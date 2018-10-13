#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H
#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>

using namespace std;

class Snake {
private:

public:
    const int width = 20;
    const int height = 20;
    vector<vector<int>> FIELD;
    int size_of_snake{3}, x {1}, y{1}, food_x{2}, food_y{2}, score{0};
    char direction;
    bool gameOver = false;
    void initField();
    void drawField();
    char value_to_char(int);
    void spawnFood();
    void move(int, int);
    void checkDirection(char);
    void update();
    void startMenu();
    Snake();
};


#endif //SNAKEGAME_SNAKE_H
