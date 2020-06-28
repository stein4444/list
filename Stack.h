#pragma once
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

//Defining Class
class Stack
{
    Node* top;
public:
    Stack();
    bool isEmpty();
    void push(int value);
    void pop();
    void Peek();
};

