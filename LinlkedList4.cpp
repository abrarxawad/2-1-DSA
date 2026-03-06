// deletion
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    void insertEnd(int value)
    {
        Node *newNode = new Node(value);
        Node *temp = head;

         if (head == nullptr)
        {
            head = newNode;
            return;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteHead()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd()
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deletePosition(int pos)
    {
        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertEnd(50);

    list.printList();

    list.deleteEnd();
    list.deleteHead();
    list.deletePosition(2);

    list.printList();

    return 0;
}
