#pragma once
#include "OutputManager.h"
#include "InputManager.h"

enum class State {
  LOADING,
  ENTERING_NAME,
  MENU,
  SETTINGS,
  RECORDS,
  IN_GAME,
  GAME_OVER
};

class GameManager {
private:
  void dealKeyboard(TSPoint p);
  void dealMenuButtons(TSPoint p);
  void dealSettingsButtons(TSPoint p);
  
public:
  GameManager(OutputManager& OM, InputManager& IM) :output(OM), input(IM) {

  };          //конструктор

  void load();            //заставка игры
  void enterName();       //переходит в ввод имени
  void openMenu();        //переходит в меню
  void startGame();       //начинает новую игру
  void openSettings();    //открывает настройки
  void openRecords();     //открывает топ игроков
  void gameOver();        //заканчиывает игру

  void update();          //считывает нажатие и изменяет состояние игры

  State getState() {
    return curState;
  }
private:
  OutputManager& output;
  InputManager& input;

  MyString name;
  State curState;
};
