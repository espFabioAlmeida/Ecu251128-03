///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasEntradasDigitais 
//AUTOR:      Fabio Almeida
//CRIADO:     21/07/2023
//OBSERVACOES:
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
LEITURA ENTRADAS DIGITAIS
==============================================================================*/
void leituraEntradasDigitais() {
    if(flagSeguranca) {
        if(debounceInverso(IN1)) {
            flagSeguranca = false;
        }
    }
    else {
        if(debounce(IN1)) {
            flagSeguranca = true;
        }
    }

    if(flagSeguranca) {
        if(flagAcionamento) {
            if(debounceInverso(IN2)) {
                flagAcionamento = false;
            }
        }
        else {
            if(debounce(IN2)) {
                flagAcionamento = true;
            }
        }
    }

    if(flagHomeAcelerador) {
        if(debounceInverso(IN4)) {
            flagHomeAcelerador = false;
        }
    }
    else {
        if(debounce(IN4)) {
            flagHomeAcelerador = true;
        }
    }

    if(flagFimCursoAcelerador) {
        if(debounceInverso(IN5)) {
            flagFimCursoAcelerador = false;
        }
    }
    else {
        if(debounce(IN5)) {
            flagFimCursoAcelerador = true;
        }
    }
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/ 
