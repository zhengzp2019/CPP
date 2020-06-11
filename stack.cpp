#include "stack.h"
#include <iostream>
using namespace std;

bool stack::empty()
{
    cout << "this is empty member fouction\n";
    if (_stack.size() == 0)
        return true;
    else
        return false;
}

bool stack::full()
{
    cout << "this is full member founction\n";
    if (_stack.size() == _stack.max_size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::pop(string &elem)
{
    cout << "this is pop menber foundation\n";
    return true;
}

bool stack::push(const string &)
{
    cout << "this is push member founction\n";
    return true;
}

bool stack::top(string &elem)
{
    cout << "this is top member founction\n";
    return true;
}