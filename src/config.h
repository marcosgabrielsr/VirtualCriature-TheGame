// No início do arquivo src/config.h
#ifndef CONFIG_H
#define CONFIG_H

//Definindo constantes
#define MAX_TITLE 20

//Arquivo de Cabeçalho que contém as principais funcionalidades e tipos de dados
//====== Incluindo Bibliotecas ======
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <EEPROM.h>
#include "PushButton.hpp"

//====== Structs ======
struct Criature {
    //Dados para status da criatura
    const char* nome;
    bool dormindo;
    uint8_t saude;
    uint8_t nivel;
    uint8_t humor;
    uint8_t comida;
    uint8_t energia;
    unsigned int exp;

    //Configurações do jogo
    uint8_t addressEEPROM;
    uint8_t pinBackLight;
    bool backLight;
};

//====== Funcionalidades ======
//Função que cria o título do menu
void menuTitle(Adafruit_PCD8544 &display, char* title);

//Função que desenha no display as opções e a opção selecionada pelo usuário
void menuShow(Adafruit_PCD8544 &display, Criature &criature, char* title, PushButton &buttonL, PushButton &buttonX, PushButton &buttonR, const char options[][MAX_TITLE], const int size, bool (*func)(Adafruit_PCD8544 &, int8_t, Criature &, PushButton &, PushButton &, PushButton &));

//Função que desenha o menu para visualição dos status da criatura
void menuStatus(Adafruit_PCD8544 &display, char* title, Criature cratiure, PushButton &btnL, PushButton &btnX, PushButton &btnR);

//Função que carrega os dados da memória EEPROM do arduino para uma struct
void loadData(uint8_t address, Criature &criature);

//Função para atualizar os status da criatura
void updateStatus(Criature &criature);

//Função chamada quando uma comida é entregue à criatura
bool criatureEat(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR);

//Função chamada quando alguma opção do menu de configurações é selecionada
bool criatureConfig(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR);

//Função chamada quando o menu de jogos for acessado
bool playGame(Adafruit_PCD8544 &display, int8_t cursor, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR);

//Função principal que executa o jogo BombDrop
void gameBbD(Adafruit_PCD8544 &display, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR);

//Função responsável por desenhar a tela inicial do jogo
void gameRM(Adafruit_PCD8544 &display, Criature &criature, PushButton &btnL, PushButton &btnX, PushButton &btnR);

#endif // CONFIG_H