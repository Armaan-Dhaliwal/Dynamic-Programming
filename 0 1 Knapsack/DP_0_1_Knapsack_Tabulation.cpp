#include<iostream>
using namespace std;

 int knapSack(int W, int wt[], int val[], int n) 
    { 
       int **arr = new int*[W+1];
        for(int i=0;i<W+1;i++){
            arr[i] = new int[n+1];
        }
        
        for(int i=0;i<n+1;i++){
            arr[0][i]=0;
        }
        for(int i=0;i<W+1;i++){
            arr[i][n]=0;
        }
        
        for(int i=1;i<W+1;i++){
            for(int j=n-1;j>=0;j--){
                 if(wt[j]>i){
                    arr[i][j] = arr[i][j+1];
                }
                else{
                    arr[i][j] = max(val[j]+arr[i-wt[j]][j+1],arr[i][j+1]);
                }
            }
        }
        return arr[W][0];
    }