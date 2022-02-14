#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&a,int k,int i=0,int sum=0){
	if(sum>k)return false;
	if(sum==k)return true; 
	if(i==a.size())return false;

	bool inc=solve(a,k,i+1,sum+a[i]),exc=solve(a,k,i+1,sum);
	return inc or exc;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		std::vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];

		bool isPossible=solve(a,k);
		if(isPossible)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}