//Incluindo biblioteca com as configurações do projeto
#include "config.h"

//Função chamada quando uma comida é entregue à criatura
bool criatureEat(int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
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
bool criatureConfig(int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    if(btnX.clickButton()){
        switch(cursor){
            case 0:
                criature.backLight = !criature.backLight;
                digitalWrite(criature.pinBackLight, criature.backLight);
            break;
        
            case 1:
                return false;
            break;
        }
    }

    return true;
}

//Função chamada quando o menu de jogos for acessado
bool playGame(int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    if(btnX.clickButton()){
        switch (cursor){
            case 0:
                Serial.println("BombDrop");
            break;

            case 1:
                Serial.println("RandomMath");
            break;

            case 2:
                return false;
            break;
        }
    }

    return true;
}