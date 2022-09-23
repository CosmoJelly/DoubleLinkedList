#include <iostream>
#include "List.h"

int main() 
{
	List* list = new List();

	list->add(10);
	list->add(20);
	list->add(30);

	list->displayList();

	return 0;
}