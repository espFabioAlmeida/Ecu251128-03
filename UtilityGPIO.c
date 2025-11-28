///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityGPIO  
//AUTOR:      Fabio Almeida
//CRIADO:     11/06/2020
//OBSERVAÇÕES:   
////////////////////////////////////////////////////////////////////////////////
/*==============================================================================
DEBOUNCE
==============================================================================*/ 
boolean debounce(unsigned int16 pino) {
    #ifndef TEMPO_DEBOUNCE
        #define TEMPO_DEBOUNCE 120
    #endif
    
    if(!input(pino)) {
        delay_ms(TEMPO_DEBOUNCE);
        if(!input(pino)) {
            return true;
        }
    }

    return false;
}
/*==============================================================================
DEBOUNCE
==============================================================================*/ 
boolean debounceInverso(unsigned int16 pino) {
    #ifndef TEMPO_DEBOUNCE
        #define TEMPO_DEBOUNCE 120
    #endif
    
    if(input(pino)) {
        delay_ms(TEMPO_DEBOUNCE);
        if(input(pino)) {
            return true;
        }
    }

    return false;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/ 