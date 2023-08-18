#include<iostream>
using namespace std;

// 0: Beerus
// 1: Whis
bool Winner(int **dp, int N, int* arr, bool turn){
    if(N==0){
        return (turn==0?1:0);
    }

    if(N<0){
        return (turn==0?0:1);
    }

    if(dp[N][turn]!=-1){
        return dp[N][turn];
    }

    bool res1 = Winner(dp,N-arr[0],arr,!turn);
    bool res2 = Winner(dp,N-arr[1],arr,!turn);
    bool res3 = Winner(dp,N-arr[2],arr,!turn);
    bool result = res1 || res2 || res3;

    if(res1==turn){
        dp[N][turn]=res1;
		return res1;
    }
    if(res2==turn){
        dp[N][turn]=res2;
		return res2;
    }
    if(res3==turn){
        dp[N][turn]=res3;
		return res3;
    }
        dp[N][turn]=result;
        return result;
}

bool Wrapper(int N, int* arr, bool turn){
    int **dp = new int*[N+1];
    for(int i=0;i<N+1;i++){
        dp[i] = new int[3];
    }

    for(int i=0;i<N+1;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=-1;
        }
    }

    return Winner(dp,N,arr,turn);
}

int main(){
    cout<<"Enter value of N:"<<endl;
    int N;
    cin>>N;
    int arr[3]={1,2,3};
    cout<<"Enter two moves: "<<endl;
    cin>>arr[1];
    cin>>arr[2];

    if(Wrapper(N,arr,0)){
        cout<<"Whis wins"<<endl;
    }
    cout<<"Beerus wins"<<endl;
}