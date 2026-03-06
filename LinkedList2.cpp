//Insertion

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
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

    // Insert at Head
    void insertHead(int newdata)
    {
        Node *newNode = new Node(newdata);
        newNode->next = head;
        head = newNode;
    }

    // Insert at End
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

    // Insert at Position
    void insertPosition(int value, int position)
    {
        if (position < 1)
        {
            cout << "Invalid Position\n";
            return;
        }

        if (position == 1)
        {
            insertHead(value);
            return;
        }

        Node *newNode = new Node(value);
        Node *temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
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

    list.insertHead(4);
    list.insertHead(3);
    list.insertHead(2);

    list.printList();

    list.insertHead(1);
    list.insertEnd(20);
    list.insertPosition(15, 2);

    list.printList();

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
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
    void insertHead(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value)
    {

        Node *newNode = new Node(value);
        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertPosition(int value, int pos)
    {
        Node *newNode = new Node(value);

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printlist()
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
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    list.printlist();

    list.insertEnd(5);

    list.insertPosition(100, 3);

    list.printlist();

    return 0;
}
*/