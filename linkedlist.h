#pragma once
#include <sstream>
#include <iomanip>

using std::stringstream;

template <typename TYPE>
class LinkedList : public List<TYPE>
{
private:
    struct Node
    {
        TYPE data;
        Node *next;
        //This assignment was what made me kinda further understand how constructors work and deconstructors
        //When you add multi-file programming on top of a subject I don't really understand yet (OOP) my brain starts to poop itself
        //At first I tackled trying to handle edge cases in each function but then I realized thats stupid and a waste of time so I just decided to deal with edge cases on things that would make sense (atleast to me 😎)
        Node(TYPE item) : data(item), next(nullptr) {}
    };
    Node *head = nullptr;
    int size;
    // Although I would like to reference all the stuff I used as guides, there is way too many things to write down. Mainly used geeksforgeeks as reference,
    // onlinegdb.com to debug my code cause vs enterprise is too complicated and im too lazy to learn a new IDE
public:
    LinkedList() : head(nullptr), size(0) {}
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
    void insert(TYPE item, int index)
    // this stupid function is the reason that i pulled out so many hairs
    {

        if (index == 0 || index == -1)
        {
            Node *temp = new Node(item);
            temp->next = head;
            head = temp;
            size++;
        }
        else if (index > 0 && index <= size)
        {
            {
                Node *temp = new Node(item);
                Node *current = head;

                for (int i = 0; i < index - 1; i++)
                {
                    current = current->next;
                }
                temp->next = current->next;
                current->next = temp;
                size++;
            }
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
        Node *current = head;
        for (int count = 0; count < index; count++)
        {
            current = current->next;
        }
        return current->data;
    }
    friend Node *getNextPointer(Node *node)
    // Had to create this function because I was too lazy to change the private parts of the Node to public + I don't we should be doing that regardless
    {
        return node->next;
    }
    void sort(int (*cmp)(const TYPE &item1, const TYPE &item2), bool doQuicksort)
    { // Using this stupid int (*cmp) blah blah blah part of the function made my brain hurt because of the address of operators and pointer

        if (size == 0)
            return;

        if (doQuicksort)
        {
        }
        else
        {
            bool swapped;
            do
            {
                swapped = false;
                Node *prev = head;
                Node *curr = getNextPointer(prev);

                while (curr != nullptr)
                {
                    if (cmp(curr->data, prev->data) == -1)
                    {
                        // Swap nodes
                        prev->next = curr->next;
                        curr->next = head;
                        head = curr;
                        swapped = true;
                    }
                    else
                    {
                        prev = prev->next;
                    }
                    curr = prev->next;
                }
            } while (swapped);
        }
    }
    int search(TYPE item, int (*cmp)(const TYPE &item1, const TYPE &item2))
    {
        Node *current = head;
        for (int index = 0; index < size; index++)
        {
            if (cmp(item, current->data) == 0)
                return index;
            current = current->next;
        }
        return -1;
    }
    int getSize()
    {
        return size;
    }
};
