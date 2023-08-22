#include<iostream>
#include<vector>
#include<string>
using namespace std;

 int longestCommonSubsequence(string text1, string text2) {
        int **arr = new int*[text1.size()+1];
        for(int i=0;i<text1.size()+1;i++){
            arr[i] = new int[text2.size()+1];
        }
        for(int i=0;i<text1.size()+1;i++){
            arr[i][text2.size()] = 0;
        }
        for(int i=0;i<text2.size()+1;i++){
            arr[text1.size()][i] = 0;
        }

        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                int k=j;
                while(k<text2.size()){
                    if(text1[i]==text2[k]){
                        break;
                    }
                    k++;
                }

                if(k<text2.size()){
                    arr[i][j] = max(arr[i+1][j], 1+arr[i+1][k+1]);
                }
                else{
                    arr[i][j] = arr[i+1][j];
                }
            }
        }
        return arr[0][0];
    }