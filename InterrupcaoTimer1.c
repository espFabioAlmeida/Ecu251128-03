///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    InterrupcaoTimer1 
//AUTOR:      Fabio Almeida
//CRIADO:     17/04/2019
//OBSERVACOES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
TAREFAS 1MS
==============================================================================*/
void tarefas1ms() {

}
/*==============================================================================
TAREFAS 10MS
==============================================================================*/
void tarefas10ms() {

}
/*==============================================================================
TAREFAS 100MS
==============================================================================*/
void tarefas100ms() {
    if(contadorEntreReles) {
        if(contadorEntreReles < CONTADOR_ENTRE_RELES) {
            contadorEntreReles ++;
        }        
    }

    if(contadorRele2) {
        if(contadorRele2 < CONTADOR_RELE2) {
            contadorRele2 ++;
        }        
    }

    if(contadorAquecimento) {
        if(contadorAquecimento < CONTADOR_AQUECIMENTO) {
            contadorAquecimento ++;
        }
    }

    if(contadorDesaquecimento) {
        if(contadorDesaquecimento < CONTADOR_DESAQUECIMENTO) {
            contadorDesaquecimento ++;
        }
    }
}
/*==============================================================================
TAREFAS 1S
==============================================================================*/
void tarefas1s() {
    toggle(LED_CPU);
}
/*==============================================================================
INTERRUPCAO TIMER1
==============================================================================*/
#INT_TIMER1                                     
void timer1_() {
    static int conta10ms = 0, conta100ms = 0,conta1s = 0; 
    set_timer1(64558 + get_timer1());// carrega timer1  

    tarefas1ms();  
    conta10ms ++;

    if(conta10ms >= 10) {
        conta10ms = 0;
        tarefas10ms();
        conta100ms ++;
        
        if(conta100ms >= 10) {
            conta100ms = 0;
            tarefas100ms();
            conta1s++;
        
            if(conta1s >= 10) {
                conta1s = 0;
                tarefas1s();
            }
        }
    } 
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/ 
