#include <stdio.h>
#include <stdlib.h>
#include "domain.h"
#include "dynamicArray.h"
#include "ui.h"

int main()
{
	DynamicArray* estateList = createDynamicArray(2);
	initializeList(estateList);
	runMenu(estateList);
	return 0;
}