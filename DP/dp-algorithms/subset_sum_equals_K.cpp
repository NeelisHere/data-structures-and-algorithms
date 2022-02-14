#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<bool>>&dp){
	for(int i=0;i<dp.size();++i){
		for(int j=0;j<dp[0].size();++j){
			cout<<int(dp[i][j])<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool solve(int i,int sum,vector<int>&a){
	if(sum==0)return true;
	if(i==0)return (a[i]==sum);
	bool exc=solve(i-1,sum,a),inc=(sum-a[i]>=0)?solve(i-1,sum-a[i],a):false;
	return inc or exc;
}
bool solveTabulation(vector<int>&a,int k){
	int n=a.size();
	vector<vector<bool>>dp(a.size(),vector<bool>(k+1,false));
	for(int i=0;i<n;++i)dp[i][0]=true;
	dp[0][a[0]]=true;
	for(int i=1;i<n;++i){
		for(int j=1;j<=k;++j){
			bool exc=dp[i-1][j],inc=(j-a[i]>=0)?dp[i-1][j-a[i]]:false;
			dp[i][j]=exc or inc;
		}
	}
	display(dp);
	return dp[n-1][k];
}
bool solveTabulationSpaceOptimized(vector<int>&a,int k){
	
	
}
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		std::vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];

		// bool ans=solve(n-1,k,a);
		// bool ans=solveTabulation(a,k);
		bool ans=solveTabulationSpaceOptimized(a,k);
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

