#include <bits/stdc++.h>
using namespace std;
int solve1(int n){
	if(n==0 or n==1)return 1;
	int op1=solve1(n-1),op2=solve1(n-2);
	return op1+op2;
}
int solve2(int n){
	vector<int>dp(n+1);
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;++i)dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}
int main() {
	int n=3;
	int ans=solve2(n);
	cout<<ans<<endl;
}