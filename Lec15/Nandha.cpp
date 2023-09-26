#include<iostream>
#include<stdlib.h>
using namespace std;

#define Max_size 20
int top = -1;
int Stack[Max_size];

void push(int value)
{
    top++;
    Stack[top] = value;
}
void display()
{

    for(int i = top ; i>=0; i--)
    {
        cout<<Stack[i]<<" ";
    }
    cout<<endl;
}
void pop()
{   
    if(top ==-1)
    {
        cout<<"Stack is empty";
    }
    else{
    int temp;
    temp  = Stack[top];
    cout<<"Top element is "<<temp<<endl;
    top--;}
}
int main()
{
    int n;cin>>n;
    if(n>=1 || n<=20)
    {
        if(n==0)
        {
            cout<<"Stack is empty";
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                int num;cin>>num;
                push(num);
            }
            display();
            pop();
            display();
            pop();
        }
    }
}
