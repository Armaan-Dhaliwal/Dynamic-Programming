#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
  int n=nums.size();

  int *dp = new int[n+1];
	if(n==1){
		return nums[0];
	}
	dp[0]=0;
	dp[1]=nums[0];
	int maxi=0;
	for(int i=2;i<n;i++){
		if(maxi<=dp[i-2]){
			maxi= dp[i-2];
		}	
			dp[i]=nums[i-1]+maxi;
	}

	int a =max(dp[n-1],dp[n-2]);

	dp[0]=0;
	dp[1]=0;
	maxi=0;

	for(int i=2;i<=n;i++){
		if(maxi<=dp[i-2]){
			maxi= dp[i-2];
		}
		dp[i]=nums[i-1]+maxi;
	}

	int b=max(dp[n],dp[n-1]);
	return max(a,b);
}
