#include "services.h"

void addEstate(DynamicArray* arr, char* type, char* address, int surface, int price)
{
	Estate* estate = createEstate(type, address, surface, price);

	add(arr, *estate);
}

void removeEstate(DynamicArray* arr, char* address)
{
	int i;
	for(i = 0; i < arr->length; i++)
		if (strcmp(arr->elements[i].address, address) == 0)
		{
			int j;
			for (j = i; j < arr->length - 1; j++)
				arr->elements[j] = arr->elements[j + 1];
			arr->length--;
			break;
		}
}

void updateEstate(DynamicArray* arr, char* address, char* type2, char* address2, int surface2, int price2)
{
    int i;
    for (i = 0; i < arr->length; i++)
        if (strcmp(arr->elements[i].address, address) == 0)
        {
            strcpy(arr->elements[i].type, type2);
            strcpy(arr->elements[i].address, address2);
            arr->elements[i].surface = surface2;
            arr->elements[i].price = price2;
            break;
        }
}