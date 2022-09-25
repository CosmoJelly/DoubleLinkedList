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
	if (head == nullptr)
	{
		head = newNode;
		size++;
	}
	else
	{
		newNode->setNext(head);
		newNode->setPrev(nullptr);
		head->setPrev(newNode);
		head->setNext(nullptr);
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
	newNode->setNext(iterator->getNext());
	newNode->setPrev(iterator);
	//add a check to see if next is null
	//(iterator->getNext())->setPrev(newNode);
	iterator->setNext(newNode);
}

void List::remove(int data)
{
	Node* iterator = head;
	while (iterator->getNext() != nullptr && (iterator->getData() != data))
	{
		iterator = iterator->getNext();
	}
	Node* temp = iterator->getPrev();
	//temp->setNext(iterator->getNext());
	//(iterator->getNext())->setPrev(temp);

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