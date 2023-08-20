#include<iostream>
#include<vector>
using namespace std;

    int Solver(vector<vector<int>> &grid, int m, int n, int i, int j,int** arr){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i>=m || j>=n){
            return INT_MAX;
        }

        if(arr[i][j]!=-1){
            return arr[i][j];
        }

        int r = Solver(grid,m,n,i,j+1,arr);
        int dia = Solver(grid,m,n,i+1,j+1,arr);
        int d = Solver(grid,m,n,i+1,j,arr);
        
        arr[i][j] = min(dia,min(d,r))+grid[i][j];
        return arr[i][j];
    }

    int Wrapper(vector<vector<int>> &grid, int m, int n, int i, int j){
        int **arr = new int*[m];
        for(int i=0;i<m;i++){
            arr[i] = new int[n];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=-1;
            }
        }
        return Solver(grid,m,n,i,j,arr);
    }

int getMinPathSum(vector<vector<int>> &matrix)
{

     int m = matrix.size();
        int n = matrix[0].size();
        return Wrapper(matrix,m,n,0,0);
}