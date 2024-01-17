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
#include "PushButton.hpp"

//====== Structs ======
struct Criature {
    //Dados para status da criatura
    const char* nome;
    uint8_t saude;
    uint8_t nivel;
    uint8_t humor;
    uint8_t fome;
    uint8_t energia;
    unsigned int exp;

    //Configurações do jogo
    uint8_t pinBackLight;
    bool backLight;
};

//====== Funcionalidades ======
//Função que cria o título do menu
void menuTitle(Adafruit_PCD8544 &display, char* title);

//Função que desenha no display as opções e a opção selecionada pelo usuário
void menuShow(Adafruit_PCD8544 &display, Criature &criature, char* title, PushButton &buttonL, PushButton &buttonX, PushButton &buttonR, const char options[][MAX_TITLE], const int size, bool (*func)(int8_t, Criature &, PushButton &));

//Função que desenha o menu para visualição dos status da criatura
void menuStatus(Adafruit_PCD8544 &display, char* title, Criature cratiure, PushButton &btnL, PushButton &btnX, PushButton &btnR);

//Função chamada quando uma comida é entregue à criatura
bool criatureEat(int8_t cursor, Criature &criature, PushButton &btnX);

//Função chamada quando alguma opção do menu de configurações é selecionada
bool criatureConfig(int8_t cursor, Criature &criature, PushButton &btnX);

//Função chamada quando o menu de jogos for acessado
bool playGame(int8_t cursor, Criature &criature, PushButton &btnX);

#endif // CONFIG_H