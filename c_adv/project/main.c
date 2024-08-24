#include "func.h"
#define EPS1 0.000001       //Заданная точность вычисления абсцисс точек пересечения графиков
#define EPS2 0.000001       //Точность вычисления интеграла (длина шага по оси X)
char invalid_arg_num_msg[] = "Invalid number of arguments, use -h for more information";
char Help_message[] = "Supported options are:\n'--points' to display coordinates of the crossing points;\n'--count' to display the number of iterations the solution took.";
int display_points=0;                   //программой поддерживаются две опции, передача в любом порядке
int display_counter=0;
int main (int argc, char * argv[])
{
    if (argc>3)             //проверка числа аргументов
    {
        printf(invalid_arg_num_msg);
        return 1;
    }
    if (argc>1)
    {
        if (!strcmp(argv[1], "-h"))
        {
            if (argc>2)
            {
                printf(invalid_arg_num_msg);
                return 1;
            }
            printf(Help_message);
            return 1;
        }
    for (int i = 1;i<argc;i++)
    {
        if (!strcmp(argv[i], "--points"))       //появление этих параметров среди переданных программе
            display_points++;                   //выставляет значение "сигнальных" переменных display_*
        if (!strcmp(argv[i], "--count"))
            display_counter++;
    }
    if ((display_counter>1)||(display_points>1))
        {
            printf("Insert only one option of a kind"); //Сообщение о двойном вводе одного параметра
            return 1;
        }
    }
        
    int counter = 0;
    point array[3] = {0};                               //массив трех точек {X;Y}
    counter+=pointCalc(0.0001,5,EPS1,func1,func3,&array[0]);    //Вычисление точек пересечения функций
    counter+=pointCalc(0.0001,5,EPS1,func2,func3,&array[1]);    //друг с другом и передача числа итераций
    counter+=pointCalc(0.0001,5,EPS1,func1,func2,&array[2]);    //в общую сумму

    float f1ac = integral(array[0].x, array[2].x, EPS2, func1); //Расчет требуемых интегралах на отрезкам методом трапеций
    float f3ac = integral(array[0].x, array[2].x, EPS2, func3);
    float f2bc = integral(array[1].x, array[2].x, EPS2, func2);
    float f3bc = integral(array[0].x, array[2].x, EPS2, func3);

    float result = f1ac-f3ac-f2bc+f3bc; //вычисление площади
    if(display_points)
    {
        printf("Crossing points:\n");               //вывод дополнительных данных в зависимости
        printf("X-axis\t\tY-axis\n");               //от значения переменных display_*
        for (int i=0;i<3;i++)
            printf("%f\t%f\n",array[i].x,array[i].y);
    }
    if(display_counter)
        printf("Roots calculation took %d iterations\n",counter);   
    printf("The solution is %f",result);
    return 0;
}

