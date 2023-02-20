#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size(); 
        vector<int> cnt(3); 
        for(int i = 0; i < n; ++i) 
			cnt[s[i] - '0']++;  
        int a[] = {0, 1, 2};
        long long ans = 1000000000000000000; 
        do 
		{
            long long temp_ans = 0, benefit = 0;
            for(int i = 0; i < cnt[a[0]] + cnt[a[1]]; ++i) 
			{
                if(i < cnt[a[0]]) 
				{
                    if(s[i] - '0' == a[0]) 
						continue; 
                    temp_ans++;    
                    if(s[i] - '0' == a[1]) 
						++benefit; 
                } 
				else 
				{
                    if(s[i] - '0' == a[2]) 
						temp_ans++;
                    else if(s[i] - '0' == a[0]) 
					{
                        if(benefit > 0) 
							--benefit;
                        else 
							temp_ans++; 
                    } 
                }
            }
            if(temp_ans < ans) 
				ans = temp_ans ; 
        } 
		while(next_permutation(a, a + 3));
        	cout << ans << "\n";
    }
  	return 0;
}
