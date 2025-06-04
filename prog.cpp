#include<iostream>
using namespace std;

class Stack{
protected:
    int *arr;
    int top;
    int capacity;
    
public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity];
        this->top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    
};

class Operation : public Stack{
public:
    Operation(int size) : Stack(size) {}

    void push(int data)
    {
        if(this->isFull())
        {
            cout<<"Stack is Full."<<endl;
        }
        else
        {
           this->top++;
           this->arr[this->top] = data; 
        }
    }
    void pop()
    {
        if(this->isEmpty())
        {
            cout<<"Stack is Empty."<<endl;
        }
        else
        {
            cout << "Popped element: " << this->arr[this->top] << endl;
            this->top--;
        }
    }
    int Top()
    {
        return this->arr[top];
    }
    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top ==this->capacity - 1;
    }

    void Display()
    {
        if(this->isEmpty())
        {
            cout<<"Stack is Empty."<<endl;
        }
        else
        {
            cout<<"Stcak is : ";
            for (int i = 0; i <= this->top; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            
        }
    }
};

int main()
{
    int size;
    cout<<"Enter Size Of Stack : ";
    cin>>size;
    Operation stack(size);
    int choice;
    do
    {

        cout<<endl<<"-----------------------"<<endl;
        cout<<"1. Push Data."<<endl;
        cout<<"2. pop Data."<<endl;
        cout<<"3. Check Stack is Empty."<<endl;
        cout<<"4. Check Stack is Full."<<endl;
        cout<<"5. Display Top Elmenent"<<endl;
        cout<<"6. Display Stack."<<endl;
        cout<<"7. EXIT!"<<endl;
        cout<<"Enter Your Choce : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int data;
                cout<<"Enter Data : ";
                cin>>data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if (stack.isEmpty())
                {
                    cout<<"Stack is Empty."<<endl;
                }
                else
                {
                    cout<<"Stack Not Empty."<<endl;
                }
                
                break;
            case 4: 
                if (stack.isFull())
                {
                    cout<<"Stack is FULL."<<endl;
                }
                else
                {
                    cout<<"Stack Not FULL."<<endl;
                }
                break;
            case 5:
                cout<<"Top Element : "<< stack.Top()<<endl;
                break;
            case 6:
                stack.Display();
                break;
            case 0: 
                break;
            default :
                break;
        }
    } while (choice != 0);
    

    return 0;
}