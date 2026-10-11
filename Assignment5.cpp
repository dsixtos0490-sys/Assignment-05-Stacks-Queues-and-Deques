#include <iostream>
struct Node{
    int data;
    Node * next;
    Node * prev;
};
class Stack{
    private:
    Node * top;
    public:
    Stack(){
        top = nullptr;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    void push(int value){
        Node * newNode = new Node();
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;

    }
    int pop(){
        if(isEmpty()){
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        Node * temp = top;
        int poppedValue = top -> data;
        top = top -> next;
        delete temp;
        return poppedValue;
    }
};
class Queue{
    private:
    Node * head;
    Node * tail;
    public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void enqueue(int value){
        Node * newNode = new Node();
        newNode -> data = value;
        newNode -> next = nullptr;
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    int dequeue(){
        if(isEmpty()){
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int dequeuedValue = head -> data;
        Node * temp = head;
        head = head -> next;
        if(head == nullptr){
            tail = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }
};
class Deque{
    private: 
    Node * head;
    Node * tail;
    public:
    Deque(){
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void insertFront(int value){
        Node * newNode = new Node{value, head, nullptr};
        if(isEmpty()){
            head = newNode;
            tail = newNode;
        }
        else{
            head -> prev = newNode;
            head = newNode;
            }
        }
        void insertRear(int value){
            Node * newNode = new Node{value, nullptr, tail};
            if(isEmpty()){
                head = newNode;
                tail = newNode;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
        }
        int deleteHead(){
            if(isEmpty()){
                std::cout << "Deque is empty" << std::endl;
                return -1;
            }
            int value = head -> data;
            Node * temp = head;
            head = head -> next;
            if(head == nullptr){
                tail = nullptr;
            }
            else{
                head -> prev = nullptr;
            }
            delete temp;
            return value;
        }
        int deleteTail(){
            if(isEmpty()){
                std::cout << "Dequeue is empty" << std::endl;
                return -1;
            }
            int value = tail -> data;
            Node * temp = tail;
            tail = tail -> prev;
            if(tail == nullptr){
                head = nullptr;
            }
            else{
                tail -> next = nullptr;
            }
            delete temp;
            return value;
            }
};
class ArrayStack{
    private:
    int arr[100];
    int top;
    public:
    ArrayStack(){
        top = -1;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == 99;
    }
    void push(int value){
        if(isFull()){
            std::cout << "Stack is full" << std:: endl;
            return;
        }
        arr[++top] = value;
    }
    int pop(){
        if(isEmpty()){
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return arr[top--];
    }
};
class ArrayQueue{
    private:
    int arr[100];
    int head;
    int tail;
    int count;
    public:
    ArrayQueue(){
        head = 0;
        tail = -1;
        count = 0;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == 100;
    }
    void enqueue(int value){
        if(isFull()){
            std::cout << "Queue is full" << std:: endl;
            return;
        }
        tail = (tail + 1) % 100;
        arr[tail] = value;
        count++;
    }
    int dequeue(){
        if(isEmpty()){
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int value = arr[head];
        head = (head + 1) % 100;
        count --;
        return value;
    }
};
class ArrayDeque{
    private:
    int arr[100];
    int head; 
    int tail;
    int count;
    public:
    ArrayDeque(){
        head = 0;
        tail = 0;
        count =0;
    }
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == 100;
    }
    void insertHead(int value){
        if(isFull()){
            std::cout << "Deque is full" << std::endl;
            return;
        }
        if(isEmpty()){
            head = 0;
            tail = 0;
        }
        else{
            head = (head - 1 + 100) % 100;
        }
        arr[head] = value;
        count++;
            
    }
    void insertTail(int value){
        if(isFull()){
            std::cout << "Deque is full" << std::endl;
            return;
        }
        if(isEmpty()){
            head = 0;
            tail = 0;
        }
        else{
            tail = (tail + 1) % 100;
        }
        arr[tail] = value;
        count++;
        }
        int deleteHead(){
            if(isEmpty()){
                std::cout<<"Deque is empty"<<std::endl;
                return -1;
            }
            int value = arr[head];
            if(head == tail){
                head = 0;
                tail = 0;
            }
            else{
                head = (head + 1) % 100;
            }
            count--;
            return value;
            }
            int deleteTail(){
                if(isEmpty()){
                    std::cout<<"Deque is empty"<<std::endl;
                    return -1;
                }
                int value = arr[tail];
                if(head == tail){
                    head = 0;
                    tail = 0;
                }
                else{
                    tail = (tail - 1 + 100) % 100;
                }
                count--;
                return value;
                }
 };
 int main(){
    using namespace std;
    cout << boolalpha;
    cout << "Testing Stack" << endl;
    Stack linkedStack;
    cout << "Is stack empty? " << linkedStack.isEmpty() << endl;
    cout << "pop -> " << linkedStack.pop() << endl;

    linkedStack.push(10);
    linkedStack.push(20);
    linkedStack.push(30);
    linkedStack.push(40);
    linkedStack.push(50);
    linkedStack.push(60);
    cout << "pop -> " << linkedStack.pop() << endl;
    cout << "pop -> " << linkedStack.pop() << endl;
    cout << "pop -> " << linkedStack.pop() << endl;
    cout << "Is stack empty? " << linkedStack.isEmpty() << endl;

    cout << endl << "Testing Queue" << endl;
    Queue linkedQueue;
    cout << "Is queue empty? " << linkedQueue.isEmpty() << endl;
    cout << "dequeue -> " << linkedQueue.dequeue() << endl;
    linkedQueue.enqueue(1);
    linkedQueue.enqueue(2);
    linkedQueue.enqueue(3);
    linkedQueue.enqueue(4);
    linkedQueue.enqueue(5);
    linkedQueue.enqueue(6);
     cout << "dequeue -> " << linkedQueue.dequeue() << endl;
      cout << "dequeue -> " << linkedQueue.dequeue() << endl;
       cout << "dequeue -> " << linkedQueue.dequeue() << endl;
    cout << "Is queue empty? " << linkedQueue.isEmpty() << endl;

    cout << endl << "Testing Deque" << endl;
    Deque linkedDeque;
    cout << "Is deque empty? " << linkedDeque.isEmpty() << endl;
    cout << "deleteHead -> " << linkedDeque.deleteHead() << endl;
    linkedDeque.insertFront(12);
    linkedDeque.insertRear(22);
    linkedDeque.insertFront(2);
    linkedDeque.insertFront(0);
    linkedDeque.insertRear(32);
    cout << "deleteHead -> " << linkedDeque.deleteHead() << endl;
    cout << "deleteTail -> " << linkedDeque.deleteTail() << endl;
    cout << "Is deque empty? " << linkedDeque.isEmpty() << endl;

    cout << endl << "Testing ArrayStack" << endl;
    ArrayStack arrayStack;
    cout << "Is stack empty? " << arrayStack.isEmpty() << endl;
    cout << "pop -> " << arrayStack.pop() << endl;
    arrayStack.push(5);
    arrayStack.push(10);
    arrayStack.push(15);
    arrayStack.push(20);
    arrayStack.push(25);
    arrayStack.push(30);
    cout << "pop -> " << arrayStack.pop() << endl;
    cout << "pop -> " << arrayStack.pop() << endl;
    cout << "Is stack full? " << arrayStack.isFull() << endl;

    cout << "Testing full capacity of ArrayStack" << endl;
    for(int i = 0; i < 100; i++){
        arrayStack.push(3);
    }
    cout << "Testing ArrayQueue" << endl;
    ArrayQueue arrayQueue;
    cout << "Is queue empty? " << arrayQueue.isEmpty() << endl;
    cout << "dequeue -> " << arrayQueue.dequeue() << endl;
    arrayQueue.enqueue(3);
    arrayQueue.enqueue(6);
    arrayQueue.enqueue(9);
    arrayQueue.enqueue(12);
    arrayQueue.enqueue(15);
    arrayQueue.enqueue(18);
    cout << "dequeue -> " << arrayQueue.dequeue() << endl;
    cout << "dequeue -> " << arrayQueue.dequeue() << endl;
    cout << "Is queue full? " << arrayQueue.isFull() << endl;





    
 }

    
