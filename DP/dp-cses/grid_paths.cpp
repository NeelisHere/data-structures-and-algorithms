#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
int main() {
	int n; cin>>n;
	char mat[n][n];
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      cin>>mat[i][j];
    }
  }
  int dp[n][n];
  memset(dp,0,sizeof dp);
  if(mat[0][0]=='.')dp[0][0]=1;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(mat[i][j]=='.'){
        if(j-1>=0)dp[i][j]=dp[i][j-1];
        if(i-1>=0)dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
      }
    }
  }
	cout<< dp[n-1][n-1];
	cout<<endl;
	// for(int i=1;i<=n;++i){
	// 	for(int j=1;j<=n;++j){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }
	return 0;
}
