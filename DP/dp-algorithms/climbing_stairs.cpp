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
int solve3(int n){
	int p0=1,p1=1,curr=0;
	if(n==0 or n==1)return 1;
	for(int i=2;i<=n;++i){
		curr=p0+p1;
		p0=p1,p1=curr;
	}
	return curr;
}
int main() {
	int n=3;
	int ans=solve3(n);
	cout<<ans<<endl;
}