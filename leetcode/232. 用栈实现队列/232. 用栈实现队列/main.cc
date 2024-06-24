//Created on ...24/6/22
#include <iostream>
#include <stack>
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false

using namespace std;
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stack_in.push(x);
    }

    int pop() {
        int ret = 0;
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                int top_element = stack_in.top();
                stack_in.pop();
                stack_out.push(top_element);
            }
        }
        ret = stack_out.top();
        stack_out.pop();
        return ret;
    }

    int peek() {
        int ret=this->pop();
        stack_out.push(ret);
        return ret;
    }

    bool empty() {
        if (stack_in.empty() && stack_out.empty()) {
            return true;
        } else {
            return false;
        }
    }
private:
    stack<int> stack_in;
    stack<int> stack_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
    MyQueue* obj = new MyQueue();
    int x;
    cin >> x;
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    return 0;
}