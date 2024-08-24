#include "func.h"



float func1(float x)    //функции по условию задачи
{
    return 0.6*x+3;
}
float func2(float x)
{
    x-=2;
    return x*x*x-1;
}
float func3(float x)
{
    return (3/x);
}
int sign(float x)   //проверка знака
{
    if (x<0)
        return 0;
    else
        return 1;
}

float root(float (*f1)(float), float (*f2)(float), float xl, float xr, float eps, int *counter)
{
    float xm;
    while (fabs(xl-xr)>eps)
    {
        *counter += 1;                  
        xm=(xl+xr)/2;                                  //расчет методом деления отрезка пополам
        if(f1(xr)-f2(xr)==0)                           //число итераций передается через указатель в счетчик
            return xr;
        if(f1(xl)-f2(xl)==0)
            return xl;
        if(sign(f1(xl)-f2(xl)) != sign(f1(xm)-f2(xm)))
            xr=xm;
        else
            xl=xm;
    }
    return (xl+xr)/2;
}
int pointCalc(float xl, float xr, float eps, float (*f1)(float), float (*f2)(float), point* obj)
{
    int counter;                                        //расчет ординат точек пересечения       
    float x,y;                                          //с передачей по указателю в структуру,
    x = root(f1,f2,xl,xr,eps,&counter);            //описывающую точку (необязательная часть)
    y = (f1(x) + f2(x))/2;
    obj->x=x;
    obj->y=y;
    return counter;
}

float integral(float xl, float xr, float eps, float (*f)(float))
{
    float sum = 0;
    for(float x=xl+eps; x<xr-eps; x+=eps)               //расчет интеграла методом трапеций
    {
        sum += 0.5*eps*(f(x)+f(x+eps));
    }
    return sum;
}
/*
void face(int argc, char * argv[])
{

}*/