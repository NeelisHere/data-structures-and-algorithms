#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define M 1000000007
#define print(x) cout<<x<<" "
#define println(x) cout<<x<<endl
#define next_line() cout<<endl
#define inp1(a) int a;cin>>a;
#define inp2(a,b) int a,b;cin>>a>>b;
#define inp3(a,b,c) int a,b,c;cin>>a>>b>>c;
#define inp4(a,b,c,d) int a,b,c,d;cin>>a>>b>>c>>d;
#define inpArray(arr) for(auto &val:arr)cin>>val;
using namespace std;
using namespace __gnu_pbds;
vector<int>coins,allCombinations;
unordered_map<int,int>dp;
int countSum(int target){
	if(target<=0)return(target==0);
	int currentTotalNoOfWays=0;
	for(int coin:coins){
		int val=0;
		if(dp.find(target-coin)==dp.end())val+=countSum(target-coin);
		else val+=dp[target-coin];
    val=(val%M);
		currentTotalNoOfWays=(currentTotalNoOfWays%M+val)%M;
	}
	dp[target]=currentTotalNoOfWays;
	return dp[target];
}
void solve(){
	inp2(n,target);
	while(n--){
		inp1(x);
		coins.push_back(x);
	}
	n=coins.size();
	int ans=countSum(target);
	print(ans);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// inp1(t);
	int t=1;
	while(t--){
		solve();
	}
}
