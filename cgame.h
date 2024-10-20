#pragma once
#include "cmap.h"

class cgame {
private:
    cmap _map;
    bool _ISEXIT1, _ISEXIT2;
    bool _isPaused;
public:
    cgame();
    bool getIsExist1() { return _ISEXIT1; }
    void setIsExist1(bool b) { _ISEXIT1 = b; }
    bool getIsExist2() { return _ISEXIT2; }
    void setIsExist2(bool b) { _ISEXIT2 = b; }
    cmap& getMap() { return _map; }
    void startGame();
    void updateGame();
    void processInput(char input);
    void exitGame();
    void pauseGame();
};
