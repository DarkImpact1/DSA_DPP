
/*
You are tasked with implementing a ticketing system for a concert event using a 
queue using a linked list data structure. The program should store ticket numbers 
in a queue and display them in a zigzag pattern. The program should prompt the 
user to enter the capacity of the ticket queue and allow them to enqueue ticket 
numbers until they enter -1 to stop. After enqueueing, the program should display 
the ticket numbers in the zigzag pattern.*/

#include <iostream>
using namespace std;
#define size 100
int myQueue[size];
int  top=0;

void push(int data)
{
    
    myQueue[top]=data;
    // cout<<data<<" inserted at "<<top<<endl;
    top++;
}

int main() {
    

    int num;
    cin>>num;
    if(num>0)
    {
        int myQueue[num];
    }
    else
    {
        cout<<"capacity should be positive :"<<endl;
    }
    int i=0;
    while (true && i<num) 
    {
        int value;
        cin>>value;
        if (value == -1) {
            break;
        }
        if(value>0)
        {
        push(value);
        }
    }
    int front=0, back=top-1;
    while(back>front)
    {
        cout<<myQueue[front]<<" ";
        // cout<<"front "<<front<<endl;
        front++;
        cout<<myQueue[back]<<" ";
        // cout<<"back "<<back<<endl;
        back--;
    }
    if((top-1)%2==0)
    {
        back = (top-1)/2;
        cout<<myQueue[back]<<" ";
        // cout<<"back "<<back<<endl;
    }

    return 0;
}
