#include<bits/stdc++.h>
#define MOD 1000000007
#define lng long long
#define min_heap priority_queue<int,int>
#define max_heap priority_queue<int,vector<int>,greater<int>>
#define int_pair pair<int,int>
#define test(t) int t;cin>>t;while(t--)
#define loop(start,end) for(int i=start;i<=end;++i)
using namespace std;
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    fast_io();
    int n,x,ans;
    cin>>n>>x;
    vector<int>dp(x+1,1e9),coins(n);
    for(auto& cn:coins)cin>>cn;
    dp[0]=0;
    for(int i=1;i<=x;++i){
        for(int coin:coins){
            if(coin<=i){
                dp[i]=min(dp[i],1+dp[i-coin]);
            }
        }
    }if(dp[x]==1e9)cout<<-1;
    else cout<<dp[x];
//    for(int i:dp)cout<<i<<" ";
    return 0;
}
