#include<iostream>
#include<climits>
using namespace std;

int main(){
    cout<<"Enter number of matrices: "<<endl;
    int size;
    cin>>size;
    cout<<"Enter dimensions: "<<endl;
    int *dimensions = new int[size+1];
    for(int i=0;i<size+1;i++){
        cin>>dimensions[i];
    }

    int **dp = new int*[size+1];
    for(int i=0;i<size+1;i++){
        dp[i] = new int[size+1];
    }

    for(int i=0;i<size+1;i++){
        for(int j=0;j<size+1;j++){
            if(i>=j){
                dp[i][j]=0;
            }
            if(j-i==1){
                dp[i][j]=0;
            }
        }
    }

    for(int i=size;i>=0;i--){
        for(int j=i+1;j<size+1;j++){
            int min=INT_MAX;
            for(int k=i+1;k<j;k++){
                int temp = dp[i][k] + dp[k][j] + dimensions[i]*dimensions[k]*dimensions[j];
                if(temp<min){
                    min=temp;
                }
            }
            if(min<INT_MAX){
                dp[i][j]=min;
            }
            else{
                dp[i][j]=0;
            }   
        }
    }

    cout<<dp[0][size]<<endl;

}