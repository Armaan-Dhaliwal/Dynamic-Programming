#include<iostream>
#include<vector>
using namespace std;

int getMinPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int **arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }

    arr[m-1][n-1]=matrix[m-1][n-1];

    for(int i=m-2;i>=0;i--){
        arr[i][n-1]=arr[i+1][n-1] + matrix[i][n-1];
    }

    for(int i=n-2;i>=0;i--){
        arr[m-1][i]=arr[m-1][i+1] + matrix[m-1][i];
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int r = arr[i][j+1];
            int dia = arr[i+1][j+1];
            int d = arr[i+1][j];
            
            arr[i][j] = min(dia,min(d,r))+matrix[i][j];
        }
    }

    return arr[0][0];
}