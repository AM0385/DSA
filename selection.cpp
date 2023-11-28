#include <iostream>
using namespace std;

void selection(int arr[]){
    for(int i=0;i<4;i++){
        int min=i;
        for(int j=i+1;j<5;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}

int main(){
    int myArr[5];
    cout<<"Enter 5 elements:"<<endl;
    for(int i=0;i<5;i++){
        cin>>myArr[i];
    }
    selection(myArr);
    cout<<"sortedArray:"<<endl;
    for(int i=0;i<5;i++){
        cout<<myArr[i]<<" ";
    }
    cout<<endl;
}