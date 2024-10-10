#include "iostream"
#include "./clsDblLinkedLIst.h"
using namespace std;



int main()
{

      clsDblLinkedList<int> myDbLinkedList;

    // Insert some numbers
    myDbLinkedList.insertAtEnd(1);
    myDbLinkedList.insertAtEnd(2);
    myDbLinkedList.insertAtEnd(3);

    // Display the list
    std::cout << "List: " << myDbLinkedList.ToString() << std::endl;

    // Find a node with value 2
    clsNode<int>* foundNode = myDbLinkedList.Find(2);
    if (foundNode) {
        std::cout << "Found: " << foundNode->value << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // Delete node with value 2
    myDbLinkedList.DeleteNode(2);
    std::cout << "After deletion: " << myDbLinkedList.ToString() << std::endl;

    // Delete the first node
    myDbLinkedList.deleteFirstNode();
    std::cout << "After deleting first node: " << myDbLinkedList.ToString() << std::endl;

    // Delete the last node
    myDbLinkedList.DeleteLastNode();
    std::cout << "After deleting last node: " << myDbLinkedList.ToString() << std::endl;
    return 0;
}
