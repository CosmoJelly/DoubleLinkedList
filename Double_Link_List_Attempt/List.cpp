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
		newNode->setNext(head);
		head->setPrev(newNode);
		head = newNode;
		size++;
	}
	else
	{
		head = newNode;
		size++;
	}
}

void List::addAfter(int data, int afterdata)
{
	Node* iterator = head;
	while (iterator->getNext() != nullptr && iterator->getData() != afterdata)
	{
		iterator = iterator->getNext();
	}
	Node* newNode = new Node(data);
	newNode->setPrev(iterator);
	newNode->setNext(iterator->getNext());
	(iterator->getNext())->setPrev(newNode);
	iterator->setNext(newNode);
}

void List::remove(int data)
{
	Node* iterator = head;
	while (iterator->getNext() != nullptr && iterator->getData() != data)
	{
		iterator = iterator->getNext();
	}
	iterator->getPrev()->setNext(iterator->getNext());
	iterator->getNext()->setPrev(iterator->getPrev());
	delete iterator;
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