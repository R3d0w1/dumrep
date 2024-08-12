#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#define CONTROLS 3
#define MIN_Y  2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=7, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3};
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
};

extern struct control_buttons default_controls[CONTROLS];

typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons *controls;
} snake_t;

typedef struct tail_t
{
    int x;
    int y;
} tail_t;

struct food {
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
};
void initFood(struct food f[], size_t size);
void putFoodSeed(struct food *fp);
void putFood(struct food f[], size_t number_seeds);
void refreshFood(struct food f[], int nfood);
void addTail(struct snake_t* snake);
void haveEat(struct snake_t *head, struct food f[]);
void initTail(struct tail_t t[], size_t size);
void initHead(struct snake_t *head, int x, int y);
void initSnake(snake_t *head, size_t size, int x, int y);
void go(struct snake_t *head);
int checkDirection(snake_t* snake, int32_t key);
void changeDirection(struct snake_t* snake, const int32_t key);
void goTail(struct snake_t *head);
int ifcollision(struct snake_t *head);