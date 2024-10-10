
#pragma once

using namespace std;

// doubly linked list :
// doubly linked list :
template <typename T>

class clsNode
{

public:
    T value;
    clsNode *prev;
    clsNode *next;

    // parametrized constructor :
    clsNode(T value) : value(value), prev(nullptr), next(nullptr) {}
};

// iLinkedList interface :
template <typename T>
class clsLinkedListInteface
{
public:
    // declare a list of pure virtual functions :
    virtual void insertAtBeginning(T value) = 0;
    virtual void insertAtEnd(T value) = 0;
    virtual void deleteFirstNode() = 0;
    virtual void DeleteLastNode() = 0;
    virtual clsNode<T> *Find(T value) = 0;
    virtual void DeleteNode(T value) = 0;
    virtual string ToString() const = 0;

    virtual ~clsLinkedListInteface() = default;
};

template <typename T>
class clsDblLinkedList : public clsLinkedListInteface<T>
{
    clsNode<T> *head;
    clsNode<T> *Tail;

public:
    clsDblLinkedList() : head(nullptr), Tail(nullptr) {}

    void insertAtBeginning(T value) override
    {

        clsNode<T> *newNode = new clsNode<T>(value);

        if (this->isEmpty())
        {
            this->Tail = newNode;
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }
    }
    bool isEmpty()
    {
        return this->head == nullptr && this->Tail == nullptr;
    }

    void insertAtEnd(T value) override
    {
        clsNode<T> *newNode = new clsNode<T>(value);

        if (this->isEmpty())
        {
            this->Tail = newNode;
            this->head = newNode;
        }

        else
        {
            clsNode<T> *lastNode = this->head;
            while (lastNode->next != nullptr)
            {
                lastNode = lastNode->next;
            }

            lastNode->next = newNode;
            newNode->prev = lastNode;
            this->Tail = newNode;
        }
    }

    void deleteFirstNode() override
    {
        if (this->isEmpty())
        {
            return;
        }
        else
        {
            if (this->head == this->Tail)
            {
                delete this->head;
                this->head = nullptr;
                this->Tail = nullptr;
            }
            else
            {
                clsNode<T> *firstNode = this->head;
                this->head = this->head->next;
                delete firstNode;
            }
        }
    }

    clsNode<T> *Find(T value) override
    {
        clsNode<T> *currentNode = this->head;

        while (currentNode != nullptr)
        {
            if (currentNode->value == value)
                return currentNode;
            currentNode = currentNode->next;
        }

        return nullptr;
    }

    void DeleteLastNode() override
    {

        if (this->isEmpty())
        {
            return;
        }
        else
        {
            if (this->head == this->Tail)
            {
                delete this->head;
                this->head = nullptr;
                this->Tail = nullptr;
            }
            else
            {
                clsNode<T> *lastNode = this->Tail;
                this->Tail = this->Tail->prev;
                this->Tail->next = nullptr;
                delete lastNode;
            }
        }
    }
    void DeleteNode(T value) override
    {
        if (this->isEmpty())
        {
            return;
        }
        else
        {
            clsNode<T> *currentNode = this->Find(value);
            if (currentNode)
            {

                if (currentNode == this->head)
                {
                    this->deleteFirstNode();
                }
                else if (currentNode == this->Tail)
                    this->DeleteLastNode();

                else
                {

                    currentNode->prev->next = currentNode->next;
                    currentNode->next->prev = currentNode->prev;
                    delete currentNode;
                }
            }
        }
    }

    string ToString() const override
    {
        string result = "List: ";
        clsNode<T> *current = head;
        while (current != nullptr)
        {
            result += to_string(current->value) + " ";
            current = current->next;
        }
        return result;
    }

    ~clsDblLinkedList()
    {

        clsNode<T> *current = head;
        while (current != nullptr)
        {
            clsNode<T> *next = current->next;
            delete current;
            current = next;
        }
    }
};