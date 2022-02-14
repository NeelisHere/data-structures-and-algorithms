#include <bits/stdc++.h>
using namespace std;
vector<int>coins;
int n;
void solve(){
	int N=accumulate(coins.begin(),coins.end(),0);
	vector<int>dp(N+1,0);
	dp[0]=1;
	for(int coin: coins){
		for(int i=N;i>=coin;i--){
			dp[i]=dp[i] or dp[i-coin];

		}
	}
	cout<<accumulate(dp.begin(),dp.end(),0)-1<<endl;
	for(int i=1;i<=N;++i){
		if(dp[i])cout<<i<<" ";
	}
	cout<<endl;
}
int main() {
	cin>>n;
	while(n--){
		int val; cin>>val;
		coins.push_back(val);
	}
	n=coins.size();
	solve();
}
