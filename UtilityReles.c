///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityReles
//AUTOR:      Fabio Almeida
//CRIADO:     21/07/2023
//OBSERVAÇÕES: 
//////////////////////////////////////////////////////////////////////////////// 
/*==============================================================================
ACIONAMENTO MOTOR
==============================================================================*/
void acionamentoMotor(unsigned int motor) {

    switch(motor) {
        case MOTOR_DESLIGA:
            off(MOTOR_H);
            off(MOTOR_AH);
            break;
        
        case MOTOR_AVANCA:           
            off(MOTOR_AH);
            on(MOTOR_H);
            break;

        case MOTOR_RECUA:   
            off(MOTOR_H);        
            on(MOTOR_AH); 
            break;
    }

}
/*==============================================================================
MOTOR EM HOME
==============================================================================*/
void motorEmHome() {
    if(flagHomeAcelerador) {
        acionamentoMotor(MOTOR_DESLIGA);
    }
    else {
        acionamentoMotor(MOTOR_RECUA);
    }
}
/*==============================================================================
ACIONAMENTO RELES
==============================================================================*/
void acionamentoReles() {
    static boolean reentrada = true;
    if(flagOperacao) {
        on(LED_ON);
        reentrada = true;
        
        switch(operacao) {
            case OPERACAO_RL1: 
                on(RELE1);
                if(contadorEntreReles >= CONTADOR_ENTRE_RELES) {
                    contadorEntreReles = 0;
                    contadorRele2 = 1;
                    operacao = OPERACAO_RL2;
                }
                motorEmHome();
                break;

            case OPERACAO_RL2:
                on(RELE2);
                if(contadorRele2 >= CONTADOR_RELE2) {
                    off(RELE2);
                    contadorRele2 = 0;
                    contadorAquecimento = 1;
                    operacao = OPERACAO_AQUECIMENTO;
                }
                motorEmHome();
                break;

            case OPERACAO_AQUECIMENTO:
                motorEmHome();
                if(contadorAquecimento >= CONTADOR_AQUECIMENTO) {
                    contadorAquecimento = 0;
                    operacao = OPERACAO_ACELERADOR;
                }
                break;

            case OPERACAO_ACELERADOR:
                if(flagFimCursoAcelerador) {
                    acionamentoMotor(MOTOR_DESLIGA);
                }
                else {
                    acionamentoMotor(MOTOR_AVANCA);
                }
                break;

            case OPERACAO_DESAQUECIMENTO:
                motorEmHome();
                if(contadorDesaquecimento >= CONTADOR_DESAQUECIMENTO) {
                    contadorDesaquecimento = 0;
                    flagOperacao = false;
                }

                if(flagAcionamento) {
                    contadorDesaquecimento = 0;
                    operacao = OPERACAO_ACELERADOR;
                }

                break;
        }

        if(!flagSeguranca) {
            flagOperacao = false;
        }

        if(!flagAcionamento) {
            if(operacao == OPERACAO_AQUECIMENTO || operacao == OPERACAO_ACELERADOR) {
                operacao = OPERACAO_DESAQUECIMENTO;
                contadorDesaquecimento = 1;
            }           
        }

        return;
    }

    off(RELE1);
    off(RELE2);
    off(LED_ON);

    motorEmHome();

    if(reentrada) {
        if(!flagAcionamento) {
            reentrada = false;
        }
        return;
    }

    if(flagSeguranca && flagAcionamento) {
        flagOperacao = true;
        operacao = OPERACAO_RL1;
        contadorEntreReles = 1;
        contadorRele2 = 0;
    }
}
/*==============================================================================
FIM DO ARQUIVO   
==============================================================================*/
