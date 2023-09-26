#include<iostream>
#include<stdlib.h>
#define Max_Size 100
using namespace std;

int stack[Max_Size];
int top = -1;

void push(int value)
{
    top++;
    stack[top] = value;
    cout<<"Element "<<value<<" pushed onto the stack."<<endl;
}
void pop()
{
    if(top == -1)
    {
        cout<<"Stack Underflow. Cannot perform pop operation."<<endl;
    }
    else
    {
        int temp = stack[top];
        top--;
        cout<<"Element "<<temp<<" popped from the stack."<<endl;
    }
}
void display()
{
    if(top == -1)
    {
        cout<<"Stack is empty."<<endl;
    }
    else
    {
        cout<<"Elements in the stack: ";
        for(int i=top; i>=0;i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}
void Exit()
{
    cout<<"Exiting the program."<<endl;
}
int main()
{
    bool start = true;
    while(start)
    {
        int choice;cin>>choice;
        if(choice == 1)
        {
            int data;cin>>data;
            push(data);
        }
        else if(choice == 2)
        {
            pop();
        }
        else if(choice == 3)
        {
            display();
        }
        else if(choice == 4)
        {
            Exit();
            start = false;
        }
        else
        {
            cout<<"Invalid choice."<<endl;
        }
    }
}
