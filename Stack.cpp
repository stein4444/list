#include"Stack.h"

Stack::Stack()
{
    top = NULL;
}
void Stack::push(int value)
{
    Node* ptr = new Node();
    ptr->data = value;
    ptr->next = top;
    top = ptr;
}


bool Stack::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node* temp = top;
        top = top->next;
        delete(temp);
    }
}
void Stack::Peek()
{
    if (isEmpty())
    {
        cout << "Stack Is Empty" << endl;
    }
    else
    {
       top->data;
    }
}

