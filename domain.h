#pragma once

typedef struct
{
	char* type;
	char* address;
	int surface;
	int price;
} Estate;

Estate* createEstate(char*, char*, int, int);
