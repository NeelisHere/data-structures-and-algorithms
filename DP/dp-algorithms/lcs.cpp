#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define M 1000000007
#define print(x) cout<<x<<" "
#define println(x) cout<<x<<endl
#define next_line() cout<<endl
#define inp1(a) int a;cin>>a;
#define inp2(a,b) int a,b;cin>>a>>b;
#define inp3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define inp4(a,b,c,d) int a,b,c,d;cin>>a>>b>>c>>d;
#define inp5(a,b,c,d,e) int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
using namespace std;
using namespace __gnu_pbds;
void Array(vector<int>&A){
	next_line();
	for(int i=0;i<A.size();++i)cout<<A[i]<<" ";
	next_line();
}
void Matrix(vector<vector<int>>&A){
	next_line();
	for(int i=0;i<A.size();++i){
		for(int j=0;j<A[0].size();++j){
			cout<<A[i][j]<<" ";
		}cout<<endl;
	}
	next_line();
}
string s1,s2;
int lcs_memo(int p1,int p2){
	if(p1<0 or p2<0)return 0;
	if(s1[p1]==s2[p2]){
		return 1+lcs_memo(p1-1,p2-1);
	}else{
		return max(lcs_memo(p1-1,p2),lcs_memo(p1,p2-1));
	}
}
int lcs_tab(string s1,string s2){
	vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
	for(int i=1;i<=s1.length();++i){
		for(int j=1;j<=s2.length();++j){
			if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	Matrix(dp);
	int p1=s1.length(),p2=s2.length();
	string s="";
	while(p1>0 and p2>0){
		if(s1[p1-1]==s2[p2-1]){
			s.push_back(s1[p1-1]);
			p1--,p2--;
		}else{
			if(dp[p1-1][p2]==dp[p1][p2]){
				// s.push_back(s1[p1-1]);
				p1--;
			}else{
				// s.push_back(s2[p2-1]);
				p2--;
			}
		}
	}
	// while(p1>0){
	// 	s.push_back(s1[p1-1]);
	// 	p1--;
	// }
	// while(p2>0){
	// 	s.push_back(s2[p2-1]);
	// 	p2--;
	// }
	// next_line();
	println(s);
	next_line();
	
	return dp[s1.length()][s2.length()];
}
int solve(){
	cin>>s1; cin>>s2;
	return lcs_tab(s1,s2);
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// inp1(t);
	int t=1;
	while(t--){
		int ans=solve();
		println(ans);
	}
}