//Incluindo biblioteca com as configurações do projeto
#include "config.h"

//Função chamada quando uma comida é entregue à criatura
bool criatureEat(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    if(btnX.clickButton()){
        switch (cursor){
            case 0:
                criature.fome += 5;
            break;
            
            case 1:
                criature.fome += 6;
            break;

            case 2:
                return false;
            break;
        }
    }

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
        criature.fome = 50;
        criature.energia = 70;
        criature.humor = 40;
        criature.saude = 100;
    }
}

//Função para decrementação dos status da criatura
void decrementation(Criature &criature){
    //Variáveis para controle e verificação de intervalos de tempo
    static unsigned long timer1 = 0;

    //Verificando se a criatura está dormindo
    if(criature.dormindo && ((timer1 - millis()) > 120000))
        criature.energia += 10;
}