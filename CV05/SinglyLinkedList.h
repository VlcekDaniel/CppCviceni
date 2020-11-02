#pragma once
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
class SinglyLinkedList {

	class Node
	{
	private:
		Node* dalsi;
		Object data;
	public:

	};
private:
	Node* start;
public:
	void AddNode(Node* node);
	Node* FindNode();
	Node* DeleteNode();

};

#endif // SINGLY_LINKED_LIST_H
