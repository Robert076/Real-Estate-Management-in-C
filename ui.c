#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void runMenu(DynamicArray* arr)
{
	while (1)
	{
		printf("What do you wish to do?\n");
		printf("1. Add a new estate\n");
		printf("2. Remove an estate\n");
		printf("3. Update an estate\n");
		printf("4. List estates ascending by price\n");
		printf("5. List estates of given type with a surface greater than the given one\n");

		int userInput;
		scanf("%d", &userInput);

		int addEstateOption = 1, removeEstateOption = 2, updateEstateOption = 3, listEstatesByPriceOption = 4, listEstatesByTypeOption = 5;

		if (userInput == addEstateOption)
			manageAddEstate(arr);
		else if (userInput == removeEstateOption)
			manageRemoveEstate(arr);
		else if (userInput == updateEstateOption)
			manageUpdateEstate(arr);
		else if (userInput == listEstatesByPriceOption)
			manageListEstatesByPrice(arr);
		else if (userInput == listEstatesByTypeOption)
			manageListEstatesByType(arr);
	}
	
}

void manageAddEstate(DynamicArray* arr)
{
	char* type = malloc(100 * sizeof(char));
	char* address = malloc(100 * sizeof(char));
	int surface, price;

	while (getchar() != '\n');
	printf("Enter type: ");
	if (scanf("%99[^\n]%*c", type) != 1)
	{
		printf("Error reading type! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	printf("Enter address: ");
	if (scanf("%99[^\n]%*c", address) != 1)
	{
		printf("Error reading address! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	printf("Enter surface: ");
	if (scanf("%d", &surface) != 1)
	{
		printf("Error reading surface! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	printf("Enter price: ");
	if (scanf("%d", &price) != 1)
	{
		printf("Error reading price! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	addEstate(arr, type, address, surface, price);

	free(type);
	free(address);
}

void manageRemoveEstate(DynamicArray* arr)
{
	char* address = (char*)malloc(100 * sizeof(char));
	printf("Enter the address you want to remove: ");
	while (getchar() != '\n');
	if (scanf("%99[^\n]%*c", address) != 1)
	{
		printf("Error reading address! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}
	removeEstate(arr, address);
}

void manageUpdateEstate(DynamicArray* arr)
{
	while (getchar() != '\n');
	char address[100];
	printf("Enter the address you want to update: ");
	if (scanf("%99[^\n]%*c", address) != 1)
	{
		printf("Error reading address! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}
	char* type2 = malloc(100 * sizeof(char));
	char* address2 = malloc(100 * sizeof(char));
	int surface2;
	int price2;

	printf("Enter type: ");
	if (scanf("%99[^\n]%*c", type2) != 1)
	{
		printf("Error reading type! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	printf("Enter address: ");
	if (scanf("%99[^\n]%*c", address2) != 1)
	{
		printf("Error reading address! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	printf("Enter surface: ");
	if (scanf("%d", &surface2) != 1)
	{
		printf("Error reading surface! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	printf("Enter price: ");
	if (scanf("%d", &price2) != 1)
	{
		printf("Error reading price! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}

	updateEstate(arr, address, type2, address2, surface2, price2);
}

void manageListEstatesByPrice(DynamicArray* arr)
{
	while (getchar() != '\n');
	char address[100];
	printf("Enter the address you are searching for ('all' for everything) : ");
	if (scanf("%99[^\n]%*c", address) != 1)
	{
		printf("Error reading address! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}
	sortListByPrice(arr);
	if (strcmp(address, "all") == 0)
	{
		int i;
		for (i = 0; i < arr->length; i++)
			printf("%s %s %d %d\n", arr->elements[i].type, arr->elements[i].address, arr->elements[i].surface, arr->elements[i].price);
	}
	else
	{
		int i;
		for (i = 0; i < arr->length; i++)
			if (strstr(arr->elements[i].address, address))
				printf("%s %s %d %d\n", arr->elements[i].type, arr->elements[i].address, arr->elements[i].surface, arr->elements[i].price);
	}
}

void manageListEstatesByType(DynamicArray* arr)
{
	while (getchar() != '\n');
	char type[100];
	printf("Enter the type you are searching for (apartment, house, penthouse) : ");
	if (scanf("%99[^\n]%*c", type) != 1)
	{
		printf("Error reading address! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}
	int surface;
	printf("Enter surface: ");
	if (scanf("%d", &surface) != 1)
	{
		printf("Error reading surface! Invalid input!\n");
		while (getchar() != '\n');
		return;
	}
	
	int i;
	for(i = 0; i < arr->length; i++)
		if (strcmp(arr->elements[i].type, type) == 0 && arr->elements[i].surface >= surface)
			printf("%s %s %d %d\n", arr->elements[i].type, arr->elements[i].address, arr->elements[i].surface, arr->elements[i].price);
}

void sortListByPrice(DynamicArray* arr)
{
	int i, j;
	for (i = 0; i < arr->length - 1; i++)
	{
		for (j = 0; j < arr->length - i - 1; j++)
		{
			if (arr->elements[j].price > arr->elements[j + 1].price)
			{
				Estate temp = arr->elements[j];
				arr->elements[j] = arr->elements[j + 1];
				arr->elements[j + 1] = temp;
			}
		}
	}
}
