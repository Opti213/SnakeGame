#include "Snake.h"
#include "cstring"

using namespace std;

int main() {
    system ("mode con cols=75 lines=25");
    system("color 02");
    Snake player;
    struct timespec tw = {1,0};
    player.spawnFood();
    cout << "here\n";
    player.startMenu();
    player.initField();


    while(!player.gameOver){
        if(_kbhit()){
            player.checkDirection(getch());
        }

        player.update();
        system("cls");
        player.drawField();
        nanosleep(&tw,NULL);
        player.score += player.size_of_snake;
    }

    for (int i = 0; i < 9; ++i){
        i % 2 == 0 ? system("color 02") : system("color 04");
        nanosleep(&tw,NULL);
    }
    system ("cls");
    system ("mode con cols=50 lines=20");
    system ("color 0D");
    cout << "                              \n"
            "              ,-.       _,---._ __  / \\\n"
            "             /  )    .-'       `./ /   \\\n"
            "            (  (   ,'            `/    /|\n"
            "             \\  `-\"             \\'\\   / |\n"
            "              `.              ,  \\ \\ /  |\n"
            "               /`.          ,'-`----Y   |\n"
            "              (            ;        |   '\n"
            "              |  ,-.    ,-'   CODE  |  /\n"
            "              |  | (   |       <3   | /\n"
            "              )  |  \\  `.___________|/\n"
            "              `--'   `--'\n\n\n GAME OVER \n Your Score is: ";
    cout << (player.size_of_snake-3)*100 << endl;

    system("pause");

    return 0;
}
