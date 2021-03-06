#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>a;
void display(vector<vector<int>>&dp){
	for(int i=0;i<dp.size();++i){
		for(int j=0;j<dp[0].size();++j){
			cout<<int(dp[i][j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int solve(int i,int w){
	auto [wt,p]=a[i];
	if(i==0){
		if(wt<=w)return p;
		else return 0;
	}
	int exc=solve(i-1,w),inc=(wt<=w)?p+solve(i-1,w-wt):INT_MIN;
	return max(inc,exc);
}
int tabulation(int max_wt){
	int n=a.size();
	vector<vector<int>>dp(n,vector<int>(max_wt+1,0));
	auto [w,p]=a[0];//dp[current_index][remaining_weight]
	for(int rem_wt=w;rem_wt<=max_wt;++rem_wt)dp[0][rem_wt]=p;
	for(int i=1;i<n;++i){
		for(int rem_wt=0;rem_wt<=max_wt;++rem_wt){
			auto [wi,pi]=a[i];
			int exc=dp[i-1][rem_wt],inc=(wi<=rem_wt)?pi+dp[i-1][rem_wt-wi]:INT_MIN;
			dp[i][rem_wt]=max(exc,inc);
		}
	}
	display(dp);
	return dp[n-1][max_wt];
}
int spaceOptimization(int max_wt){
	int n=a.size();
	vector<int>prev(max_wt+1,0),current(max_wt+1,0);
	auto [w0,p0]=a[0];
	for(int rem_wt=w0;rem_wt<=max_wt;++rem_wt)prev[rem_wt]=p0;
	for(int i=1;i<n;++i){
		for(int rem_wt=0;rem_wt<=max_wt;++rem_wt){
			auto [wi,pi]=a[i];
			int exc=prev[rem_wt],inc=(wi<=rem_wt)?pi+prev[rem_wt-wi]:INT_MIN;
			current[rem_wt]=max(inc,exc);
		}prev=current;
	}
	return current[max_wt];
}
int singleArraySpaceOptimization(int max_wt){
	int n=a.size();
	vector<int>dp(max_wt+1,0);
	auto [w0,p0]=a[0];
	for(int w=w0;w<=max_wt;++w)dp[w]=p0;
	for(int i=1;i<n;++i){
		for(int w=max_wt;w>=0;--w){
			auto [wi,pi]=a[i];
			int exc=dp[w],inc=(wi<=w)?pi+dp[w-wi]:INT_MIN;
			dp[w]=max(inc,exc);
		}
	}
	return dp[max_wt];
}
int main(){
	std::vector<pair<int,int>>v={{3,30},{2,40},{5,60}};
	a=v;
	int n=a.size(),w=6;
	// int ans=solve(n-1,w);
	// int ans=tabulation(w);
	// int ans=spaceOptimization(w);
	int ans=singleArraySpaceOptimization(w);
	cout<<ans<<endl;
	return 0;
}