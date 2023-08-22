#include<iostream>
#include<vector>
#include<string>
using namespace std;

  int Solver(string &word1, string &word2, int i, int j){
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
            return Solver(word1,word2,i+1,j+1);
        }

        int a = 1+Solver(word1,word2,i+1,j); //delete
        //string temp = word2[j]+word1;
        int b = 1+Solver(word1,word2,i,j+1); //insert
        int c = 1+Solver(word1,word2,i+1,j+1); //replace
        return min(a,min(b,c));
    }

    int minDistance(string word1, string word2) {
        return Solver(word1,word2,0,0);
    }