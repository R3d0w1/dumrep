#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
double DELAY = 0.1;
#define PLAYERS  2

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=10, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3,CONTROLS=2};




// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons[PLAYERS];

struct control_buttons player1_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};    
struct control_buttons player2_controls = {115,119,97,100};                                              
/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;
/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.
 */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void setColor(int snake){
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    switch (snake){
        case 0:{ // SNAKE1
            attron(COLOR_PAIR(1));
            break;
        }
        case 1:{ // SNAKE2
            attron(COLOR_PAIR(2));
            break;
        }
        case 2:{ // FOOD
            attron(COLOR_PAIR(3));
            break;
        }
    }
}


int distance(const snake_t snake, const struct food food)
{
    return (abs(snake.x - food.x) + abs(snake.y - food.y));
}
void autoChangeDirection(snake_t *snake, struct food food[], int foodSize)
{
    int pointer = 0;
    for (int i = 1; i < foodSize; i++) {   // ищем ближайшую еду
        pointer = (distance(*snake, food[i]) < distance(*snake, food[pointer])) ? i : pointer;
    }
    if ((snake->direction == RIGHT || snake->direction == LEFT) &&
        (snake->y != food[pointer].y)) {  // горизонтальное движение
        snake->direction = (food[pointer].y > snake->y) ? DOWN : UP;
    } else if ((snake->direction == DOWN || snake->direction == UP) &&
               (snake->x != food[pointer].x)) {  // вертикальное движение
        snake->direction = (food[pointer].x > snake->x) ? RIGHT : LEFT;
    }
}


void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
 Обновить/разместить текущее зерно на поле
 */
void putFoodSeed(struct food *fp)
{
    setColor(2);
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}

/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t= {0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}
//========================================================================
void initSnake(snake_t *head[], size_t size, int x, int y,int i)
{
    head[i]    = (snake_t*)malloc(sizeof(snake_t));
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail     = tail; // прикрепляем к голове хвост
    head[i]->tsize    = size+1;
    //~ head[i]->controls = default_controls[i];
        if(!i)
            head[i]->controls = player1_controls;
        else
            head[i]->controls = player2_controls;
    
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
    case LEFT:
        if(head->x <= 0) // Циклическое движение, чтобы не
            // уходить за пределы экрана
            head->x = max_x;
        mvprintw(head->y, --(head->x), "%c", ch);
        break;
    case RIGHT:
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
    if (head->x == max_x){head->x=0;}                           //Выход за границы экрана
    if (head->y == max_y){head->y=0;}
    if (head->x <0){head->x=max_x;}
    if (head->x <0){head->x=max_y;}
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

//========================================================================
//Проверка того, является ли какое-то из зерен съеденным,
_Bool haveEat(struct snake_t *head, struct food f[])
{
    for(size_t i=0; i<SEED_NUMBER; i++)
    {
        if( (f[i].x==head->x)&&(f[i].y==head->y) )
        {
            f[i].enable=0;
            return true;
        }
    }
    return false;
}

void repairSeed(struct food f[], size_t nfood, struct snake_t *head)
{
    int n = 1;
    while(n)        //Добавлен внешний цикл для проверки корректности только по обоим условиям одновременно
    {
        n=0;
         for( size_t i=0; i<head->tsize; i++ )
            for( size_t j=0; j<nfood; j++ )
                {
                    if((f[j].x == head->tail[i].x)&&( f[j].y == head->tail[i].y)&&(!(f[j].enable)))
                        n=1;
                }
        for( size_t i=0; i<nfood; i++ )
            for( size_t j=0; j<nfood; j++ )
                {
                    if ((i!=j) && (!(f[i].enable)) && (!(f[j].enable)) && (f[j].x == f[i].x) && (f[j].y == f[i].y))
                        n=1;
                }
        if(n)
            refreshFood(food, nfood);
    }

                        
}


/*
 Увеличение хвоста на 1 элемент
 */

void addTail(struct snake_t *head)
{
    head->tsize++;
}
//========================================================================
int checkDirection(snake_t* snake, int32_t key)
{
    if ((snake->direction == DOWN)&&(key == snake->controls.up))
        return 0;
    else if ((snake->direction == UP)&&(key == snake->controls.down))
        return 0;
    else if ((snake->direction == RIGHT)&&(key == snake->controls.left))
        return 0;
    else if ((snake->direction == LEFT)&&(key == snake->controls.right))
        return 0;
    else return 1;

}
_Bool isCrush(snake_t * snake)
{
    for(size_t i = snake->tsize-1; i>0; i--)
    {
       if((snake->tail[i].x == snake->x)&&(snake->tail[i].y == snake->y))
       {
            return true;
       }
    }
    return false;
}
//========================================================================

//Вынести тело цикла while из int main() в отдельную функцию update
//и посмотреть, как изменится профилирование
void update(struct snake_t *head[], struct food f[])                    //Главный цикл перенесен в update()
{
    int key = 0;
    while( key != STOP_GAME )
    {
        key = getch(); // Считываем клавишу
        for (int i = 0; i < PLAYERS; i++)
        {
            setColor(i);
            clock_t begin = clock();
            go(head[i]);
            goTail(head[i]);
            if (i)                                                       //Пусть ИИ - игрок с индексом 1
                autoChangeDirection(head[i],food,SEED_NUMBER);           //Отрабатывает автопилот
            else if (checkDirection(head[i],key))                        //Иначе отзыв на клваишу упавления
                changeDirection(head[i], key);
            refreshFood(food, SEED_NUMBER);// Обновляем еду
            if (haveEat(head[i],food))
            {
                addTail(head[i]);
                DELAY -= 0.009;
            }
            if(isCrush(head[i]))
                return;
            repairSeed(food, SEED_NUMBER, head[i]);
            refresh();//Обновление экрана, вывели кадр анимации
            while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
            {}
        }
    }

}
//========================================================================





int main()
{
    
//========================================================================   
snake_t* snakes[PLAYERS];
    for (int i = 0; i < PLAYERS; i++)
        initSnake(snakes,START_TAIL_SIZE,2+i*2,2+i*2,i);
//========================================================================

    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);

    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    /*while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        for (int i = 0; i < PLAYERS; i++)
        {
            update(snakes[i], food, key_pressed);
            if(isCrush(snakes[i]))
                break;//!!!!!!
            repairSeed(food, SEED_NUMBER, snakes[i]);
        }
    }*/
    update(snakes,food);
    for (int i = 0; i < PLAYERS; i++)
    {
        //printExit(snakes[i]);
        free(snakes[i]->tail);
        free(snakes[i]);
    }
    endwin(); // Завершаем режим curses mod
    return 0;
}