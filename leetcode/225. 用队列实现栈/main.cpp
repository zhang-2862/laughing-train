#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        que_.push(x);
    }

    int pop() {
        while (que_.size() > 1) {
            backup_que_.push(que_.front());
            que_.pop();
        }
        int temp = que_.front();
        que_.pop();
        que_ = backup_que_;
        while (!backup_que_.empty()) {
            backup_que_.pop();
        }
        return temp;
    }

    int top() {
        while (que_.size() > 1) {
            backup_que_.push(que_.front());
            que_.pop();
        }
        int temp = que_.front();
        backup_que_.push(que_.front());
        que_ = backup_que_;
        while (!backup_que_.empty()) {
            backup_que_.pop();
        }
        return temp;
    }

    bool empty() {
        return que_.empty();
    }

private:
    queue<int> que_;
    queue<int> backup_que_;
};

class MyStackSingleQueue {
public:
    MyStackSingleQueue() {

    }

    void push(int x) {
        que_.push(x);
    }

    int pop() {
        size_t size = que_.size();
        size--;
        while (size--) {
            int temp = que_.front();
            que_.pop();
            que_.push(temp);
            // 或者用下面方式
//            que_.push((que_.front()));
//            que_.pop();
        }
        int temp = que_.front();
        que_.pop();
        return temp;
    }

    int top() {
        size_t size = que_.size();
        int temp = 0;
        while (size--) {
            temp = que_.front();
            que_.pop();
            que_.push(temp);
        }
        return temp;
    }

    bool empty() {
        return que_.empty();
    }

private:
    queue<int> que_;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 void test() {
    MyStack* obj = new MyStack();
    obj->push(6);
    obj->push(7);
    // obj->push(8);
    int param_2 = obj->top();
    int param_3 = obj->pop();
    int param_4 = obj->pop();
    bool param_5 = obj->empty();
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    cout << param_5 << endl;
    delete obj;
 }

void test01() {
    MyStackSingleQueue* obj = new MyStackSingleQueue();
    obj->push(6);
    obj->push(7);
    // obj->push(8);
    int param_2 = obj->top();
    int param_3 = obj->pop();
    int param_4 = obj->pop();
    bool param_5 = obj->empty();
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
    cout << param_5 << endl;
    delete obj;
}

int main() {

    test();
    cout << "---------" << endl;
    test01();

    return 0;
}
