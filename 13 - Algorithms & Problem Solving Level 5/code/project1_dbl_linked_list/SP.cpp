#include <iostream>
#include <sstream>

// Node class definition
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// Linked list interface definition
template <typename T>
class ILinkedList {
public:
    virtual void InsertAtBeginning(T value) = 0;
    virtual void InsertAtEnd(T value) = 0;
    virtual void DeleteFirstNode() = 0;
    virtual void DeleteLastNode() = 0;
    virtual Node<T>* Find(T value) = 0;
    virtual void DeleteNode(T value) = 0;
    virtual std::string ToString() const = 0; // Updated method
    virtual ~ILinkedList() = default;
};

// MyDbLinkedList class definition
template <typename T>
class MyDbLinkedList : public ILinkedList<T> {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    MyDbLinkedList() : head(nullptr), tail(nullptr) {}

    void InsertAtBeginning(T value) override {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void InsertAtEnd(T value) override {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void DeleteFirstNode() override {
        if (!head) return; // List is empty
        if (head == tail) { // Only one node
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    void DeleteLastNode() override {
        if (!tail) return; // List is empty
        if (head == tail) { // Only one node
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    Node<T>* Find(T value) override {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Not found
    }

    void DeleteNode(T value) override {
        Node<T>* current = Find(value);
        if (current) {
            if (current == head) {
                DeleteFirstNode();
            } else if (current == tail) {
                DeleteLastNode();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
        }
    }

    // Return string representation of the list
    std::string ToString() const override {
        std::ostringstream oss;
        Node<T>* current = head;
        while (current != nullptr) {
            oss << current->data << " ";
            current = current->next;
        }
        return oss.str(); // Return the string
    }

    ~MyDbLinkedList() {
        // Clean up all nodes
        while (head != nullptr) {
            DeleteFirstNode();
        }
    }
};

// Client code
int main() {
    MyDbLinkedList<int> myDbLinkedList;

    // Insert some numbers
    myDbLinkedList.InsertAtEnd(1);
    myDbLinkedList.InsertAtEnd(2);
    myDbLinkedList.InsertAtEnd(3);

    // Display the list
    std::cout << "List: " << myDbLinkedList.ToString() << std::endl;

    // Find a node with value 2
    Node<int>* foundNode = myDbLinkedList.Find(2);
    if (foundNode) {
        std::cout << "Found: " << foundNode->data << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // Delete node with value 2
    myDbLinkedList.DeleteNode(2);
    std::cout << "After deletion: " << myDbLinkedList.ToString() << std::endl;

    // Delete the first node
    myDbLinkedList.DeleteFirstNode();
    std::cout << "After deleting first node: " << myDbLinkedList.ToString() << std::endl;

    // Delete the last node
    myDbLinkedList.DeleteLastNode();
    std::cout << "After deleting last node: " << myDbLinkedList.ToString() << std::endl;

    return 0;
}
