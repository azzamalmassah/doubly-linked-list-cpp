

#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;
int main()
{
    clsDblLinkedList <int> MyDblLinkedList;
    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);


    cout << "Linked List Content : \n";
    MyDblLinkedList.PrintList();


    // Find
    clsDblLinkedList<int>::Node* N1 = MyDblLinkedList.Find(2);


    if (N1 != NULL) {
        cout << "\nNode Found !\n";
    }
    else {
        cout << "\nNode Was not Found!\n";
    }

    cout << "After Inserting 100 after 2 \n";
    MyDblLinkedList.InsertAfter(N1, 100);
    MyDblLinkedList.PrintList();

    cout << "After Inserting 500 at End \n";
    MyDblLinkedList.InsertAtEnd(500);
    MyDblLinkedList.PrintList();

    clsDblLinkedList<int>::Node* N2 = MyDblLinkedList.Find(4);

    cout << "Delete Node 4 \n";
    MyDblLinkedList.DeleteNode(N2);
    MyDblLinkedList.PrintList();


    cout << "After Delete First Node  \n";
    MyDblLinkedList.DeleteFirstNode();
    MyDblLinkedList.PrintList();

    cout << "After Delete Last Node  \n";
    MyDblLinkedList.DeleteLastNode();
    MyDblLinkedList.PrintList();

    cout << "After Reverse  \n";
    MyDblLinkedList.Reverse();
    MyDblLinkedList.PrintList();


}
