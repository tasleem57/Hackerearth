#include <bits/stdc++.h>
using namespace std;
int main() {
	int z;
	for (scanf("%d", &z); z; --z) {
		int n, m, last;
		scanf("%d%d%d", &n, &m, &last);
		vector<long long> dp(3);
		for (--n; n; --n) {
			int x;
			scanf("%d", &x);
			dp = {dp[0] + x % last, 
			max(dp[0] + (x + m) % last, dp[1] + (x + m) % (last + m)),
			max(dp[2] + x % last, dp[1] + x % (last + m))};
			last = x;
			//printf("dp[0] = %d dp[1] = %d dp[2] = %d\n", dp[0], dp[1], dp[2]);
		}
		printf("%lld\n", max(dp[0], max(dp[1], dp[2])));
	}
	return 0;
}
