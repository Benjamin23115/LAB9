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
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    // The following function prototype was created based on https://www.geeksforgeeks.org/insert-a-node-at-a-specific-position-in-a-linked-list/
    void insert(TYPE item, int index)
    {
        if (index == size){
            //TODO: Implement the addition of another NODE to make the linked list bigger than the index selected

        }
        else
        {
            while (index--)
            {
                if (index == 0)
                {
                    Node *newNode = new Node(item);
                    newNode->next = head;
                    head = newNode;
                }
                else
                    head = &(*head)->next;
            }
            size++;
        }
        // if (index < 1 || index > size + 1)
        // {
        //     throw std::out_of_range("Index out of range insert");
        // }
        // Node *newNode = new Node(item);
        // if (index == 0)
        // {
        //     newNode->next = head;
        //     head = newNode;
        // }
        // else
        // {
        //     Node *prev = head;
        //     for (int i = 0; i < index - 1; i++)
        //     {
        //         prev = prev->next;
        //     }
        //     newNode->next = prev->next;
        //     prev->next = newNode;
        // }
        // size++;
    }
    // The following function prototype is inspired from https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
    void remove(int index)
    {
        if (*head == NULL){
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

        // if (index == 0 || index > size)
        // {
        //     throw std::out_of_range("Index out of range remove");
        // }
        // else if (index < 1 || index > size)
        // {
        //     throw std::out_of_range("Index out of range remove 2 ");
        // }
        // else
        // {
        //     Node *target;
        //     if (index == 0)
        //     {
        //         target = head;
        //         head = head->next;
        //     }
        //     else
        //     {
        //         Node *prev = head;
        //         for (int i = 0; i < index - 1; i++)
        //         {
        //             prev = prev->next;
        //         }
        //         target = prev->next;
        //         prev->next = target->next;
        //     }
        //     delete target;
        //     size--;
        // }
    }

    TYPE at(int index)
    {
        // Used this StackOverflow post as a starting point https://stackoverflow.com/questions/69759050/how-do-i-return-that-data-at-specific-position-if-present
        if (index < 0 || index > size){
            stringstream sstream;
            sstream << "Index " << index << " is out of bounds";
            string msg;
            getline(sstream, msg);
            throw IndexOutOfBounds(msg);
        }
        int count = 0;
        Node *current = head;
        while (current.next.next.next != null && count < index)
        {
            current = current.next;
            count++;
            if (count == index)
                break;
        }
        return current->data;
        // if (index < 0 || index > size)
        // {
        //     throw std::out_of_range("Index out of range at");
        // }
        // Node *current = head;
        // for (int i = 0; i < index; i++)
        // {
        //     current = current->next;
        // }
        // return current->data;
    }

    void sort(int (*cmp)(const TYPE &item1, const TYPE &item2), bool doQuicksort)
    {
    }

    int search(TYPE item, int (*cmp)(const TYPE &item1, const TYPE &item2))
    {
        if (index < 0 || index > size)
            throw std::out_of_range("Issue trying to find out of range index");
        int count = 0;
        Node *current = head;
        while (current.next.next.next != null && count < index)
        {
            current = current.next;
            count++;
            if (count == index)
                break;
        }
        return index;
        // Node *current = head;
        // int index = 0;
        // while (current != nullptr)
        // {
        //     if (cmp(current->data, item) == 0)
        //     {
        //         return index;
        //     }
        //     current = current->next;
        //     index++;
        // }
        // return -1;
    }

    int getSize()
    {
        return size;
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
