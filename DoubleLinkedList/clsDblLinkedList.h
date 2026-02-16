#pragma once
#include<iostream>
using namespace std;
template <class T>

class clsDblLinkedList
{

protected:
int	_Size = 0;
public:


	class Node
	{
	public:
		T value;
		Node* Next;
		Node* Prev;
	};

	Node* head = NULL;

	void InsertAtBeginning(T value) {


		Node* NewNode = new Node();
		NewNode->value = value;
		NewNode->Next = head;
		NewNode->Prev = NULL;


		if (head != NULL) {
			head->Prev = NewNode;
		}
		head = NewNode;
		_Size++;
	}

	Node* Find(T value) {

		Node* Current = head; ;

		while (Current != NULL) {
			if (Current->value == value) {

				return Current;
			}
			Current = Current->Next;
		}
		return NULL;
	}
	void InsertAfter(Node* Current, T Value) {
		//1 check if Node is NULL
		if (Current == NULL)
		{
			return;
		}

		//2 create New Node 
		Node* NewNode = new Node();
		NewNode->value = Value;

		//3 Set NewNode Pointer 
		NewNode->Next = Current->Next;
		NewNode->Prev = Current;

		//4 update the forward neighbor's back pointer 

		if (Current->Next != NULL) {
			Current->Next->Prev = NewNode;
		}
		//5 update After's forword pointer 
		Current->Next = NewNode;
		_Size++;
	}


	void InsertAtEnd(T value) {
		Node* NewNode = new Node();
		NewNode->value = value;
		NewNode->Next = NULL;
		_Size++;
		if (head == NULL) {
			NewNode->Prev = NULL;
			head = NewNode;
			return;
		}
		Node* Current = head;
		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}
		Current->Next = NewNode;
		NewNode->Prev = Current;
	}


	void DeleteNode(Node* NodeToDelete) {
		/*
		1-Set the next pointer of the previous node to the next pointer of the current node.
		2-Set the previous pointer of the next node to the previous pointer of the current node.
		3-Delete the current node.
	*/

		if (NodeToDelete == NULL || head == NULL) {
			return;
		}
		Node* Current = head;

		if (head == NodeToDelete) {
			head = NodeToDelete->Next;
		}

		if (NodeToDelete->Next != NULL) {
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}
		if (NodeToDelete->Prev != NULL) {
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode() {

		/*
			1-Store a reference to the head node in a temporary variable.
			2-Update the head pointer to point to the next node in the list.
			3-Set the previous pointer of the new head to NULL.
			4-Delete the temporary reference to the old head node.
		*/
		if (head == NULL) {
			return;
		}
		Node* temp = head;

		head = head->Next;
		if (head != NULL) {
			head->Prev = NULL;
		}
		delete temp;
		_Size--;
	}

	void DeleteLastNode() {
		/*
			1-Traverse the list to find the last node.
			2-Set the next pointer of the second-to-last node to NULL.
			3-Delete the last node.
		*/

		//1 check if head is empty and return 
		if (head == NULL) {
			return;
		}
		// 2 check if there is only one node delete and return 
		_Size--;
		if (head->Next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		// 3 create current to treeverse the list
		Node* Current = head;
		//4 check if the next of the next is Null which mean it is the last one
		while (Current->Next->Next != NULL) {
			//5 go forowrd one node
			Current = Current->Next;

		}
		//6 create temp to stor last node to delete 
		Node* temp = Current->Next;
		//7 make the last node NULL
		Current->Next = NULL;
		// 8 delete the last node 
		delete temp;
	}


	void PrintList() {
		Node* Current = head;
		while (Current != NULL) {
			cout << Current->value << " <-> ";
			Current = Current->Next;
		}
		cout << "\n";

	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* Current = head;
		Node* temp = nullptr;

		while (Current != NULL)
		{
			temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = temp;
			Current = Current->Prev;
		}
		if (temp != nullptr)
		{
			head = temp->Prev;
		}
	}

	Node* GetNode(T index) {

		if (index > _Size - 1 || index < 0) {
			return NULL;
		}

		Node* Current = head;
		int Counter = -1;

		while ((Current != NULL) && (Current->Next != NULL))
		{
			Counter++;
			if (Counter == index)
			{
				return Current;
			}
			Current = Current->Next;
		}
		return NULL;
	}
	
};