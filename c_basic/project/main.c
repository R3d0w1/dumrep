#include "temp_functions.h"
char Help_message[] = "The program is designed for printing out statistics for the temperature readings database.\nSupported parameters are:\n-h for help (but you already know that, apparently)\n-f <filename.csv> - a file with lines formatted as Year;Month;Day;hour;minute;second;temperature_value\n-m <month_number> number from 1 to 12, filter the output for the month specified";
int main(int argc, char * argv[])
{
    if ((2>argc)||(argc>5))
    {
        printf("Invalid number of arguments, use -h for more information");
        return 1;
    }
    if (!strcmp(argv[1], "-h"))
    {
        if (argc>2)
        {
            printf("U stoopid");
            return 1;
        }
        printf(Help_message);
        return 0;
    }
    else if (!strcmp(argv[1], "-f"))
    {
        switch(argc)
        {
            case 2:
            printf("No file specified");
            return 1;
            case 4:
            if (!strcmp(argv[3], "-m"))
            {
                printf("No month specified");
                return 1;
            }
            else
            {
                printf("invalid argument specified");
                return 1;
            }
            case 5:
            if (!strcmp(argv[3], "-m"))
            {
                if ((atoi(argv[4])>12)||(atoi(argv[4])<1))  
                {
                    printf("invalid month specified");
                    return 1;
                }
            }
            
        }     
    }
    struct return_values feedback[13];

    open(argv[2],feedback);
    printf("Month\tt_av\tt_min\tt_max\n");

    if (argc==5)
    {
        printf("%s\t%d\t%d\t%d\n",argv[4],feedback[atoi(argv[4])].av_temp,feedback[atoi(argv[4])].min_temp,feedback[atoi(argv[4])].max_temp);
        return 0;
    }
    for (int i=0;i<12;i++)
    {
         if(feedback[i].records_number==0)
        {
            printf("%d\tNo valid data\n",i+1);
            continue;
        }
        printf("%d\t%d\t%d\t%d\n",i+1,feedback[i].av_temp,feedback[i].min_temp,feedback[i].max_temp);
    }
    printf("Total\t%d\t%d\t%d\n",feedback[12].av_temp,feedback[12].min_temp,feedback[12].max_temp);
    
    return 0;
}  