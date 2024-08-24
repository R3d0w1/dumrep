#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct point {
    float x;
    float y;            
} point;                //структура, описывающая точку с двумя координатами
float func1(float x);
float func2(float x);
float func3(float x);
int sign(float x);

float root(float (*f1)(float), float (*f2)(float), float xl, float xr, float eps, int *counter);
int pointCalc(float xl, float xr, float eps, float (*f1)(float), float (*f2)(float), point* obj);
float integral(float xl, float xr, float eps, float (*f)(float));