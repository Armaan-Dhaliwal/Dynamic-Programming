#include<iostream>
#include<vector>
using namespace std;

int Solver(vector<vector<int>> &grid, int m, int n, int i, int j){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i>=m || j>=n){
            return INT_MAX;
        }

        int r = Solver(grid,m,n,i,j+1);
        int dia = Solver(grid,m,n,i+1,j+1);
        int d = Solver(grid,m,n,i+1,j);
        
        int ans = min(dia,min(d,r))+grid[i][j];
        return ans;
    }

int getMinPathSum(vector<vector<int>> &matrix)
{

     int m = matrix.size();
        int n = matrix[0].size();
        return Solver(matrix,m,n,0,0);
}