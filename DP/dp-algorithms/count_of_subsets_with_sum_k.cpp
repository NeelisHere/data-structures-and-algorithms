#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>&dp){
	for(int i=0;i<dp.size();++i){
		for(int j=0;j<dp[0].size();++j){
			cout<<int(dp[i][j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int solve(int i,int sum,vector<int>&a){
	if(sum==0)return 1;
	if(i==0)return sum==a[0];
	return solve(i-1,sum,a)+solve(i-1,sum-a[i],a);
}
int solveTabulation(int k,vector<int>&a){
	int n=a.size();
	vector<vector<int>>dp(k+1,vector<int>(n+1,0));
	for(int i=0;i<=n;++i)dp[0][i]=1;
	for(int sum=1;sum<=k;++sum){
		for(int i=1;i<=n;++i){
			if(sum-a[i-1]>=0){
				dp[sum][i]=dp[sum-a[i-1]][i-1]+dp[sum][i-1];
			}else dp[sum][i]=dp[sum][i-1];
		}
	}
	display(dp);
	return dp[k][n];
}
int main(){
	vector<int>a={2,3,3,5,4,5,4,1};
	int n=a.size();
	// int ans=solve(n-1,5,a);
	int ans=solveTabulation(5,a);
	cout<<ans<<endl;
}