#pragma once
#include "services.h"

void runMenu(DynamicArray* arr);
void manageAddEstate(DynamicArray* arr);
void getInputForAddEstate(char* type, char* address, int* surface, int* price);
void manageRemoveEstate(DynamicArray* arr);
void manageUpdateEstate(DynamicArray* arr);
void manageListEstatesByPrice(DynamicArray* arr);
void sortListByPrice(DynamicArray* arr);
void manageListEstatesByType(DynamicArray* arr);