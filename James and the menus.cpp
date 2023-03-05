#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int N = 1e3 + 14;
int n, m, a[N][N], mx[N];
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			mx[j] = max(mx[j], a[i][j]);
		}
	vector<tuple<int, ll, int>> v;
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < m; ++j)
			s += a[i][j] == mx[j];
		v.emplace_back(s, accumulate(a[i], a[i] + m, 0ll), i);
	}
	cout << std::get<2>(*max_element(v.begin(), v.end())) + 1 << '\n';
}
