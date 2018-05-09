#include <iostream>
#include <conio.h>
#include <time.h>

const int HEIGHT {10}, WIDTH {10};
char map[HEIGHT][WIDTH];

using namespace std;

class Snake{
private:
    int x{WIDTH/2}, y{HEIGHT/2},  snakeSize{3}, score{0}, food_x, food_y;
    bool GameOver = false;
public:

    void initMap(){
        for (int i {0}; i <= HEIGHT; ++i){
            for(int j {0}; j <= WIDTH; ++j){
                if ((i == 0 || i == HEIGHT) || (j == 0 || j == WIDTH)){
                    map[j][i] = '+';
                } else if (i == y && j == x){
                    map[j][i] = '#';
                } else if (i == food_y && j == food_x){
                    map[j][i] = '@';
                } else {
                    map[j][i] = ' ';
                }
            }
        }
    }

    void drawMap(){
            for (int i {0}; i <= HEIGHT; ++i) {
                for (int j{0}; j <= WIDTH; ++j) {
                    cout << map[j][i];
                }
                cout << endl;
            }
    };

    void spawnFood(){
        srand(time(NULL));
        food_x = 1 + rand() % (WIDTH - 1);
        food_y = 1 + rand() % (HEIGHT - 1);
    }

    void move(int moving_x, int moving_y){
        int xNew = x + moving_x;
        int yNew = y + moving_y;

        if(map[xNew][yNew] == '@'){
            snakeSize++;
            spawnFood();
        }

        else if(map[xNew][yNew] = '+'){
            GameOver = true;
        }

        x = xNew;
        y = yNew;
        map[x][y] = snakeSize++;

    }
    void moveSnake(){
        switch (tolower(getch())){
            case 'w':
                move(-1,0);
                break;
            case 'a':
                move(0,-1);
                break;
            case 's':
                move(1,0);
                break;
            case 'd':
                move(0,1);
                break;
        }
        for(int i {0}; i < WIDTH; i++){
            for(int j {0}; j < HEIGHT; j++){
                if(map[i][j]  == '#') map[i][j]--;
            }
        }
    }
};

int main(){
    Snake player;
    player.spawnFood();
    player.initMap();
    player.drawMap();
    return 0;
};