#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* orders;      
    int front, rear;  
    int size;         
    int capacity;     

public:
    
    PizzaParlor(int maxOrders) {
        capacity = maxOrders;
        orders = new int[capacity];  
        front = -1;
        rear = -1;
        size = 0;
    }

    
    ~PizzaParlor() {
        delete[] orders;
    }

    bool isFull() {
        return size == capacity;
    }

    
    bool isEmpty() {
        return size == 0;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Sorry, the pizza parlor is at full capacity. Cannot accept more orders.\n";
        } else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % capacity;  
            orders[rear] = orderID;
            size++;
            cout << "Order placed: " << orderID << endl;
        }
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
        } else {
            cout << "Serving order ID: " << orders[front] << endl;
            front = (front + 1) % capacity;  
            size--;
            if (size == 0) {
                front = -1;  
                rear = -1;
            }
        }
    }

    
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
        } else {
            cout << "Orders in the queue:\n";
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << "Order ID: " << orders[i] << endl;
                i = (i + 1) % capacity;  
            }
        }
    }
};

int main() {
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can handle: ";
    cin >> M;
    
    PizzaParlor parlor(M);
    int choice, orderID;

    while (true) {
        cout << "\nPizza Parlor Menu\n";
        cout << "1. Place an Order\n";
        cout << "2. Serve an Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Order ID: ";
                cin >> orderID;
                parlor.placeOrder(orderID);
                break;
            
            case 2:
                parlor.serveOrder();
                break;

            case 3:
                parlor.displayOrders();
                break;
            
            case 4:
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}