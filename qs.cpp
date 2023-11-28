#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int s, int e){
    int pivot = arr[e];
    int pIndex = s;
    for(int i = s; i < e; i++){
        if(arr[i] < pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[e], arr[pIndex]);
    return pIndex;
}

void QuickSort(vector<int>& arr, int s, int e){
    if(s < e){
        int p = partition(arr, s, e);
        QuickSort(arr, s, p - 1);
        QuickSort(arr, p + 1, e);
    }
}

int generateNumber(int minRange, int maxRange){
    return minRange + rand() % (maxRange - minRange + 1);
}

int main(){
    int size;
    cout << "Enter the size of the array:" << endl;
    cin >> size;

    vector<int> temp(size);
    for(int i = 0; i < size; i++){
        temp[i] = generateNumber(0, size);
    }

    clock_t endTime;
    clock_t startTime = clock();
    QuickSort(temp, 0, size - 1);
    endTime = clock();
    double duration = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Sorted array:" << endl;
    for(int i = 0; i < size; i++){
        cout << temp[i] << " ";
    }
    cout << endl;

    cout << "Time taken for Quick sort: " << duration << " seconds" << endl;

    return 0;
}
