//Incluindo biblioteca com as configurações do projeto
#include "config.h"

//Função que desenha o menu para visualição dos status da criatura
void menuStatus(Adafruit_PCD8544 &display, PushButton &btnX, char* title){
    while(!btnX.clickButton()){
        display.clearDisplay();

        menuTitle(display, title);

        display.display();
    }
}