#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class StackArray
{
private:
    int top = -1;
    int size;
    int *arr;

public:
    StackArray(int sz = 10)
    {
        arr = new int[sz];
        size = sz;
    }
    void push(int x);
    int pop();
    bool isEmpty();
    bool isFull();
    int stackTop();
    void display();
};

int StackArray::stackTop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return NULL;
    }
    else
    {
        return arr[top];
    }
}

void StackArray::display()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        for (int i = 0; i < top + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void StackArray::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

int StackArray::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        top--;
        return arr[top + 1];
    }
}

bool StackArray::isEmpty()
{
    return top == -1;
}

bool StackArray::isFull()
{
    return top >= size;
}

int test(int size)
{
    StackArray stack = StackArray(size);
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

double getExecutionTime(int size)
{
    auto start = high_resolution_clock::now();
    test(size);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();
}

int main()
{
    int size;
    cout << "Enter a stack size: ";
    cin >> size;
    int time = getExecutionTime(size);
    cout << "Execution Time: " << time << endl;
    return 0;
}
