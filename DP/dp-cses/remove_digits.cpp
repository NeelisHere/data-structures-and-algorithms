#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	vector<int>dp(n+1,0);
	for(int i=1;i<=n;++i){
		int temp=i,minVal=INT_MAX;
		while(temp>0){
			int di=temp%10;
			if(di) minVal=min(minVal,1+dp[i-di]);//ignore if di==0
			temp/=10;
		}
		dp[i]=minVal;
	}
	cout<<dp[n];
	return 0;
}
