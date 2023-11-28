#include<iostream>
#include<ctime>
#include<windows.h>
#include<vector>
using namespace std;

void QuickSort(int arr[],int s, int e){
    int p= partition(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}
int partition(int arr[], int s, int e){
    int pivot= arr[e];
    int pIndex=s;
    for(int i=0;i<e-1;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[e],arr[pIndex]);
    return pIndex;
}
int generateNumber(int minRange, int maxRange){
    return minRange+rand()%(maxRange -minRange+1);
}

int main(){

    int size;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    int temp[size];
    for(int i=0;i<=size;i++){
        temp[i]=generateNumber(0,size);
    }
    clock_t endTime;
    clock_t startTime=clock();
    QuickSort(temp,0,size);
    endTime=clock();
    double duration=(endTime-startTime);


}