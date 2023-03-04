#include <bits/stdc++.h>
using namespace std;
 
void solve(int n)
{
    bool zero = true;
    int a;
    for(int i = 0; i < n; i++)
	{
        cin >> a;
        if(a > 0) 
			zero = false;
    }
    if(zero)
	{
        cout << "YES" << "\n";
        cout << 0 << " " << 0 << "\n";
    }
    else 
		cout << "NO" << "\n";
}
 
bool check(vector<int>& a, multiset<int, greater<int>> st)
{
    while(st.size() < a.size())
	{
        auto it = st.begin();
        int p = (*it++), q = (*it);
        st.insert(p + q);
        st.insert(p - q);
    }
    int i = 0;
    for(auto it = st.begin(); it != st.end(); it++)
	{
        if(a[i] == (*it)) 
			++i;
        else 
			return false;
    }
    return true;
}
 
int main() 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
	{
        int n, i = 0, ab, a;
        cin >> n;
        if(n >= 90)
		{
            solve(n);
            continue;
        }
        vector<int> x(n);
        multiset<int, greater<int>> st;
        for(int i = 0; i < n; i++)
		{
            cin >> x[i];
            st.insert(x[i]);
        }
        for(auto it = st.begin(); it != st.end(); it++) 
			x[i++] = (*it);
        while(st.size() > 2)
		{
            auto it = st.begin();
            ab = (*it), st.erase(it);
            it = st.begin(), a = (*it);
            int b = ab - a;
            if(a >= b && st.count(a - b)) 
				st.erase(st.find(a - b));
            else 
				break;
        }
        if(st.size() == 2 && check(x, st))
		{
            cout << "YES" << "\n";
            for(auto it = st.begin(); it != st.end(); it++) 
				cout << (*it) << " ";
            cout << "\n";
        }
        else 
			cout << "NO\n";
    }
	return 0;
}
