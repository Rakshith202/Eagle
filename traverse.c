#include "header.h"

void traverse(struct plant *head)
{
    int mprod = 0;
    while (head != NULL)
    {
        printf("Plant ID: %d, Plant Name: %s\n", head->plant_id, head->plant_name);

        struct machine *temp_m = head->mlink;

        while (temp_m != NULL)
        {
            printf("   Machine ID: %d, Machine Name: %s, Start Time: %02d:%02d, Stop Time: %02d:%02d, Cycle Time: %.2f hours, Production:%d\n", 
                   temp_m->machine_id, 
                   temp_m->machine_name, 
                   temp_m->start_time.hour, temp_m->start_time.minute, 
                   temp_m->stop_time.hour, temp_m->stop_time.minute, 
                   temp_m->cycle_time,temp_m->production);
	
            mprod = mprod + temp_m->production;
	    temp_m = temp_m->mlink;
	 //   mprod = mprod + temp_m->production;
        }
	printf("\nPlant %s productions is %d\n",head->plant_name,mprod);
        head = head->plink;
    }
}
