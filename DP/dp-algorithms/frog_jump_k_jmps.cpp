#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int solve1(int i,int k){
	if(i==0)return 0;
	int res=INT_MAX;
	for(int j=1;j<=k;++j){
		if(i-j>=0)res=min(res,abs(a[i]-a[i-j])+solve1(i-j,k));
	}
	return res;
}
int solve2(int n,int max_k){
	// int dp[k+1][n+1]={0};
	int dp[n+1]={0};
	dp[0]=0;
	for(int i=1;i<n;++i){
		int res=INT_MAX;
		for(int k=1;k<=max_k;++k){
			if(i-k>=0){
				res=min(res,abs(a[i]-a[i-k])+dp[i-k]);
			}
		}
		dp[i]=res;
	}
	return dp[n-1];
}
int main() {
	a={30,10,60,10,60,50};
	int n=a.size(),k=2;
	cout<<solve2(n,k);
	// cout<<solve1(n-1,k);
}