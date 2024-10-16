#include "header.h"

int main()
{
	int choice;
	struct plant *result = NULL;

	printf("Welcome to the INDUSTRIES Pvt Ltd");

	menu();

	printf("Enter your choice");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			result = create_plant();
			traverse(result);
			break;

		default:
			printf("Invalid choice");
	}
}
