//Created on ...24/6/22
#include <iostream>
#include <stack>
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false

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