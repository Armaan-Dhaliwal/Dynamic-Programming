#include<iostream>
using namespace std;
    int Solver(int W, int wt[], int val[], int n,int i){
        //base case:
        if(i>=n){
            return 0;
        }
        if(wt[i]>W){
            return Solver(W,wt,val,n,i+1);
        }
        
        //recursive calls:
        int sum = max(val[i]+Solver(W-wt[i],wt,val,n,i+1),Solver(W,wt,val,n,i+1));
        return sum;
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return Solver(W,wt,val,n,0);
    }