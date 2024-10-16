#include "header.h"

struct plant *create_plant(void)
{
    int np, ele_p;
    struct plant *phead = NULL;
    struct plant *new_p;
    int nm, ele_m, mproduction;

    np = validate_int_input("Enter the number of plants: ");

    for (int i = 0; i < np; i++)
    {
        struct plant *temp_p = (struct plant *)malloc(sizeof(struct plant));

        ele_p = validate_int_input("Enter the plant %d id: ");
        temp_p->plant_id = ele_p;

        printf("Enter the plant %d name: ", i + 1);
        scanf("%s", temp_p->plant_name);
        temp_p->plink = NULL;

        struct machine *mhead = NULL;
        struct machine *last = NULL;

        nm = validate_int_input("Enter the number of machines for plant %d: ");

        for (int j = 0; j < nm; j++)
        {
            struct machine *temp_m = (struct machine *)malloc(sizeof(struct machine));

            ele_m = validate_int_input("Enter the machine %d id: ");
            temp_m->machine_id = ele_m;

            printf("Enter the machine %d name: ", j + 1);
            scanf("%s", temp_m->machine_name);

            temp_m->start_time.hour = validate_int_input("Enter the machine %d start time hour (0-23): ");
            temp_m->start_time.minute = validate_int_input("Enter the machine %d start time minute (0-59): ");
            validate_time_format(temp_m->start_time.hour * 100 + temp_m->start_time.minute); // Validates time

            temp_m->stop_time.hour = validate_int_input("Enter the machine %d stop time hour (0-23): ");
            temp_m->stop_time.minute = validate_int_input("Enter the machine %d stop time minute (0-59): ");
            validate_time_format(temp_m->stop_time.hour * 100 + temp_m->stop_time.minute); // Validates time

            mproduction = validate_int_input("Enter the machine %d production: ");
            temp_m->production = mproduction;

            temp_m->cycle_time = calculate_cycle_time(temp_m->start_time, temp_m->stop_time);

            temp_m->mlink = NULL;

            if (mhead == NULL)
            {
                mhead = temp_m;
            }
            else
            {
                last->mlink = temp_m;
            }
            last = temp_m;
        }

        temp_p->mlink = mhead;

        if (phead == NULL)
        {
            phead = temp_p;
        }
        else
        {
            new_p = phead;
            while (new_p->plink != NULL)
            {
                new_p = new_p->plink;
            }
            new_p->plink = temp_p;
        }
    }
    return phead;
}
