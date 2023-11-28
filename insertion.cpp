#include<iostream>
using namespace std;

void insertion(int arr[]){
    int key,j;
    for(int i=1;i<5;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}


int main(){
    int arr[5];
    cout<<"Enter 5 elementa to be sorted"<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    insertion(arr);
    cout<<"Sorted Elements"<<endl;
    for(int i=4;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}