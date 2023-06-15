#include <iostream>
using namespace std;

template<typename Type>
class MyStack {
private:
    unsigned int maxNumberElements;
    unsigned int numberElements = 0;
    Type* stack;
public:
    MyStack(unsigned int size) {
        maxNumberElements = size;
        stack = new Type[size];
    }
    
    ~MyStack() {
        delete[] stack;
    }

    int size() {
        return numberElements;
    }
    bool empty() {
        return numberElements == 0;
    }

    void push(Type element) {
        if (numberElements < maxNumberElements) {
            stack[numberElements] = element;
            numberElements++;
        }
        else
            throw overflow_error("StackOverflow!");
    }

    Type pop() {
        if (numberElements != 0) {
            Type element = stack[numberElements - 1];
            numberElements--;
            return element;
        }
        else
            throw out_of_range("Stack is empty!");
    }
    void top() {
        if (numberElements != 0) {
            cout << stack[numberElements - 1] << endl;
        }
        else
            throw logic_error("Stack is empty!");
    }
};
int main()
{
    MyStack<int> stack(3);
    cout << "Count of number: " << stack.size()<<endl;
    cout << "Empty? " << (stack.empty()? "Yes": "No") << endl;
    for (int i = 1; i <= 3; i++)
        stack.push(i);
    cout << "Count of numbers: " << stack.size() << endl;
    cout << "Empty? " << (stack.empty() ? "Yes" : "No") << endl;
    cout << "Last element: ";
    stack.top();
    cout << "Last element: " << stack.pop() << endl;
    cout << "Last element: ";
    stack.top();
    

}
