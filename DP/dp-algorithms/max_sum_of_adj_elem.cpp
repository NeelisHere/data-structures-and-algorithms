#include <bits/stdc++.h>
using namespace std;
vector<int>a;
int solve1(int i){
	if(i==0)return a[0];
	if(i<0)return 0;
	return max(solve1(i-1),a[i]+solve1(i-2));
}
int solve2(){
	int n=a.size(),dp[n]={0};
	dp[0]=a[0];
	if(n>1)dp[1]=a[1];
	for(int i=2;i<n;++i){
		dp[i]=max(dp[i-1],a[i]+dp[i-2]);
	}
	return dp[n-1];
}
int solve3(){
	int n=a.size(),p0=a[0],p1=a[1],curr;
	for(int i=2;i<n;++i){
		curr=max(p0+a[i],p1);
		p0=p1,p1=curr;
	}
	return (n==1)?a[0]:((n==2)?a[1]:curr);
}
int main() {
	a={5,5,10,40,50,35};//ans=80
	int n=a.size();
	
	int ans=(n==0)?0:solve3();
	cout<<ans;
}