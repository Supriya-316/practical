#include <iostream>
using namespace std;

class Queue {
    public:
    const static int size = 5 ;
    int queue[size];
    int front = -1;
    int rear = -1;
    
    
    bool isFull(){
        return(rear == size -1);
    }
    
    bool isEmpty(){
        return(rear == front);
    }
    
    
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue is full"<<endl;
        }else{
            rear ++;
            queue[rear] = value;
            cout<<"Enqueued job:"<< value << endl;
            
        }
    }
    
    void dequeue(){ 
        if (isEmpty()){
            cout<<"Can't perform Dequeue operation as queue is empty"<<endl;
        }else {
            int frontvalue= queue[front];
            if (front==rear){
                front = rear =-1;
            }else{
                front++;
            }
            cout<<"Dequeued element is :"<< frontvalue<<endl;
        }
        
    }
    
        
        void display(){
            
        if (isEmpty()){
            cout << "Queue is empty." << endl;
        }else
        {cout << "Jobs in Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        }
        }
        
};




int main()
{
    Queue q;
    int data;
    int choice;

    cout << "MENU\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit"<<endl;

    while (true)
    {
        cout << "\n\nEnter Your Input Here (1/2/3 or to exit 0)-> ";
        cin >> choice;

        switch (choice)
        {
            case 0:
                cout << "Exit!" << endl;
                return 0;
            case 1:
                cout << "Enter the data to be inserted: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            default:
                cout << "Invalid Case" << endl;
                break;
        }
    }

    return 0;
}

