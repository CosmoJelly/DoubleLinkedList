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
		newNode->setPrev(head);
		newNode->setNext(head->getNext());
		head->setNext(newNode);
		(head->getNext())->setPrev(newNode);
		++size;
	}
	else if (head == nullptr) //&& head->getNext() == nullptr && head->getPrev() == nullptr)
	{
		head = newNode;
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