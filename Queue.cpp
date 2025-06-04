#include<iostream>
using namespace std;

class Queue {
    int front, rear, capacity;
    int *arr;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->front = this->rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void Enqueue(int data);
    int Dequeue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();
    int size();
    void Display();
};

bool Queue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool Queue::isFull() {
    return (rear == capacity - 1);
}

int Queue::size() {
    if (isEmpty())
    {
        cout << "Queue is Empty." << endl;
    }
    else
    {
        return rear - front + 1;
    }
}

void Queue::Enqueue(int data) {
    if (isFull()) {
        cout << "Queue is FULL" << endl;
        return;
    }

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[front] = arr[rear] = data;
    }
    else
    {
        rear++;
        arr[rear] = data;
    }
}

int Queue::Dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Dequeued Element : " <<arr[front]<< endl;
        return arr[front++];
    }
}

int Queue::Front() {
    if (isEmpty())
    {
        cout << "Queue is Empty." << endl;
    }
    else
    {
        return arr[front];
    }
}

int Queue::Rear() {
    if (isEmpty())
    {
        cout << "Queue is Empty." << endl;
    }
    else
    {
        return arr[rear];
    }
}

void Queue::Display() {
    if (isEmpty()) {
        cout << "Queue is Underflow!" << endl;
        return;
    }

    cout << "Queue is: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice,n;
    cout<<"Enter Size Of Queue : ";
    cin>>n;
    
    Queue q(n);
    
    do
    {
        cout<<endl<<"-----------------------"<<endl;
        cout<<"1. Enqueue."<<endl;
        cout<<"2. Dequeue."<<endl;
        cout<<"3. Check Queue is Empty."<<endl;
        cout<<"4. Check Queue is Full."<<endl;
        cout<<"5. Display Front Elmenent"<<endl;
        cout<<"6. Display Rear Element"<<endl;
        cout<<"7. Queue Size."<<endl;
        cout<<"8. Display Queue."<<endl;
        cout<<"0. EXIT!"<<endl;
        cout<<"Enter Your Choce : ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                int data;
                cout<<"Enter Data : ";
                cin>>data;
                q.Enqueue(data);
                break;
            case 2:
                q.Dequeue();
                break;
            case 3:
                if (q.isEmpty())
                {
                    cout<<"Queue is Empty."<<endl;
                }
                else
                {
                    cout<<"Queue Not Empty."<<endl;
                }
                break;
            case 4: 
                if (q.isFull())
                {
                    cout<<"Queue is FULL."<<endl;
                }
                else
                {
                    cout<<"Queue Not FULL."<<endl;
                }
                break;
            case 5:
                cout<<"Top Element : "<< q.Front()<<endl;
                break;
            case 6:
                cout<<"Rear Element : "<< q.Rear()<<endl;
                break;
            case 7:
                cout << "Current Queue Size: " << q.size() << endl;
                break;
            case 8:
                q.Display();    
                break;
            case 0:
                cout<<"Code Exited."<<endl;
                break;
            default:
                cout<<"Wrong choice .."<<endl;
                break;
        }
        
    }while(choice != 0);

    return 0;
}