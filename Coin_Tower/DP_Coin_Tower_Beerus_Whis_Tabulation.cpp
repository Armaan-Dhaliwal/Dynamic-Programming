#include<iostream>
using namespace std;

// 0: Beerus
// 1: Whis

int main(){
    cout<<"Enter value of N:"<<endl;
    int N;
    cin>>N;
    int arr[3]={1,2,3};
    cout<<"Enter two moves: "<<endl;
    cin>>arr[1];
    cin>>arr[2];

    int **dp = new int*[N+1];
    for(int i=0;i<N+1;i++){
        dp[i] = new int[2];
    }

    dp[0][1]=0;
    dp[0][0]=1;

    bool turn =0 ;
    for(int i=1;i<=N;i++){
        turn=!turn;
        bool res1=!turn;
        bool res2=!turn;
        bool res3=!turn;
            if(i-arr[0]>=0){
                res1 = dp[i-arr[0]][!turn];
            }
            if(i-arr[1]>=0){
                res2 = dp[i-arr[1]][!turn];
            }
            
            if(i-arr[2]>=0){
                res3 = dp[i-arr[2]][!turn];
            }
            
            bool result = res1 || res2 || res3;
            if(res1==turn){
                dp[i][turn]=res1;
                dp[i][!turn]=!res1;
                // turn=!turn;
                continue;
            }
            if(res2==turn){
                dp[i][turn]=res2;
                dp[i][!turn]=!res2;
                //  turn=!turn;
                continue;
            }
            if(res3==turn){
                dp[i][turn]=res3;
                dp[i][!turn]=!res3;
                //  turn=!turn;
                continue;
            }
        dp[i][turn]=result;
        dp[i][!turn]=!result;
        // turn=!turn;
    }

    if(dp[N][0]){
        cout<<"Whis wins"<<endl;
    }
    else{
        cout<<"Beerus wins"<<endl;
    }
    
}