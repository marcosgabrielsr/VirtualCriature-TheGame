//Incluindo biblioteca com as configurações do projeto
#include "config.h"

//Função chamada quando uma comida é entregue à criatura
bool criatureEat(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    if(criature.comida < 100){
        if(btnX.clickButton()){
            switch (cursor){
                case 0:
                    criature.comida += 6;
                break;
                
                case 1:
                    criature.comida += 6;
                break;

                case 2:
                    return false;
                break;
            }
        }
    
    } else
        criature.comida = 100;

    return true;
}

//Função chamada quando alguma opção do menu de configurações é selecionada
bool criatureConfig(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    if(btnX.clickButton()){
        switch(cursor){
            case 0:
                criature.backLight = !criature.backLight;
                digitalWrite(criature.pinBackLight, criature.backLight);
            break;

            case 1:

            break;

            case 2:
                return false;
            break;
        }
    }

    return true;
}

//Função chamada quando o menu de jogos for acessado
bool playGame(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    if(btnX.clickButton()){
        switch (cursor){
            case 0:
                gameBbD(display, criature, btnL, btnX, btnR);
            break;

            case 1:
                gameRM(display, criature, btnL, btnX, btnR);
            break;

            case 2:
                return false;
            break;
        }
    }

    return true;
}

//Função que carrega os dados da memória EEPROM do arduino para uma struct
void loadData(uint8_t address, Criature &criature){
    EEPROM.get(address, criature);

    if(criature.nivel == 0){
        //Inicializa a criatura estando acordada
        criature.dormindo = false;

        //Setando configurações iniciais
        criature.nivel = 1;
        criature.comida = 50;
        criature.energia = 70;
        criature.humor = 40;
        criature.saude = 100;
    }
}

//Função para atualizar os status da criatura
void updateStatus(Criature &criature){
    //Variáveis para controle e verificação de intervalos de tempo
    static unsigned long timer1 = 0;                //Timer utilizado para dormir
    static unsigned long timer2 = 0;                //Timer utilizado para decrementar humor
    static unsigned long timer3 = 0;                //Timer utilizado para decrementar comida

    //Verificando se a criatura está dormindo
    if(criature.dormindo){
        //Verifica se passou 12s para incrementar a energia
        if(((millis() - timer1) > 12000) && criature.energia < 100){
            criature.energia += 1;
            timer1 = millis();                      //Reinicia o timer1
        }

        //Verifica se passou 654s para decrementar o humor
        if((millis() - timer2) > 654000){
            criature.humor -= 1;
            timer2 = millis();                      //Reinicia o timer2
        }

        //Verifica se passou 80s para decrementar a taxa de comida
        if(((millis() - timer3) > 80000) && criature.comida > 0){
            criature.comida -= 1;
            timer3 = millis();
        }
    }
    //Caso contrário
    else{
        //Verifica se passou 426s para decrementar o humor
        if((millis() - timer2) > 426000){
            criature.humor -= 1;
            timer2 = millis();                      //Reinicia o timer2
        }

        //Verifica se passou 60s para decrementar a taxa de comida
        if(((millis() - timer3) > 60000) && criature.comida > 0){
            criature.comida -= 1;
            timer3 = millis();
        }
    }
}