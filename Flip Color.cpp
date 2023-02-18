#include <bits/stdc++.h>
using namespace std;
 
void dfs(int x, int f, const vector<vector<int>> &con, vector<int> &c) {
	for (int y : con[x]) {
		if (y != f) {
			dfs(y, x, con, c);
			c[x] += c[y];
		}
	}
}
 
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
	vector<vector<int>> con(n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
	vector<int> c(n);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		++c[x - 1];
	}
 
	dfs(0, -1, con, c);
	int r = 0;
	for (int i = 0; i < n; ++i) {
		r += (v[i] + c[i]) % 2;
	}
	printf("%d\n", r);
	return 0;
}
