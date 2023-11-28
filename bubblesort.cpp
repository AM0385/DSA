#include<iostream>
using namespace std;
void bubble(int arr[]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int myArr[5];
    cout<<"Enter 5 elements:"<<endl;
    for(int i=0;i<5;i++){
        cin>>myArr[i];
    }
    bubble(myArr);
    cout<<"sortedArray:"<<endl;
    for(int i=0;i<5;i++){
        cout<<myArr[i]<<" ";
    }
    cout<<endl;
}