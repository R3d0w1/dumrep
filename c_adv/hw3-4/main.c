#include "func.h"
struct food food[MAX_FOOD_SIZE];
struct control_buttons control_buttons;
struct control_buttons default_controls[CONTROLS] = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT,
                                                    83,87,65,68,
                                                    115,119,97,100};

int main()
{
snake_t* snake = (snake_t*)malloc(sizeof(snake_t));

    initSnake(snake,START_TAIL_SIZE,10,10);
       
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0," Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна    
    int key_pressed=0;
    while( (key_pressed != STOP_GAME)&&(ifcollision(snake)))
    {
        key_pressed = getch(); // Считываем клавишу
        go(snake);
        goTail(snake);
        timeout(50); // Задержка при отрисовке
        haveEat(snake,food); 
        refreshFood(food, SEED_NUMBER);// Обновляем еду    
        changeDirection(snake, key_pressed);
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}