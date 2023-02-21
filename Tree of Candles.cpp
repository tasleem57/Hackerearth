#include <bits/stdc++.h>
#define int long long
using namespace std; 
int n, c[100005];
pair<int, int> ans[100005];
vector<int> adj[100005];
bitset<100005>vis;
 
inline void solve(int tc)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        adj[i].clear();
        vis[i]=false;
        ans[i]={0,0};
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    priority_queue<pair<int, int>> pq;
    int cur=0;
    pq.push({c[1],1});
    vis[1]=true;
    while(!pq.empty())
    {
        pair<int, int> x=pq.top();
        pq.pop();
        ans[x.second] = {++cur, cur + x.first - 1};
        for(int i : adj[x.second])
        {
            if(!vis[i])
            {
                vis[i] = true;
                pq.push({c[i], i});
            }
        }
    }
    int lb=0,rb=LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
        lb=max(lb,ans[i].first);
        rb=min(rb,ans[i].second);
    }
    cout<<max(0ll,rb-lb+1)<<"\n";
}
 
int32_t main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++)
        solve(i);
    return 0;
}
