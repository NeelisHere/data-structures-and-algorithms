#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int solve1(int n){
	if(n==1)return 0;
	if(n==2)return abs(a[1]-a[2]);
	int op1=abs(a[n]-a[n-1])+solve1(n-1),
		op2=abs(a[n]-a[n-2])+solve1(n-2);
	return min(op1,op2);
}
int solve2(int n){
	int dp[n+1]={0};
	dp[1]=0,dp[2]=abs(a[1]-a[2]);
	for(int i=3;i<=n;++i){
		int op1=abs(a[n]-a[n-1])+dp[n-1],
			op2=abs(a[n]-a[n-2])+dp[n-2];
		dp[i]=min(op1,op2);
	}
	return dp[n];
}
int solve3(int n){
	int p2=abs(a[1]-a[2]),p1=0;
	if(n==1)return p1;
	if(n==2)return p2;
	int res=0;
	for(int i=3;i<=n;++i){
		int op1=abs(a[n]-a[n-1])+p2,
			op2=abs(a[n]-a[n-2])+p1;
		res=min(op1,op2);
		p1=p2,p2=res;
	}
	return res;
}
int main() {
	a={0,10,20,30,10};
	int n=a.size()-1,ans1=solve1(n),ans2=solve2(n),ans3=solve3(n);;
	cout<<ans3;
}