
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
    virtual string ToString() = 0;
    virtual int Size() = 0;
    virtual void Clear() = 0;

    virtual ~clsLinkedListInteface() = default;
};

template <typename T>
class clsDblLinkedList : public clsLinkedListInteface<T>
{
    clsNode<T> *head;
    clsNode<T> *Tail;
    int size;

public:
    clsDblLinkedList() : head(nullptr), Tail(nullptr), size(0) {}

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
        this->size++;
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
            this->size--;
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
            this->size--;
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
            this->size--;
        }
    }
    int Size() override
    {
        return size;
    }

    string ToString() override
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

    void Clear() override
    {
        clsNode<T> *current = head;
        while (current != nullptr)
        {
            clsNode<T> *next = current->next;
            delete current;
            current = next;
        }
        this->head = nullptr;
        this->Tail = nullptr;
        this->size = 0;
    }
    void reverse()
    {
        if (this->isEmpty())
        {
            return;
        }

        clsNode<T> *current = this->Tail;
        clsNode<T> *temp = nullptr;

        while (current != nullptr)
        {

            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = current->next;
        }

        temp = this->head;
        this->head = this->Tail;
        this->Tail = temp;
    }
    clsNode<T> *GetNode(int index)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }
        if (index > this->size - 1 || index < 0)
        {
            return nullptr;
        }

        clsNode<T> *current = this->head;
        int counter = 0;
        for (clsNode<T> *i = this->head; counter++ < index; i++)
        {

            current = current->next;
        }

        return current;
    }
    T GetItem(int index)
    {
        clsNode<T> *node = this->GetNode(index);
        return node ? node->value : T{}; // Return default value of T if node is nullptr
    }
    bool UpdateItem(int index, T newValue)
    {
        if (isEmpty())
            false;

        clsNode<T> *targetNode = this->GetNode(index);
        if (targetNode)
        {
            targetNode->value = newValue;
            return true;
        }

        return false;
    }
    bool InsertAfter(int index, T value)
    {

        clsNode<T> *targetNode = this->GetNode(index);

        if (targetNode)
        {
            clsNode<T> *newNode = new clsNode(value);

            newNode->next = targetNode->next;
            newNode->prev = targetNode;
            targetNode->next = newNode;
            return true; 
        }

        return false; 
    }

    ~clsDblLinkedList()
    {
        this->Clear();
    }
};