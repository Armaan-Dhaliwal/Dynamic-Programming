#include<iostream>
#include<vector>
#include<string>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int**dp = new int*[m];
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            dp[i]=new int[n];
        }
        int temp=0;

        for(int i=0;i<m;i++){
            char c = matrix[i][0];
            if(c=='1'){
                temp=1;
            }
            string str="";
            str+=c;
            dp[i][0]=stoi(str);
            cout<<dp[i][0]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            char c = matrix[0][i];
            if(c=='1'){
                temp=1;
            }
            string str ="";
            str+=c;
            dp[0][i]=stoi(str);
            cout<<dp[0][i]<<" ";
        }
        int side=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j] =1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                if(dp[i][j]>side){
                    side = dp[i][j];
                }
            }
        }
        if(side==0){
            return temp;
        }
        return side*side;
    }