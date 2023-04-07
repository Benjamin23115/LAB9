#pragma once
#include <sstream>
using std::stringstream;

template <typename TYPE>
class LinkedList : public List<TYPE>
{
private:
    struct Node
    {
        TYPE data;
        Node *next;
        Node(TYPE item) : data(item), next(nullptr) {}
    };
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    LinkedList() : head(nullptr), size(0) {}
    void insert(TYPE item, int index)
    {
        Node *temp = new node(item);
        if (head == nullptr)
        {
            head = temp;
            return head;
        }
        else if (index == 0)
        {
            temp->next = head;
            head = temp;
            return head;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            return head;
        }
    }
    void remove(int index)
    {
        if (head == nullptr)
        {
            stringstream sstream;
            sstream << "Index " << index << " is out of bounds";
            string msg;
            getline(sstream, msg);
            throw IndexOutOfBounds(msg);
        }
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        for (int i = 0; current != nullptr && i < index - 1; i++)
            current = current->next;
        if (current == nullptr || current->next == nullptr)
            return;
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    TYPE at(int index)
    {
        if (index < 0 || index >= size)
        {
            stringstream sstream;
            sstream << "Index " << index << " is out of bounds";
            string msg;
            getline(sstream, msg);
            throw IndexOutOfBounds(msg);
        }
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            if (count == index)
                return break;
            count++;
            current = current - next;
        }
        return current->data;
    }

    void sort(int (*cmp)(const TYPE &item1, const TYPE &item2), bool doQuicksort)
    {
    }

    int search(TYPE item, int (*cmp)(const TYPE &item1, const TYPE &item2))
    {
        Node *current = head;
        int index = 0;
        while (current != nullptr)
        {
            if (cmp(item, current->data) == 0)
                return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    int getSize()
    {
        return tail;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};
