//Incluindo biblioteca com as configurações do projeto
#include "config.h"

//Função que desenha o menu para visualição dos status da criatura
void menuStatus(Adafruit_PCD8544 &display, char* title, Criature criature, PushButton &btnL, PushButton &btnX, PushButton &btnR){
    int8_t cursor = 0;

    while(!btnX.clickButton()){
        display.clearDisplay();

        //Imprimindo título do menu
        menuTitle(display, title);
        display.setCursor(0, 12);

        //Verifica se o btnL foi clicado para voltar à tela anterior
        if(btnL.clickButton())
            cursor = 0;
        //Verifica se o btnR foi clicado para ir para a próxima tela
        if(btnR.clickButton())
            cursor = 1;

        //Verifica o valor do cursor
        switch(cursor){
            //Caso seja 0 imprime a primeira tela
            case 0:
                display.print("Nome:"); display.println(criature.nome);
                display.print("Nivel:"); display.println(int(criature.nivel));
                display.print("Exp:"); display.print(criature.exp); display.print("/"); display.println(10 * criature.nivel);
            break;

            //Caso seja 1 imprime a segunda tela
            case 1:
                display.print("Comida:"); display.print(criature.comida); display.println("%");
                display.print("Humor:"); display.print(criature.humor); display.println("%");
                display.print("Energia:"); display.print(criature.energia); display.println("%");
            break;
        }

        updateStatus(criature);

        display.display();
    }
}