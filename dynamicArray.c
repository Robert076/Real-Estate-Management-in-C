#include <stdio.h>
#include <stdlib.h>
#include "dynamicArray.h"

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
	arr->capacity = capacity;
	arr->length = 0;
	arr->elements = (TElem*)malloc(capacity * sizeof(TElem));

	return arr;
}

void add(DynamicArray* arr, TElem elem)
{
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elements[arr->length] = elem;
	arr->length++;
}

void resize(DynamicArray* arr)
{
	arr->capacity *= 2;
	arr->elements = (TElem*)realloc(arr->elements, arr->capacity * sizeof(TElem));
}

void initializeList(DynamicArray* arr)
{
	TElem* estate;
	estate = createEstate("apartment", "aleea macului nr.3", 300, 34000);
	add(arr, *estate);
	estate = createEstate("house", "aleea orhideei nr.3", 100, 23000);
	add(arr, *estate);
	estate = createEstate("penthouse", "strada libertatii nr.5", 430, 45000);
	add(arr, *estate);
	estate = createEstate("penthouse", "strada unirii nr.1", 210, 66000);
	add(arr, *estate);
	estate = createEstate("house", "mihai viteazu nr.8", 160, 34000);
	add(arr, *estate);
	estate = createEstate("apartment", "bulevardul republicii nr.34", 70, 23000);
	add(arr, *estate);
	estate = createEstate("apartment", "piata marasti nr.23", 300, 64000);
	add(arr, *estate);
	estate = createEstate("house", "grigorescu nr.7", 150, 34000);
	add(arr, *estate);
	estate = createEstate("penthouse", "dubai nr.80", 330, 24000);
	add(arr, *estate);
	estate = createEstate("apartment", "centru vechi nr.3", 30, 61000);
	add(arr, *estate);
}