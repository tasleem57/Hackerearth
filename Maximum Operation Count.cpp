#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<bool> vis(n + 2, false);
    int st = 0, en = n / 2, ans = 0;
    sort(a.begin(), a.end());
    while(en < n)
    {
        if((a[en] - a[st]) >= k)
        {
            ans++; 
            vis[en] = true;
            vis[st] = true;
            en++;
            while(vis[st])
                st++;
        }
        else
            en++;
    }
    cout << ans << endl;
    return 0;
}
