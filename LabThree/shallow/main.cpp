#include <iostream>

using namespace std;

class Stack {
private:
    int *arr;
    int Size;
    int t;

public:
    Stack(int _Size, int _t) {
        cout<<"Constructor"<<endl;
        Size = _Size;
        t = _t;
        arr = new int[Size];
    }

    int getSize() {
        return Size;
    }

    int getT() {
        return t;
    }

    void push(int data) {
        if (t == Size - 1) {
            cout << "Sorry, Stack is Full!" << endl;
        } else {
            t++;
            arr[t] = data;
        }
    }

    int pop() {
        if (t == -1) {
            cout << "Sorry, Stack is empty!" << endl;
        } else {
            int x = arr[t];
            t--;
            return x;
        }
    }

    ~Stack() {
        cout<<"DEConstructor"<<endl;
        delete[] arr;
    }
};//endClass

int main() {

    Stack s1(10, -1);
    s1.push(5);
    s1.push(10);
    s1.push(20);
    int c=s1.pop();
    cout<<c<<endl;
    int h=s1.pop();
    cout<<h<<endl;
    return 0;
}
