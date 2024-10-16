#include "header.h"

struct plant *create_plant(void)
{
    int np, ele_p;
    struct plant *phead = NULL;
    struct plant *new_p;
    int nm, ele_m,mproduction;

    printf("Enter the number of plants: ");
    scanf("%d", &np);

    for (int i = 0; i < np; i++)
    {
        struct plant *temp_p = (struct plant *)malloc(sizeof(struct plant));

        printf("Enter the plant %d id: ", i + 1);
        scanf("%d", &ele_p);
        temp_p->plant_id = ele_p;

        printf("Enter the plant %d name: ", i + 1);
        scanf("%s", temp_p->plant_name);
        temp_p->plink = NULL;

        struct machine *mhead = NULL;
        struct machine *last = NULL;

        printf("Enter the number of machines for plant %d: ", i + 1);
        scanf("%d", &nm);

        for (int j = 0; j < nm; j++)
        {
            struct machine *temp_m = (struct machine *)malloc(sizeof(struct machine));

            printf("Enter the machine %d id: ", j + 1);
            scanf("%d", &ele_m);
            temp_m->machine_id = ele_m;

            printf("Enter the machine %d name: ", j + 1);
            scanf("%s", temp_m->machine_name);

            printf("Enter the machine %d start time (HH:MM): ", j + 1);
            scanf("%d:%d", &temp_m->start_time.hour, &temp_m->start_time.minute);

            printf("Enter the machine %d stop time (HH:MM): ", j + 1);
            scanf("%d:%d", &temp_m->stop_time.hour, &temp_m->stop_time.minute);

	    printf("Enter the machine %d production: ", j + 1);
            scanf("%d", &mproduction);
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
