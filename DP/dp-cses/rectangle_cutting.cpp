#include <bits/stdc++.h>
using namespace std;
inline void solve(){
	int height,width; cin>>height>>width;
	int dp[height+1][width+1];
	for(int h=1;h<=height;++h){
		for(int w=1;w<=width;++w){
			dp[h][w]=INT_MAX;
			if(h==w){
				dp[h][w]=0;
				continue;
			}
			//horizontal cut
			for(int i=1;i<h;++i){
				dp[h][w]=min(dp[h][w],dp[i][w]+dp[h-i][w]+1);
			}
			//vertical cut
			for(int i=1;i<w;++i){
				dp[h][w]=min(dp[h][w],dp[h][i]+dp[h][w-i]+1);
			}
		}
	}
	cout<<dp[height][width]<<endl;
	return;
}
int main() {
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}
