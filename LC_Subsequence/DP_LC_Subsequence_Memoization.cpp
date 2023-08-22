#include<iostream>
#include<vector>
#include<string>
using namespace std;


    int Solver(string &text1, string &text2, int i, int j, int** arr){
        if(i>=text1.size()){
            return 0;
        }
        if(j>=text2.size()){
            return 0;
        }

        if(arr[i][j]!=-1){
            return arr[i][j];
        }
        int k=j;
        while(k<text2.size()){
            if(text1[i]==text2[k]){
                break;
            }
            k++;
        }

        if(k<text2.size()){
            arr[i][j] = max(Solver(text1,text2,i+1,j,arr), 1+Solver(text1,text2,i+1,k+1,arr));
            return arr[i][j];
        }

        else{
            arr[i][j] = Solver(text1,text2,i+1,j,arr);
            return arr[i][j];
        }
        
    }

    int Wrapper(string &text1, string &text2, int i, int j){
        int **arr = new int*[text1.size()];
        for(int i=0;i<text1.size();i++){
            arr[i] = new int[text2.size()];
        }
        
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                arr[i][j]=-1;
            }
        }
        return Solver(text1,text2,i,j,arr);
    }

    int longestCommonSubsequence(string text1, string text2) {
            return Wrapper(text1,text2,0,0);
        
    }
