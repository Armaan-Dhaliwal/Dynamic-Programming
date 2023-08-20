#include<iostream>
#include<vector>
#include<string>
using namespace std;

int Solver(string &S, string &T, int i, int j,int arr[501][501]){
        if(i>=S.length()){
            return 501;
        }
        
        if(j>=T.length()){
            return 1;
        }
        
        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        
        int k = j;
        while(k<T.size()){
            if(S[i]==T[k]){
                break;
            }
            k++;
        }
        
        if(k==T.size()){
            return 1;
        }
        
        arr[i][j] = min(Solver(S,T,i+1,j,arr), 1+Solver(S,T,i+1,k+1,arr));
        return arr[i][j];
    }  
    
    int Wrapper(string &S, string &T, int i, int j){
        int arr[501][501];
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                arr[i][j]=-1;
            }
        }
        return Solver(S,T,0,0,arr);
    }
    
    
    int shortestUnSub(string S, string T) {
        
        int res = Wrapper(S,T,0,0);
        if(res>=501){
            return -1;
        }
            return res;
    }