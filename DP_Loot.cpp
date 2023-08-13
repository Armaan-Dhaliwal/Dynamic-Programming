#include<iostream>
#include<climits>
using namespace std;

/*
    A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
*/

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter your elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int *dp = new int[n+1];
	dp[0]=0;
	dp[1]=arr[0];
	int maxi=0;
	for(int i=2;i<=n;i++){
		maxi = max(maxi,dp[i-2]);
		dp[i]=arr[i-1]+maxi;
	}
	return max(dp[n],dp[n-1]);


}