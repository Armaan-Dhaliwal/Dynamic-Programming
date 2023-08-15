#include<iostream>
#include<climits>
using namespace std;

int minMCM(int** dp, int* dimensions, int si, int ei){
    if(si>=ei || ei-si==1){
        return 0;
    }

    if(ei-si==2){
        return dimensions[si]*dimensions[si+1]*dimensions[si+2];
    }

    if(dp[si][ei]!=-1){
        return dp[si][ei];
    }

    int min=INT_MAX;
    for(int i=si+1;i<ei;i++){
        int temp = minMCM(dp,dimensions,si,i) + minMCM(dp,dimensions,i,ei) + dimensions[si]*dimensions[i]*dimensions[ei];
        if(temp<min){
            min=temp;
        }
    }
    dp[si][ei]=min;
    return min;
}

int Wrapper(int* dimensions, int si, int ei){
    int **dp = new int*[ei+1];
    for(int i=0;i<ei+1;i++){
        dp[i] = new int[ei+1];
    }

    for(int i=0;i<ei+1;i++){
        for(int j=0;j<ei+1;j++){
            dp[i][j]=-1;
        }
    }

    return minMCM(dp,dimensions,si,ei);
}

int main(){
    cout<<"Enter number of matrices: "<<endl;
    int size;
    cin>>size;
    cout<<"Enter dimensions: "<<endl;
    int *dimensions = new int[size+1];
    for(int i=0;i<size+1;i++){
        cin>>dimensions[i];
    }
    cout<<Wrapper(dimensions, 0, size);
}