#include <bits/stdc++.h> 
using namespace std;
#define _int64 long long
#define mo 998244353
int d[4100][2], a[4100];
 
int main()
{
	int i, j, k, n, l, t, m, x, y, o, b1;
	cin >> n >> k;
	for(i = 0; i < n; i++)
		cin >> a[i];
	for(i = 0; i < n; i++)
		d[i][0] = (1<<30);
	d[0][0] = 0;
	d[0][1] = 5000;
	for(i = 0; i + 1 < n; i++)
	{
		if(d[i][0] == (1<<30)) 
			continue;
		for(j = i + 1; j <= i + k && j < n; j++)
			if(abs(a[i] - a[j]) <= d[i][1])
			{
				if(d[i][0] + 1 < d[j][0])
				{
					d[j][0] = d[i][0] + 1;
					d[j][1] = abs(a[i] - a[j]);
				}
				else if(d[i][0] + 1 == d[j][0])
					d[j][1] = max(d[j][1], abs(a[i] - a[j]));
			}
	}
	if(d[i][0] == (1<<30)) 
		cout << "-1\n";
	else 
		cout << d[n-1][0] << endl;
}
