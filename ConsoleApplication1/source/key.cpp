#include <iostream>
#include <conio.h>

#include "key.h"

int KeyUp(int& maxIndex, int& nowIndex) {
    if (nowIndex > 1) return nowIndex -= 1;
}
int KeyDown(int& maxIndex, int& nowIndex) {
    if (nowIndex < maxIndex) return nowIndex += 1;
}
int KeyReturn(int& maxIndex, int& nowIndex, bool& isRunning) {
    isRunning = false;
    return nowIndex;
}

int EventHandler(char& key, int& maxIndex, int& nowIndex, bool& isRunning) {
    if (key == UP_KEY) return KeyUp(maxIndex, nowIndex);
    else if (key == DOWN_KEY) return KeyDown(maxIndex, nowIndex);
    else if (key == RETURN_KEY) return KeyReturn(maxIndex, nowIndex, isRunning);
}
int KeyWait(int& maxIndex, int& nowIndex, bool& isRunning) {
    char key = 0;
    while (true) {
        if (_kbhit()) {
            key = _getch();
            break;  
        }
    }
    return EventHandler(key, maxIndex, nowIndex, isRunning);
}