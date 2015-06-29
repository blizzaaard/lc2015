// #225 Implement Stack using Queues
//
// Implement the following operations of a stack using queues.
//
// push(x) -- Push element x onto stack.
//
// pop() -- Removes the element on top of the stack.
//
// top() -- Get the top element.
//
// empty() -- Return whether the stack is empty.
//
// Notes:
//
// You must use only standard operations of a queue -- which means only push to
// back, peek/pop from front, size, and is empty operations are valid.
//
// Depending on your language, queue may not be supported natively. You may
// simulate a queue by using a list or deque (double-ended queue), as long as
// you use only standard operations of a queue.
//
// You may assume that all operations are valid (for example, no pop or top
// operations will be called on an empty stack).


class Stack {

    deque<int> m_queue1;
    deque<int> m_queue2;

  public:
    // Push element x onto stack.
    void push(int x) {
        m_queue2.push_back(x);
        while (!m_queue1.empty()) {
            int tmp = m_queue1.front();
            m_queue1.pop_front();
            m_queue2.push_back(tmp);
        }
        swap(m_queue1, m_queue2);
    }

    // Removes the element on top of the stack.
    void pop() {
        m_queue1.pop_front();
    }

    // Get the top element.
    int top() {
        return m_queue1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return m_queue1.empty();
    }
};
