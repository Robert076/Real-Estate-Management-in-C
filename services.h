#pragma once
#include "repository.h"

void addEstate(DynamicArray* arr, char* type, char* address, int surface, int price);
void removeEstate(DynamicArray* arr, char* address);
void updateEstate(DynamicArray* arr, char* address, char* type2, char* address2, int surface2, int price2);