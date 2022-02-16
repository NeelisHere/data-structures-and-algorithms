#include<bits/stdc++.h>
using namespace std;
vector<int>a;
void display(vector<vector<int>>&dp){
	for(int i=0;i<dp.size();++i){
		for(int j=0;j<dp[0].size();++j){
			cout<<int(dp[i][j])<<" ";
		}
		cout<<endl;
	}cout<<endl;
}
int solve(int i,int T){
	if(i==0){
		if(T%a[i]==0)return T/a[i];
		else return (int)1e9;
	}
	int inc=(T>=a[i])?1+solve(i,T-a[i]):INT_MAX,exc=solve(i-1,T);
	return min(inc,exc);
}
int tabulation(int T){
	int n=a.size();
	vector<vector<int>>dp(n,vector<int>(T+1,0));
	for(int t=a[0];t<=T;++t){
		if(t%a[0]==0)dp[0][t]=t/a[0];
		else dp[0][t]=INT_MAX;
	}
	for(int i=1;i<n;++i){
		for(int t=0;t<=T;++t){
			int inc=(t>=a[i])?1+dp[i][t-a[i]]:INT_MAX,exc=dp[i-1][t];
			dp[i][t]=min(inc,exc);
		}
	}
	display(dp);
	return dp[n-1][T];
}
int spaceOptimization(int T){
	int n=a.size();
	vector<int>prev(T+1,0),curr(T+1,0);
	for(int t=0;t<=T;++t){
		if(t%a[0]==0)prev[t]=t/a[0];
		else prev[t]=int(1e9);
	}
	for(int i=1;i<n;++i){
		for(int t=0;t<=T;++t){
			int exc=prev[t],inc=(t>=a[i])?1+curr[t-a[i]]:INT_MAX;
			curr[t]=min(inc,exc);
		}
		prev=curr;
	}
	return curr[T];
}
/* 
int singleArraySpaceOptimization(){

	We cannot do single array space optimization here because 
	one cell in current is dependent on the previous cells of current.
	current is dependent both on prev and curr...so it is not possible.
}
*/
int main(){
	a.clear(); a={1,2,3};
	int n=a.size(),target=8;

	// int ans=solve(n-1,target);
	// int ans=tabulation(target);
	int ans=spaceOptimization(target);
	// int ans=singleArraySpaceOptimization(target);

	ans=(ans>=int(1e9))?-1:ans;
	cout<<ans<<endl;
}