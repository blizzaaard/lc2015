// #155 Min Stack
//
// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.
//
// push(x) -- Push element x onto stack.
//
// pop() -- Removes the element on top of the stack.
//
// top() -- Get the top element.
//
// getMin() -- Retrieve the minimum element in the stack.


#include <iostream>
#include <stack>

class MinStack {

    std::stack<int> elements;
    std::stack<int> mins;

  public:
    void push(int x)
    {
        if (mins.empty() || x <= mins.top()) {
            mins.push(x);
        }
        elements.push(x);
    }

    void pop()
    {
        if (elements.empty()) {
            return;
        }
        if (elements.top() == mins.top()) {
            mins.pop();
        }
        elements.pop();
    }

    int top()
    {
        if (elements.empty()) {
            return -1;
        }
        return elements.top();
    }

    int getMin()
    {
        if (mins.empty()) {
            return -1;
        }
        return mins.top();
    }
};
