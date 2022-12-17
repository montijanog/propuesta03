/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
//Ejercicio propuesto:
// 5) Dos botones, al pulsar un botón que encienda un led durante 1s el segundo botón que encienda un segundo led durante 2s.
#include "mbed.h"

#define WAIT_TIME_MS 500 
// Declaro las variable de entradas (button_1  y butto_2), la  de salida  (led1) t los timer 
DigitalOut led1(D2);
DigitalIn button_1(D3);
DigitalIn button_2(D4);

Timer  timer_1; //timer button_1 ,duracion led  on 1 segundo
Timer timer_2; //timer button_2 ,duracion led  on 2 segundos

int main()
{
    
    led1=0; //Inicialmente led apagado
    


    while (true)
    {
       //Cuando apretemos button_1, encender led y timer
       if(button_1 && button_2==0){

           timer_1.start();
           led1=1;

           
        }

        //Cunado timer_1 alcance  1 segundo, que apague el led, resete ty pare el timer_1
        if(timer_1.read()>1.0f){
               
            led1=0;
            timer_1.reset();
            timer_1.stop();

        }


        //Cuando apretemos button_2, encender led y timer
       if(button_2==1 &&  button_1==0){

           timer_2.start();
           led1=1;

        }

        //Cunado timer_2 alcance  2 segundos, que apague el led, resete ty pare el timer_2
        if(timer_2.read()>2.0f){
               
            led1 = 0;
            timer_2.reset(); 
            timer_2.stop();

        }
       
        
        thread_sleep_for(WAIT_TIME_MS);
    }
}