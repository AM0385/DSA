
#include <iostream>
#include <vector>

using namespace std;

void printParenthesis(vector<vector<int>> &bracket, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParenthesis(bracket, i, bracket[i][j]);
    cout << "*"; 
    printParenthesis(bracket, bracket[i][j] + 1, j);
    cout << ")";
}

int solve(vector<int> &arr, int i, int j, vector<vector<int>> &costTable, vector<vector<int>> &bracket) {
    if(i==j) {
        return 0;
    }
    if(costTable[i][j] != -1) {
        return costTable[i][j];
    }
    int mincost = INT32_MAX;
    int minK = -1;
    for(int k = i; k < j; k++) {
        int temp = solve(arr, i, k, costTable, bracket) 
                + solve(arr, k+1, j, costTable, bracket) 
                + arr[i-1]*arr[k]*arr[j];
        if(temp < mincost) {
            mincost = temp;
            minK = k;
        }
        costTable[i][j] = mincost;
        bracket[i][j] = minK;
    }

    return mincost;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    int i = 1;
    int j = N-1;
    vector<vector<int>> costTable(N, vector<int>(N, -1));
    vector<vector<int>> bracket(N, vector<int>(N, -1));
    int minCost = solve(arr, i, j, costTable, bracket);
    cout << "Minimum Cost: " << minCost << endl;
    cout << "Optimal Parenthesization: ";
    printParenthesis(bracket, i, j);
    return minCost;
}

int main() {
    vector<int> dimensions = {3, 1, 4, 5, 4};
    matrixMultiplication(dimensions, dimensions.size());
    return 0;
}
