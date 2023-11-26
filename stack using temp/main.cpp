#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:
    T *arr;
    int Size;
    T t;

public:
    Stack(int _Size, T _t) {
        cout << "Constructor" << endl;
        Size = _Size;
        t = _t;
        arr = new T[Size];
    }

    int getSize() {
        return Size;
    }

    T getT() {
        return t;
    }

    void push(T data) {
        if (t == Size - 1) {
            cout << "Sorry, Stack is Full!" << endl;
        } else {
            t++;
            arr[t] = data;
        }
    }

    T pop() {
        if (t == -1) {
            cout << "Sorry, Stack is empty!" << endl;
            return T(); // Return a default value if the stack is empty
        } else {
            T x = arr[t];
            t--;
            return x;
        }
    }

    ~Stack() {
        cout << "DEConstructor" << endl;
        delete[] arr;
    }
}; // endClass

int main() {
    Stack <int> s1(10, -1);
    Stack <int> s2(5,-1);
    s1.push(5);
    s1.push(10);
    s1.push(20);
    s2.push(7);
    s2.push(2.5);
    s2.push(5.25);
    int c = s1.pop();
    cout << c << endl;
    int h = s1.pop();
    cout << h << endl;
    int c2 = s2.pop();
    cout << c2 << endl;
    return 0;
}
