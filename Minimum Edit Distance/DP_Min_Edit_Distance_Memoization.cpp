#include<iostream>
#include<vector>
#include<string>
using namespace std;

 int Solver(string &word1, string &word2, int i, int j, int** arr){
        if(i>=word1.length() && j<word2.length()){
            int count=0;
            count = word2.length()-j;
            return count;
        }

        if(i<word1.length() && j>=word2.length()){
            int count=0;
            count = word1.length()-i;
            return count;
        }

        if(i>=word1.length() && j>=word2.length()){
            return 0;
        }
        
        if(word1[i]==word2[j]){
            arr[i][j] = Solver(word1,word2,i+1,j+1,arr);
            return arr[i][j];
        }

        if(arr[i][j]!=-1){
            return arr[i][j];
        }

        int a = 1+Solver(word1,word2,i+1,j,arr); //delete
        int b = 1+Solver(word1,word2,i,j+1,arr); //insert
        int c = 1+Solver(word1,word2,i+1,j+1,arr); //replace
        arr[i][j] = min(a,min(b,c));
        return arr[i][j];
    }

    int Wrapper(string &word1, string &word2, int i, int j){
        int m = word1.length();
        int n = word2.length();
        int **arr = new int*[m+1];
        for(int i=0;i<m+1;i++){
            arr[i] = new int[n+1];
        }

        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                arr[i][j]=-1;
            }
        }
        return Solver(word1,word2,0,0,arr);
    }

    int minDistance(string word1, string word2) {
        return Wrapper(word1,word2,0,0);
    }