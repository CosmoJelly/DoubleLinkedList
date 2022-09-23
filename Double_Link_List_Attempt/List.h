#pragma once
#include "Node.h"

class List
{
private:
	Node* head;
	int size;
public:
	List();
	~List();
	void add(int data);
	void addAfter(int data, int afterdata);
	void remove(int data);
	void displayList();
};