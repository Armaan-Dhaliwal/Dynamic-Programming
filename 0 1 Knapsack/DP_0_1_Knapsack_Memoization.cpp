#include<iostream>
using namespace std;
int Solver(int W, int wt[], int val[], int n,int i,int **arr){
        //base case:
        if(i>=n){
            return 0;
        }
        
        if(arr[W][i]!=-1){
            return arr[W][i];
        }
        
        //recursive calls:

        if(wt[i]>W){
            arr[W][i] = Solver(W,wt,val,n,i+1,arr);
            return arr[W][i];
        }
        
        arr[W][i] = max(val[i]+Solver(W-wt[i],wt,val,n,i+1,arr),Solver(W,wt,val,n,i+1,arr));
        return arr[W][i];
    }
    
    int Wrapper(int W, int wt[], int val[], int n,int i){
        int **arr = new int*[W+1];
        for(int i=0;i<W+1;i++){
            arr[i] = new int[n+1];
        }
        
        for(int i=0;i<W+1;i++){
            for(int j=0;j<n+1;j++){
                arr[i][j]=-1;
            }
        }
        return Solver(W,wt,val,n,i,arr);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return Wrapper(W,wt,val,n,0);
    }