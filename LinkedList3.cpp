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

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 🔹 1. Delete at Head
    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // 🔹 2. Delete at End
    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        // If only one node
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // 🔹 3. Delete at Position
    void deletePosition(int position)
    {
        if (head == nullptr || position < 1)
        {
            cout << "Invalid operation\n";
            return;
        }

        if (position == 1)
        {
            deleteHead();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < position - 1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Original List: ";
    list.printList();

    list.deleteHead();
    cout << "After deleting head: ";
    list.printList();

    list.deleteEnd();
    cout << "After deleting end: ";
    list.printList();

    list.deletePosition(2);
    cout << "After deleting position 2: ";
    list.printList();

    return 0;
}