#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class StackLinkedList
{
private:
    Node *top;
    Node *head;

public:
    StackLinkedList()
    {
        top = NULL;
        head = NULL;
    }
    void push(int x);
    int pop();
    bool isEmpty();
    bool isFull();
    int stackTop();
    void display();
};

int StackLinkedList::stackTop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow";
        return NULL;
    }
    else
    {
        return top->data;
    }
}

void StackLinkedList::display()
{
    if (isEmpty())
    {
        cout << "Stack Underflow";
    }
    else
    {
        Node *temp = head;
        while (temp != top)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << top->data << endl;
    }
}

void StackLinkedList::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow";
    }
    else
    {
        Node *temp = new Node(x);
        if (isEmpty())
        {

            top = temp;
            head = temp;
        }
        else
        {
            top->next = temp;
            top = temp;
        }
    }
}

int StackLinkedList::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int data = top->data;
        if (head == top)
        {
            head = top = NULL;
        }
        else
        {
            Node *temp = head;
            while (temp->next != top)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            top = temp;
        }
        return data;
    }
}

bool StackLinkedList::isEmpty()
{
    return top == NULL;
}

bool StackLinkedList::isFull()
{
    // Here we check if the heap is full.
    Node *temp = new Node(0);
    return !temp;
}

int test()
{
    StackLinkedList stack = StackLinkedList();
    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);
    stack.display();
    return 0;
}

double getExecutionTime()
{
    auto start = high_resolution_clock::now();
    test();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();
}

int main()
{   
    int time = getExecutionTime();
    cout << "Execution Time: " << time << endl;
    return 0;
}
