#pragma once
#include "domain.h"

typedef Estate TElem;

typedef struct
{
	TElem* elements;
	int length, capacity;
} DynamicArray;

DynamicArray* createDynamicArray(int capacity);
void add(DynamicArray* estateList, TElem estate);
void initialzeList(DynamicArray* estateList);
void resize(DynamicArray* estateList);
void destroy(DynamicArray* estateList);
