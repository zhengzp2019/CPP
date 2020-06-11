#ifndef _STACK_H
#define _STACK_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class stack
{
private:
    vector<string> _stack;

public:
    stack();
    ~stack();
    bool empty();
    bool full();
    int size()
    {
        cout << "this is size of stack\n";
        return _stack.size();
    }
    bool push(const string &);
    bool pop(string &elem);
    bool top(string &elem);
};

stack::stack()
{
}

stack::~stack()
{
}

#endif