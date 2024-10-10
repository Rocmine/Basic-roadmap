#include "iostream"
#include "./clsDblLinkedLIst.h"
using namespace std;

int main()
{

    clsDblLinkedList<int> myDbLinkedList;

    myDbLinkedList.insertAtEnd(1);
    myDbLinkedList.insertAtEnd(2);
    myDbLinkedList.insertAtEnd(3);

    cout << myDbLinkedList.ToString() << std::endl;

    clsNode<int> *foundNode = myDbLinkedList.Find(2);
    if (foundNode)
    {
        std::cout << "Found: " << foundNode->value << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    myDbLinkedList.DeleteNode(2);
    cout << "After deletion: " << myDbLinkedList.ToString() << "\n";

    myDbLinkedList.deleteFirstNode();
    cout << "After deleting first node: " << myDbLinkedList.ToString() << "\n";

    cout << "The linked list size :  " << myDbLinkedList.Size() << endl;

    myDbLinkedList.DeleteLastNode();

    cout << "After deleting last node: " << myDbLinkedList.ToString() << "\n";

    myDbLinkedList.insertAtEnd(1);
    myDbLinkedList.insertAtEnd(2);
    myDbLinkedList.insertAtEnd(3);
    myDbLinkedList.reverse();
    myDbLinkedList.insertAtEnd(3);

    cout << myDbLinkedList.ToString() << "\n";
    cout << "Update node by index :\n";
    myDbLinkedList.UpdateItem(0, 100);
    myDbLinkedList.InsertAfter(3, 250);
    cout << myDbLinkedList.ToString() << "\n";

    cout << "The node at index :" << myDbLinkedList.GetNode(3) << endl;
    cout << "The item at index :" << myDbLinkedList.GetItem(10) << endl;

    myDbLinkedList.Clear();
    cout << "After clearing the linked  : " << myDbLinkedList.ToString() << std::endl;

    return 0;
}
