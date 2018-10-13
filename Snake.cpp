#include "Snake.h"


using namespace std;

Snake::Snake() {
    FIELD.resize(width);
    for (auto &tmp : FIELD){
        tmp.resize(height);
    }
}

void Snake::initField() {

    x = width / 2;
    y = height / 2;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if ((i == 0 || i == height - 1) || (j == 0 || j == width - 1)) {
                FIELD.at(i).at(j) = -1;
            } else if (i == y && j == x) {
                FIELD.at(j).at(i) = 1;
            } else if (i == food_y && j == food_x) {
                FIELD.at(j).at(i) = -2;
            } else {
                FIELD.at(j).at(i) = 0;
            }
        }
    }
}

void Snake::drawField(){
    for(int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            cout << value_to_char(FIELD.at(i).at(j));
        }
        cout << endl;
    }
}

char Snake::value_to_char(int value){
    if(value > 0) return '#';
    else if(value == 0) return ' ';
    else if(value == -1) return '+';
    else if(value == -2) return '@';
}

void Snake::spawnFood() {
    srand(time(NULL));
    food_x = 1 + rand() % (width - 2);
    food_y = 1 + rand() % (height - 2);
    FIELD.at(food_x).at(food_y) = -2;
}

void Snake::move(int dx, int dy){
    int xNew = x + dx;
    int yNew = y + dy;

    if(FIELD.at(xNew).at(yNew) == -2){
        spawnFood();
        size_of_snake++;
    }

    else if(FIELD.at(xNew).at(yNew) != 0){
        gameOver = true;
    }

    x = xNew;
    y = yNew;
    FIELD.at(x).at(y) = size_of_snake + 1;

}

void Snake::checkDirection(char pushed){

    switch(tolower(pushed)){
        case'w':
            if(direction != 's') direction = 'w';
            break;
        case'a':
            if(direction != 'd') direction = 'a';
            break;
        case's':
            if(direction != 'w') direction = 's';
            break;
        case'd':
            if(direction != 'a') direction = 'd';
            break;
    }
}

void Snake::update(){
    switch(direction){
        case 'w':
            move(-1, 0);
            break;
        case 'a':
            move(0, -1);
            break;
        case 's':
            move(1, 0);
            break;
        case 'd':
            move(0, 1);
            break;
    }

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            if(FIELD.at(i).at(j) > 0) FIELD.at(i).at(j)--;
        }
    }
}

void Snake::startMenu(){
    system ("mode con cols=75 lines=35");
    cout << "                        _____\n"
            "                    .-'`     '.\n"
            "                 __/  __       \\\n"
            "                /  \\ /  \\       |    ___\n"
            "               | /`\\| /`\\|      | .-'  /^\\/^\\\n"
            "               | \\(/| \\(/|      |/     |) |)|\n"
            "              .-\\__/ \\__/       |      \\_/\\_/__..._\n"
            "      _...---'-.                /   _              '.\n"
            "     /,      ,             \\   '|  `\\                \\\n"
            "    | ))     ))           /`|   \\    `.       /)  /) |\n"
            "    | `      `          .'       |     `-._         /\n"
            "    \\                 .'         |     ,_  `--....-'\n"
            "     `.           __.' ,         |     / /`'''`\n"
            "       `'-.____.-' /  /,         |    / /\n"
            "           `. `-.-` .'  \\        /   / |\n"
            "             `-.__.'|    \\      |   |  |-.\n"
            "                _.._|     |     /   |  |  `'.\n"
            "          .-''``    |     |     |   /  |     `-.\n"
            "       .'`         /      /     /  |   |        '.\n"
            "     /`           /      /     |   /   |\\         \\\n"
            "    /            |      |      |   |   /\\          |\n"
            "   ||            |      /      |   /     '.        |\n"
            "   |\\            \\      |      /   |       '.      /\n"
            "   \\ `.           '.    /      |    \\        '---'/\n"
            "    \\  '.           `-./        \\    '.          /\n"
            "     '.  `'.            `-._     '.__  '-._____.'--'''''--.\n"
            "       '-.  `'--._          `.__     `';----`              \\\n"
            "          `-.     `-.          `.\"'```                     ;\n"
            "             `'-..,_ `-.         `'-.                     /\n"
            "        jgs         '.  '.           '.                 .\n"
            "                            PRESS ENY KEY                    ";
    getch();
    system("cls");
}