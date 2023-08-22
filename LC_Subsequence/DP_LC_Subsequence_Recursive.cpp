#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:

    int Solver(string &text1, string &text2, int i, int j){
        if(i>=text1.size()){
            return 0;
        }
        if(j>=text2.size()){
            return 0;
        }

        int k=j;
        while(k<text2.size()){
            if(text1[i]==text2[k]){
                break;
            }
            k++;
        }

        if(k<text2.size()){
            return max(Solver(text1,text2,i+1,j), 1+Solver(text1,text2,i+1,k+1));
        }

        else{
            return Solver(text1,text2,i+1,j);
        }
        
    }

    int longestCommonSubsequence(string text1, string text2) {
            return Solver(text1,text2,0,0);
        
    }
};