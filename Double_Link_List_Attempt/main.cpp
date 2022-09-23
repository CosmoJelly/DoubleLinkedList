#include <iostream>
#include "List.h"

int main() 
{
	List* list = new List();


	list->add(1);
	list->add(2);
	list->add(3);
	list->addAfter(70, 3);
	//list->remove(3);


	list->displayList();

	return 0;
}