#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define gc(x) ((x) = getchar())
using namespace::std;
 
const long double PI = acos(-1);
const long long MOD = 1000000000 +7;
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;
typedef set<int> si;
typedef set<ii> sii;
typedef set<iii> siii;
 
ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}
 
ll add(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a+b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}
 
ll mul(ll a, ll b, ll m = MOD){
	if(a >= m) a %= m;
	if(b >= m) b %= m;
	if(a < 0) a += m;
	if(b < 0) b += m;
	ll res = a*b;
	if(res >= m or res <= -m) res %= m;
	if(res < 0) res += m;
	return res;
}
 
ll pow_mod(ll a, ll b, ll m = MOD){
	ll res = 1LL;
	a = a%m;
	while(b){
		if(b&1) res = mul(res,a,m);
		b >>= 1;
		a = mul(a,a,m);
	}
	return res;
}
 
ll fastexp(ll a, ll b){
	ll res = 1LL;
	while(b){
		if(b&1) res = res*a;
		b >>= 1;
		a *= a;
	}
	return res;
}
 
int gcdExtendido(int a, int b, int *x, int *y){
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = gcdExtendido(b%a,a,&x1,&y1);
	
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}
 
int modInverso(int a, int m){
	int x, y;
	int g = gcdExtendido(a,m,&x,&y);
	if(g!=1) return -1;
	else return (x%m + m)%m;
}
 
/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/
 
const int N = 100000 + 5;
 
int n, k;
int w[N];
int D[N];
int vis[N];
vector<int> G[N];
vector<pair<int, int>> edges;
 
pair<int, int> get_furthest(int src){
	queue<int> Q;
	Q.emplace(src);
	D[src] = 0;
	vis[src]++;
	vector<int> comp;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		comp.emplace_back(u);
		for(int v : G[u]){
			if(vis[v] == vis[src]) continue;
			Q.emplace(v);
			D[v] = D[u] + 1;
			vis[v]++;
		}
	}
	int res = -1;
	for(auto x : comp){
		if(res == -1 or D[res] < D[x]) res = x;
	}
	return make_pair(res, D[res]);
}
 
int get_component_diameter(int src){
	return get_furthest(get_furthest(src).first).second;
}
 
int get_diameter(){
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		res = max(res, get_component_diameter(i));
	}
	return res;
}
 
bool can(int X){
	for(auto e : edges){
		if(w[e.second] > X) continue;
		G[e.first].emplace_back(e.second);
		G[e.second].emplace_back(e.first);
	}
	int r = get_diameter();
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		G[i].clear();
	}
	return r >= k;
}
 
int main(){
	ri2(n, k);
	for(int i = 1; i <= n; i++) ri(w[i]);
	for(int i = 1; i < n; i++){
		int u, v;
		ri2(u, v);
		if(w[u] > w[v]) swap(u, v);
		edges.emplace_back(make_pair(u, v));
	}
	vector<int> values(w + 1, w + n + 1);
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	int lo = 0, hi = values.size() - 1;
	while(lo < hi){
		int mi = lo + (hi - lo) / 2;
		if(!can(values[mi])) lo = mi + 1;
		else hi = mi;
	}
	if(not can(values[lo])) cout << -1 << endl;
	else cout << values[lo] << endl;
	return 0;
}
