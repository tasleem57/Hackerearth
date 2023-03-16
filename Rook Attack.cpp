#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using LL = long long;
 
class Solution {
 public:
  void run() {
    int N, M;
    cin >> N >> M;
    vector<vector<LL>> A(N, vector<LL>(M));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> A[i][j];
      }
    }
    vector<LL> sr(N, 0);
    vector<LL> sc(M, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        sr[i] += A[i][j];
        sc[j] += A[i][j];
      }
    }
    int x, y;
    LL mx = -1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        LL score = sr[i] + sc[j] - 2 * A[i][j];
        if (score > mx) {
          mx = score;
          x = i + 1;
          y = j + 1;
        }
      }
    }
    cout << x << ' ' << y << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution solution = Solution();
 
  int t = 1;
  // cin >> t;
  for (int i = 0; i < t; i++) {
    solution.run();
  }
  return 0;
}
