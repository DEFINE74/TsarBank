#ifndef H_KEY
#define H_KEY

#define UP_KEY 72
#define DOWN_KEY 80
#define RETURN_KEY 13


int KeyUp(int& maxIndex, int& nowIndex);
int KeyDown(int& maxIndex, int& nowIndex);
int KeyReturn(int& maxIndex, int& nowIndex, bool& isRunning);
int EventHandler(char& key, int& maxIndex, int& nowIndex, bool& isRunning);
int KeyWait(int& maxIndex, int& nowIndex, bool& isRunning);

#endif