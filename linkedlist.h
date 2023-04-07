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
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), size(0) {}
    void insert(TYPE item, int index)
    {
    }
    // The following function prototype is inspired from https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
    void remove(int index)
    {
        if (*head == NULL)
        {
            stringstream sstream;
            sstream << "Index " << index << " is out of bounds";
            string msg;
            getline(sstream, msg);
            throw IndexOutOfBounds(msg);
        }
        Node *newNode = *head;
        if (index == 0)
        {
            *head = temp->next;
            free(temp);
            return;
        }
        for (int i = 0; temp != NULL && i < index - 1; i++)
            temp = temp->next;
        if (temp == NULL || temp->next == NULL)
            return;
        Node *next = temp->next->next;
        free(temp->next);
        temp->next = next;
    }

    TYPE at(int index)
    {
        if (index < 0 || index > size)
        {
            stringstream sstream;
            sstream << "Index " << index << " is out of bounds";
            string msg;
            getline(sstream, msg);
            throw IndexOutOfBounds(msg);
        }
        int count = 0;
        Node *current = head;
        while (current.next != NULL)
        {
            current = current.next;
            count++;
            if (count == index)
                break;
        }
        return current->data;
    }

    void sort(int (*cmp)(const TYPE &item1, const TYPE &item2), bool doQuicksort)
    {
    }

    int search(TYPE item, int (*cmp)(const TYPE &item1, const TYPE &item2))
    {
        int count = 0;
        Node *current = head;
        while (current.next != NULL)
        {
            current = current.next;
            count++;
            if (count == index)
                break;
        }
        return index;
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
