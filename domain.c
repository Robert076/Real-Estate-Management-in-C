#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "domain.h"

Estate* createEstate(char* type, char* address, int surface, int price)
{
	Estate* newEstate = (Estate*)malloc(sizeof(Estate));
	newEstate->type = (char*)malloc((strlen(type) + 1) * sizeof(char));
	newEstate->address = (char*)malloc((strlen(address) + 1) * sizeof(char));
	strcpy(newEstate->type, type);
	strcpy(newEstate->address, address);
	newEstate->surface = surface;
	newEstate->price = price;

	return newEstate;
}