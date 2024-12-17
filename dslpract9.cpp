#include <iostream>
#include <string>
using namespace std;

class Stack{
    private:
    int top = -1;
    string str="level";
    const static int size = 10;
    char rev_str[size]="";
    
    public:
    
    void display(){
        cout << "\nOriginal String:"<<str<<endl;
        cout <<"\nReversed String:"<< rev_str<<endl;
        
    }
    
    int isEmpty(){
        return(top==-1);
    }
    
    int isFull(){
        return(top== size- 1);
    }
    
    void push (char x){
        if (isFull()){
            cout << "Stack overflow"<<endl;
        }else{
            top++;
            rev_str[top]= x;
        }
    }
    
    void reverse(){
        for (int i=str.length()-1;i>=0;i--){
            push(str[i]);
            
        }
    }
    
    void isPalindrome(){
        if(str == rev_str){
            cout<<"String is Palindrome"<<endl;
        }else{
            cout<< "String is not Palindrome"<<endl;
            
        }
    }

};
    

int main() {
    Stack s;
    s.display();
    s.reverse();
    s.display();
    s.isPalindrome();
    
    
    return 0;
}

