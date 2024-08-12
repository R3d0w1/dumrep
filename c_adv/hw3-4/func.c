#include "func.h"

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
void putFoodSeed(struct food *fp)
{
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
void addTail(struct snake_t* snake)
{
    snake->tsize++;
}
void haveEat(struct snake_t *head, struct food f[])
{
    for(size_t i=0; i<SEED_NUMBER; i++)
    {
        if( (f[i].x==head->x)&&(f[i].y==head->y) )
        {
            f[i].enable=0;
            addTail(head);
        }
    }
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
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

void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls;
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
    if (head->x == max_x){head->x=0;}
    if (head->y == max_y){head->y=0;}
    if (head->x <0){head->x=max_x;}
    if (head->x <0){head->x=max_y;}
    refresh();
}
int checkDirection(snake_t* snake, int32_t key)
{
    if (snake->direction == DOWN)
        return 1;
    else if (snake->direction == UP)
        return 2;
    else if (snake->direction == RIGHT)
        return 3;
    else if (snake->direction == LEFT)
        return 4;
        else return 0;
}   
void changeDirection(struct snake_t* snake, const int32_t key)
{
    for (int i = 0; i < CONTROLS; i++)
    {
        int dir = checkDirection(snake,key);
        if ((key == snake->controls[i].down)&&(dir!=2))
            snake->direction = DOWN;
        else if ((key == snake->controls[i].up)&&(dir!=1))
            snake->direction = UP;
        else if ((key == snake->controls[i].right)&&(dir!=4))
            snake->direction = RIGHT;
        else if ((key == snake->controls[i].left)&&(dir!=3))
            snake->direction = LEFT;
    }
    
}
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
int ifcollision(struct snake_t *head)
{
    for(size_t i = head->tsize-1; i>0; i--)
    {
       if((head->tail[i].x == head->x)&&(head->tail[i].y == head->y))
       {
            getchar();
            return 0;
       }
    }
    return 1;
}
