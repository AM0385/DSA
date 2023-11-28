#include<iostream>

using namespace std;

int stack[100],n=100,top=-1;

void push(int val){
    if(top>n-1){
        cout<<"stack Overflow"<<endl;
    }
    else{
        stack[top]=val;
        top++;
    }
}
int pop(){
    if(top<=-1){
        cout<<"stack Underflow"<<endl;
    }
    else{
        cout<<"Removed Element is:"<<stack[top];
        top--;
    }
}
void display(){
    if(top>=0){
        cout<<"Th elements are:"<<endl;
        for(int i=top;i>0;i--){
            cout<<stack[i]<<" ";
        }
    }
}
int main(){

    int ch,val;
    cout<<"1)push in stack"<<endl;
    cout<<"2)pop in stack"<<endl;
    cout<<"3)display in stack"<<endl;
    cout<<"4)exit in stack"<<endl;
    do{
        cout<<"ENter your choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:{
                cout<<"Enter the value to be pushed"<<endl;
                cin>>val;
                push(val);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                cout<<"EXIT"<<endl;
                break;
            }
            default: {
                cout<<"wrong input"<<endl;
                break;
            }
        }
    }while(ch!=4);
    return 0;
}
