//Incluindo biblioteca com as configurações do projeto
#include "config.h"
#include "sprites.h"

//====== Mapeando Hardware ======
//- Pinos do display:
#define pinCLK 3
#define pinDIN 4
#define pinDC 5
#define pinCE 6
#define pinRST 7
#define led 2

//- Pinos dos botões
#define pinButtonL 10
#define pinButtonX 9
#define pinButtonR 8

//====== Criando objetos ======
//- Display Nokia 5110:
Adafruit_PCD8544 display = Adafruit_PCD8544(pinCLK, pinDIN, pinDC, pinCE, pinRST);

//- PushButtons:
PushButton buttonL(pinButtonL, 170);
PushButton buttonX(pinButtonX, 170);
PushButton buttonR(pinButtonR, 170);

//====== Declarando Funções ======
//- Função para navegação e impressão do menu lateral no display
void drawSideMenu(Adafruit_PCD8544 &display, const unsigned char* sprite[], PushButton &buttonL, PushButton &buttonR, PushButton &ButtonX, Criature &criature);
//- Função que desenha a criatura virtual segundo seu stágio de evolução
void drawCriature(Adafruit_PCD8544 &display, Criature &criature,const unsigned char* stages[]);

//Declarando variáveis
const unsigned char* stages[3] = {stage_1, 0,stage_3};

//====== Opções dos Menus ======
//- Menu para comidas
const char foods[3][MAX_TITLE] = {"Brownie", "Suco", "Sair"};
//- Menu para configurações
const char configs[2][MAX_TITLE] = {"BackLight", "Sair"};
//- Menu para jogos
const char games[3][MAX_TITLE] = {"BombDrop", "RandomMath", "Sair"};

//Criando criatura
Criature criature;

void setup(){
    //Inicializando comunicação serial
    Serial.begin(9600);

    //Definindo pino do led com saída e o inicializando como desligado
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);

    //Inicializando o display
    display.begin();
    display.setContrast(57);
    display.clearDisplay();
    display.display();

    criature.nivel = 1;
    criature.saude = 20;
    criature.pinBackLight = led;
}

void loop(){
    //Limpando display 
    display.clearDisplay();

    drawSideMenu(display,  allIconsSideMenu, buttonL, buttonR, buttonX, criature);

    drawCriature(display, criature, stages);

    //Atualizando display
    display.display();
}

//- Função para navegação e impressão do menu lateral no display
void drawSideMenu(Adafruit_PCD8544 &display, const unsigned char* sprite[], PushButton &btnL, PushButton &btnR, PushButton &btnX, Criature &criature){
    //Variável para armazenar o cursor
    static uint8_t cursor = 0;

    //Código para navegação do menu lateral
    if(buttonL.clickButton() && cursor > 0)
        cursor -= 1;
    
    if(buttonR.clickButton() && cursor < 3)
        cursor += 1;

    if(cursor == 0 && criature.saude < 25)
        display.drawBitmap(0, 0, stats_icon_atention, 15, 48, BLACK);
    else
        //Imprimindo o sprite do menu lateral no display
        display.drawBitmap(0, 0, sprite[cursor], 15, 48, BLACK);

    if(buttonX.clickButton()){
        switch (cursor){
            case 0:
                menuStatus(display, btnX, "Status");
            break;

            case 1:
                menuShow(display, criature, "Comidas", btnL, btnX, btnR, foods, 3, criatureEat);
            break;

            case 2:
                menuShow(display, criature, "Jogos", btnL, btnX, btnR, games, 3, playGame);
            break;

            case 3:
                menuShow(display, criature, "Configs", btnL, btnX, btnR, configs, 2, criatureConfig);
            break;
        }
    }
}

//- Função que desenha a criatura virtual segundo seu stágio de evolução
void drawCriature(Adafruit_PCD8544 &display, Criature &criature,const unsigned char* stages[]){
    if (criature.nivel < 16)
        display.drawBitmap(15, 0, chinchomon_sprite, 68, 48, BLACK);
    
    else if (criature.nivel < 36)
        display.drawBitmap(15, 0, stages[1], 68, 48, BLACK);
    
    else
        display.drawBitmap(0, 0, stages[2], 84, 48, BLACK);
}
