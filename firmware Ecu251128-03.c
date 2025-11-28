////////////////////////////////////////////////////////////////////////////////
//PROJETO:   Ecu251128-03                                                                                                                
//CLIENTE:   AUTOMASENSOR                                                                                                               
//CONTATO:   RICARDO KADOTA                                                                                               
//TELEFONE:                                                                                                                 
////////////////////////////////////////////////////////////////////////////////              
//AUTOR:    FABIO EDUARDO DE ALMEIDA              
//TELEFONE: 47 98411-2998                                                                                
//E-MAIL:   teg.fabio.almeida@gmail.com               
////////////////////////////////////////////////////////////////////////////////
//COMPILADOR: CCS 5.028                                                                                        
////////////////////////////////////////////////////////////////////////////////   
//VERSAO: V1 - 28/11/2025
//DESCRITIVO DO FUNCIONAMENTO:  
//Versao Inicial 
////////////////////////////////////////////////////////////////////////////////
#include <18F4620.h>                  
#device adc = 10  
#define VERSAO_FIRMWARE 1                                                          
/*==============================================================================
CONFIGURAÇÕES
==============================================================================*/
#fuses INTRC, NOWDT, PUT, PROTECT, BROWNOUT, NOLVP, NOCPD, NOWRT 
#use delay(clock = 32000000)
//#use rs232(baud=9600, parity=N, xmit=PIN_C6, rcv=PIN_C7, enable=PIN_C5, bits=8, ERRORS)
#priority TIMER1         
/*==============================================================================
CONSTANTES                         
==============================================================================*/
#define on      output_high
#define off     output_low  
#ifndef boolean
    #define boolean int1
#endif  

#define CONTADOR_ENTRE_RELES 50
#define CONTADOR_RELE2 30

enum LISTA_OPERACAO{
    OPERACAO_STANDBY,
    OPERACAO_RL1,
    OPERACAO_RL2,
    OPERACAO_AGUARDA_RL2,
    OPERACAO_ACELERADOR
};
/*==============================================================================
DEFINIÇÕES DOS PINOS                                       
==============================================================================*/
#define MOTOR_H         PIN_B5 
#define MOTOR_AH        PIN_B7 
#define RELE1           PIN_B3        
#define RELE2           PIN_B4

#define IN1             PIN_D0
#define IN2             PIN_D1
#define IN3             PIN_D2
#define IN4             PIN_D3
#define IN5             PIN_C4

#define LED_CPU         PIN_C3
#define LED_COM         PIN_D7
/*==============================================================================
VARIAVEIS
==============================================================================*/   
boolean
    flagSeguranca = false,
    flagAcionamento = false,
    flagFimCursoAcelerador = false,
    flagHomeAcelerador = false,

    flagOperacao = false;


unsigned int
    operacao = OPERACAO_STANDBY,

    contadorEntreReles = 0,
    contadorRele2 = 0;
/*==============================================================================
VARIAVEIS ARRAY
==============================================================================*/

/*==============================================================================
ARQUIVOS ANEXOS
==============================================================================*/
#include <UtilityGPIO.c>
#include <UtilityReles.c>
#include <SubrotinasEntradasDigitais.c>
#include <InterrupcaoTimer1.c>
/*==============================================================================
MAIN                                           
==============================================================================*/
void main() {                              
    setup_oscillator(OSC_32MHZ); 
    setup_adc_ports(NO_ANALOGS); 
    setup_adc(ADC_OFF); 
    delay_us(100);
        
    setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);        
    setup_timer_2(T2_DISABLED, 0, 1);                                                                   
                                    
    enable_interrupts(GLOBAL); 
    enable_interrupts(INT_TIMER1); 
/*==============================================================================
WHILE TRUE
==============================================================================*/  
    while(true) {      

    }
}
/*==============================================================================
FIM DO ARQUIVO                                                                       
==============================================================================*/
