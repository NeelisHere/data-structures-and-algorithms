#include <bits/stdc++.h>
#define int long long
#define M 1000000007
using namespace std;
signed main() {
  int N=1000001,dp[N][2];
  memset(dp,0,sizeof dp);
  dp[1][0]=dp[1][1]=1;
  for(int i=2;i<N;++i){
    dp[i][0]=((4*dp[i-1][0])%M+dp[i-1][1])%M;
    dp[i][1]=((2*dp[i-1][1])%M+dp[i-1][0])%M;
  }
	int t; cin>>t;
	while(t--){
    int n; cin>>n;
		cout<<(dp[n][0]+dp[n][1])%M<<endl;
	}
  return 0;
}
