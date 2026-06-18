#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

    // Helper function to shift elements when output stack is empty
    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
        // Stacks initialize automatically
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from in front of queue and returns it.
    int pop() {
        shiftStacks();
        int frontElement = output.top();
        output.pop();
        return frontElement;
    }
    
    // Get the front element.
    int peek() {
        shiftStacks();
        return output.top();
    }
    
    // Returns whether the queue is empty.
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */