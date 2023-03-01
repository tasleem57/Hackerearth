#include<bits/stdc++.h>
#include <cmath>
using namespace std;
 
int minimumValue (int n, vector<int> A, vector<int> B, vector<int> C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
 
    int mini = INT_MAX;
    int i=0,j=0,k=0;
 
    while(i<n && j<n && k<n)
    {
        int x = abs(A[i]-B[j]) + abs(B[j]-C[k]) + abs(C[k]-A[i]) ;
        mini = min(x,mini);
 
        if(A[i]<=B[j] && A[i]<=C[k])
        {
            i++;
        }
        else if(B[j]<=A[i] && B[j]<=C[k])
        {
            j++;
        }
        else if(C[k]<=A[i] && C[k]<=B[j])
        {
            k++;
        }
    }
 
    return mini;
   
   
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }
    vector<int> B(N);
    for(int i_B = 0; i_B < N; i_B++)
    {
    	cin >> B[i_B];
    }
    vector<int> C(N);
    for(int i_C = 0; i_C < N; i_C++)
    {
    	cin >> C[i_C];
    }
 
    int out_;
    out_ = minimumValue(N, A, B, C);
    cout << out_;
}
