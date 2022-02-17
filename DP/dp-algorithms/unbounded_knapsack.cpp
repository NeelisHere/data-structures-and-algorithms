#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>a;
int solve1(int i,int max_wt){
	auto [wt,value]=a[i];
	if(i==0) return int(max_wt/wt)*value;
	int op1=solve1(i-1,max_wt),
		op2=(max_wt>=wt)?value+solve1(i,max_wt-wt):0;
	return max(op1,op2);
}
int solve2(int max_wt){
	int n=a.size(),dp[n][max_wt+1];
	memset(dp,0,sizeof(dp));
	auto [w0,x0]=a[0];
	for(int w=0;w<=max_wt;++w)dp[0][w]=int(w/w0)*x0;
	for(int i=1;i<n;++i){
		auto [wi,xi]=a[i];
		for(int w=0;w<=max_wt;++w){
			int op1=dp[i-1][w],
				op2=(w>=wi)?xi+dp[i][w-wi]:0;
			dp[i][w]=max(op1,op2);
		}
	}
	return dp[n-1][max_wt];
}
int solve3(int max_wt){
	int n=a.size();
	vector<int>prev(max_wt+1),curr(max_wt+1);
	auto [w0,x0]=a[0];
	for(int w=0;w<=max_wt;++w)prev[w]=int(w/w0)*x0;
	for(int i=1;i<n;++i){
		auto [wi,xi]=a[i];
		for(int w=0;w<=max_wt;++w){
			int op1=prev[w],
				op2=(w>=wi)?xi+curr[w-wi]:0;
			curr[w]=max(op1,op2);
		}prev=curr;
	}
	return curr[max_wt];
}
int main() {
	a={{2,5},{4,11},{6,13}};//{wt,value}
	int n=a.size(),max_wt=10;
	
	// int ans=solve(n-1,max_wt);
	// int ans=solve2(max_wt);
	int ans=solve3(max_wt);
	cout<<ans<<endl;
	return 0;
}