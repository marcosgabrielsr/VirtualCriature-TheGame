//Funções para criação e usabilidade do menu
#include "config.h"

//Função que cria o título do menu
void menuTitle(Adafruit_PCD8544 &display, char* title){
    //Desenhando retângulo
    display.drawRect(0, 0, 84, 11, BLACK);

    //Configurando texto para imprimir o título
    display.setCursor(10, 2);
    display.setTextColor(BLACK);
    display.setTextSize(1);

    //Escrevendo título
    display.println(title);
}

//Função que faz a navegação pelas opções do menu, retornando o índice de controle do usuário
int8_t navegation(PushButton &buttonL, PushButton &buttonR, const int8_t size, int8_t cursor){
    //Posição atual do cursor
    int8_t c = cursor;

    //Verifica se a posição está no intervalo [0, quant_itens - 1) e se o buttonR foi cliclado
    if(cursor < (size - 1) && buttonR.clickButton())
        c++;
    
    //Se não, verifica se a posição está no intervalo (0, quant_itens - 1] e se o buttonL foi cliclado
    else if(cursor > 0 && buttonL.clickButton())
        c--;

    //retorna a posição atual do cursor
    return c;
}

//Função que desenha no display as opções e a opção selecionada pelo usuário
void menuShow(Adafruit_PCD8544 &display, Criature &criature, char* title, PushButton &buttonL, PushButton &buttonX, PushButton &buttonR, const char options[][MAX_TITLE], const int size, bool (*func)(int8_t, Criature &, PushButton &)){
    int8_t begin = 0, end = 0, cursor = 0; // Variáveis que guardam o primeiro item a aparecer, último item e opção atual do cursor do usuário
    bool rigth = true;

    Serial.println(cursor);

    //laço infinito que é executando enquanto o usuário não querer sair
    while(rigth){
        //Limpando o display
        display.clearDisplay();

        //Imprimindo título
        menuTitle(display, title);

        //Configurando display para escrever os itens do menu
        display.setCursor(0, 13);

        //Atualizando cursor, begin e end
        cursor = navegation(buttonL, buttonR, size, cursor); //opção atual do cursor
        begin = int(cursor / 4) * 4; // Indíce da primeira opção a ser apresentada no display
        end = begin + 3; // Indíce da última opção a ser apresentada no display

        for(int i = begin; (i < end + 1) && (i < size); i++){
            //Verifica se o índice do cursor é igual ao índice da opção a ser impressa
            if(cursor == i){
                //Caso seja, imprime "->" antes do nome do nome da opção
                display.print("->"); display.println(options[i]);
            }
            else{
                //Caso contrário,  imprime ">" antes do nome do nome da opção
                display.print(">"); display.println(options[i]);
            }
        }

        rigth = func(cursor, criature, buttonX);

        //Atualizando o display
        display.display();
    }
}