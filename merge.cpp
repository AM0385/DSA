#include<iostream>
#include<ctime>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1]; // Use dynamic allocation for temporary array

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int p = l, q = 0; p <= r; ++p, ++q) {
        arr[p] = temp[q];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
         int m = (l + r) / 2;
         mergeSort(arr, l, m);
         mergeSort(arr, m + 1, r);
         merge(arr, l, m, r);
    }
}

int generateNumber(int minRange, int maxRange){
    return minRange + rand() % (maxRange - minRange + 1);
}

int main(){
    int size = 0;
    cout << "Enter the size of the array:" << endl;
    cin >> size;

    srand(time(0));
    int arr[size];
    for(int i = 0; i < size; ++i){
        arr[i] = generateNumber(0, size);
    }

    clock_t endTime;
    clock_t startTime = clock();
    mergeSort(arr, 0, size - 1);
    endTime = clock();
    double duration = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Sorted array:" << endl;
    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken for merge sort: " << duration << " seconds" << endl;

    return 0;
}
