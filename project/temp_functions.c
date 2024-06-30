#include "temp_functions.h"
int read_line_w_check(FILE * filename, struct record* target)
{
    int a;
   switch(a=fscanf(filename,"%u;%u;%u;%u;%u;%d%[^\n]%*c",&(target->year),&(target->month),&(target->day),&(target->hours),&(target->minutes),&(target->t)))
   {  
    case 6:
        return 0;
    case EOF:
        return 1;
    default:
        while(fgetc(filename)!='\n');
        return 2;
   }
}
void open(char* filename, struct return_values* feedback)
{
    int a=0;
    int counter=0;
    int sub_flag=0;
    for (int i=0;i<13;i++)
    {
        feedback[i].min_temp = 99;
        feedback[i].max_temp = -99;
        feedback[i].records_number = 0;
        feedback[i].av_temp = 0;
    }
    FILE* f = fopen(filename,"r");
    struct record entity = {0,0,0,0,0,0};
    struct record *ptr_rec = &entity;
    
        while((a=read_line_w_check(f,ptr_rec))!=1)
        {
            counter++;
            if(a==2)
            {
                sub_flag = 1;
                printf ("Syntax error in line %d, ignoring\n",counter);
                continue;
            }

            m_av(ptr_rec,feedback);
            m_min(ptr_rec,feedback);
            m_max(ptr_rec,feedback);
          
            t_av(ptr_rec,feedback);
            t_min(ptr_rec,feedback);
            t_max(ptr_rec,feedback);
          
        }
    fclose(f);

    for (int i=0;i<13;i++)
    {
        if (feedback[i].records_number == 0)
        {
            continue;
        }
        feedback[i].av_temp /= feedback[i].records_number;
    }
    return;
}
void m_av(struct record* target, struct return_values* feedback)
{
        feedback[target->month-1].av_temp+=target->t;
        feedback[target->month-1].records_number++;
}
void m_min(struct record* target, struct return_values* feedback)
{
        if(target->t<feedback[target->month-1].min_temp)
        {
           feedback[target->month-1].min_temp = target->t;
        }
}
void m_max(struct record* target, struct return_values* feedback)
{
    if(target->t>feedback[target->month-1].max_temp)
    {
        feedback[target->month-1].max_temp = target->t;
    }
}
void t_av(struct record* target, struct return_values* feedback)
{
    feedback[12].av_temp+=target->t;
    feedback[12].records_number++;
}
void t_min(struct record* target, struct return_values* feedback)
{
    if(target->t<feedback[12].min_temp)
        {
           feedback[12].min_temp = target->t;
        }
}
void t_max(struct record* target, struct return_values* feedback)
{
    if(target->t>feedback[12].max_temp)
    {
        feedback[12].max_temp = target->t;
    }
}