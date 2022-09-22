#pragma once
class Node
{
private:
	Node* next;
	Node* prev;
	int data;

public:
	Node();
	Node(int data);
	~Node();
	Node* getNext();
	Node* getPrev();
	int getData();
	void setNext(Node* next);
	void setPrev(Node* prev);
	void setData(int data);
};
