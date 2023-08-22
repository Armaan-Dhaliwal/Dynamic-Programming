#include<iostream>
#include<vector>
#include<string>
using namespace std;

int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int **arr = new int*[m+1];
        for(int i=0;i<m+1;i++){
            arr[i] = new int[n+1];
        }

        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i>=word1.length() && j<word2.length()){
                    arr[i][j] = word2.length()-j;
                }

                if(i<word1.length() && j>=word2.length()){
                    arr[i][j] = word1.length()-i;
                }

                if(i>=word1.length() && j>=word2.length()){
                    arr[i][j] = 0;
                }
                
            }
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    arr[i][j] = arr[i+1][j+1];
                }

                else{
                    int a = 1+arr[i+1][j]; //delete
                    int b = 1+arr[i][j+1]; //insert
                    int c = 1+arr[i+1][j+1]; //replace
                    arr[i][j] = min(a,min(b,c));
                }
            }
        }
        return arr[0][0];
    }