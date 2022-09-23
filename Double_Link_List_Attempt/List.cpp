#include <iostream>
#include "List.h"

List::List()
{
	head = nullptr;
	size = 0;
}

List::~List()
{
	Node* temp = head;
	while (temp != nullptr) 
	{
		head = head->getNext();
		delete temp;
		temp = head;
	}
}

void List::add(int data)
{
	Node* newNode = new Node(data);
	if (head != nullptr)
	{
		newNode->setNext(head->getNext());
		(head->getNext())->setPrev(newNode);
		newNode->setPrev(head);
		head->setNext(newNode);
		//head = newNode;
		++size;
	}
	else //&& head->getNext() == nullptr && head->getPrev() == nullptr)
	{
		head = newNode;
		++size;
	}
}

void List::displayList()
{
	Node* iterator = head;
	while (iterator != nullptr)
	{
		std::cout << "|" << iterator->getData() << "|";
		iterator = iterator->getNext();
		if (iterator != nullptr)
			std::cout << " <-> ";
	}
	std::cout << std::endl;
}