#include "Node.h"

Node::Node()
{
	next = nullptr;
	prev = nullptr;
	data = 0;
}

Node::Node(int data)
{
	this->next = nullptr;
	this->prev = nullptr;
	this->data = data;
}

Node::~Node()
{
	delete next;
}

Node* Node::getNext()
{
	return this->next;
}

Node* Node::getPrev()
{
	return this->prev;
}

int Node::getData()
{
	return data;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

void Node::setPrev(Node* prev)
{
	this->prev = prev;
}

void Node::setData(int data)
{
	this->data = data;
}
