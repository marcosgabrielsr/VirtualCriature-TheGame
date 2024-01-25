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

//====== Endereço da EEPROM ======
#define address 1

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
//- Função que determina o nome e retorna o estágio de evolução segundo o nível da criatura
uint8_t setNameAndStage(Criature &criature);

//====== Declarando variáveis ======
//- Estágios do tamagotchi
const unsigned char* stages[3] = {tokomon, 0, salandermon};
//- Variável para armazenar o estágio atual do tamagothci
uint8_t current_stage;

//====== Opções dos Menus ======
//- Menu para comidas
const char foods[3][MAX_TITLE] = {"Brownie", "Suco", "Sair"};
//- Menu para configurações
const char configs[3][MAX_TITLE] = {"BackLight", "Salvar", "Sair"};
//- Menu para jogos
const char games[3][MAX_TITLE] = {"BombDrop", "RandomMath", "Sair"};

//Criando criatura
Criature criature;

void setup(){
    //Carregando dados salvos da memória EEPROM da criatura
    loadData(address, criature);

    //Passando o endereço da EEPROM e o pino do led do display para a criatura
    criature.addressEEPROM = address;
    criature.pinBackLight = led;

    //Definindo pino do led com saída e o inicializando como desligado
    pinMode(criature.pinBackLight, OUTPUT);
    digitalWrite(criature.pinBackLight, criature.backLight);

    //Setando uma nova semente para a função random
    randomSeed(analogRead(A0));

    //Inicializando o display
    display.begin();
    display.setContrast(57);
    display.clearDisplay();
    display.display();

    //Setando o estágio atual do tamagotchi
    current_stage = setNameAndStage(criature);
}

void loop(){
    //Limpando display 
    display.clearDisplay();

    //Desenhando a criatura segundo seu estágio
    display.drawBitmap(15, 0, stages[current_stage], 68, 48, BLACK);

    //Desenhando o menu lateral
    drawSideMenu(display,  allIconsSideMenu, buttonL, buttonR, buttonX, criature);

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

    if(btnX.clickButton()){
        switch (cursor){
            case 0:
                menuStatus(display, "Status", criature, btnL, btnX, btnR);
            break;

            case 1:
                menuShow(display, criature, "Comidas", btnL, btnX, btnR, foods, 3, criatureEat);
            break;

            case 2:
                menuShow(display, criature, "Jogos", btnL, btnX, btnR, games, 3, playGame);
            break;

            case 3:
                menuShow(display, criature, "Configs", btnL, btnX, btnR, configs, 3, criatureConfig);
            break;
        }
    }
}

//- Função que determina o nome e retorna o estágio de evolução segundo o nível da criatura
uint8_t setNameAndStage(Criature &criature){
    uint8_t current_stage;
    
    if(criature.nivel < 16){
        criature.nome = "Tokomon";
        current_stage = 0;
    }

    return current_stage;
}
