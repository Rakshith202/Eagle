#include<stdio.h>
#include<stdlib.h>

struct time {
    int hour;
    int minute;
};

struct plant {
    int plant_id;
    char plant_name[20];
    struct machine *mlink;
    struct plant *plink;
};

struct machine {
    int machine_id;
    char machine_name[20];
    struct time start_time;
    struct time stop_time;
    float cycle_time;
    int production;
    struct machine *mlink;
};

void menu(void);
struct plant *create_plant(void);
void traverse(struct plant* head);
float calculate_cycle_time(struct time start, struct time stop);
