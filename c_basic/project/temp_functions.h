#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct record {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    int t;
};
struct return_values {
    int av_temp;
    int min_temp;
    int max_temp;
    int records_number;
};
int read_line_w_check(FILE * filename, struct record * target);
void open(char* filename, struct return_values* feedback);
void m_av(struct record* target, struct return_values* feedback);
void m_min(struct record* target, struct return_values* feedback);
void m_max(struct record* target, struct return_values* feedback);
void t_av(struct record* target, struct return_values* feedback);
void t_min(struct record* target, struct return_values* feedback);
void t_max(struct record* target, struct return_values* feedback);