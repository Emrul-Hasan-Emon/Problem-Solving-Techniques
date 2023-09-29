
///              B I S M I L L A H I R  R A H M A N I R  R A H I M


#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef bool                      boo;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    lu;
typedef double                    db;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < pair<li, li>, li>        PLL;
typedef pair < ll, ll >                 pll;
typedef map < li,li >                   mli;
typedef map < ll,ll >                   mll;
typedef vector < pair < li, li > >      vpi;
typedef vector < pair < ll, ll > >      vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(int i=b; i<c; i++) cout<<a[i] spc; cout nl;
#define lp(i,a,b)                 for(i=a;i<b;i++)
#define len(z)                    z.begin(),z.end()
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define input_txt                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define nl                        <<"\n"
#define spc                       <<" "
#define sp                        <<" "<<
#define co(x)                     cout<<x nl
#define sz(a)                     a.size()
#define cy                        cout<<"YES" nl
//#define cn                        cout<<"NO" nl
#define pb                        push_back
#define F                         first
#define S                         second
#define pi                        2*acos(0.0)
#define clr(z)                    z.clear()
#define rn                        return
#define gcd(a,b)                  __gcd(a,b)
#define mem(b,z)                  memset(b,z,sizeof(b))
#define fixed(x)                  fixed<<setprecision(x)

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const double inf = 0.0000;
const int lx = 1e6 + 10;
const int mod = 998244353;
const int hs = 3797;

inline bool checkBit (int  n, int i) { return n&(1LL<<i); }
inline int  setBit (int n, int i) { return n|(1LL<<i);; }
inline int resetBit (int n, int i) { return n&(~(1LL<<i)); }

vector<int> adj[lx];
bool vis[lx];
int st[lx], en[lx], cnt[lx], depth[lx], a[lx];
int parent[lx][20], res[lx];
string colors;
int ans, _time;
int id[lx * 2];

const int B = 320;
struct query {
	int l, r, id;
	bool operator < (const query& x) {
		if(l / B == x.l /B) return r < x.r;
		return l / B < x.l / B;
	}
}Q[lx];

void dfs(int node, int p)
{
	if(colors[node] == '1') a[node] = node;
	else a[node] = a[p];
	
	st[node] = ++_time;
	id[_time] = node;
	
	depth[node] = depth[p] + 1;
	parent[node][0] = p;
	
	for(int k = 1; k < 20; k++) {
		parent[node][k] = parent[parent[node][k - 1]][k - 1];
	}
	
	for(int child : adj[node]) {
		if(child != p) dfs(child, node);
	}
	
	en[node] = ++_time;
	id[_time] = node;
}

int getLCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int k = 19; k >= 0; k--) if(depth[parent[u][k]] >= depth[v]) u = parent[u][k];
    if(u == v) return u;
    for(int k = 19; k >= 0; k--) if(parent[u][k] != parent[v][k]) u = parent[u][k], v = parent[v][k];
    return parent[u][0];
}

inline void add(int u) 
{
	int x = a[u];
	if(cnt[x] == 0) ans++;
	cnt[x]++;
}

inline void rem(int u)
{
	int x = a[u];
	cnt[x]--;
	if(cnt[x] == 0) ans--;
}

inline void check(int u)
{
	if(!vis[u]) add(u);
	else rem(u);
	vis[u] ^= 1;
}

void solve() 
{
	int n, q;
	cin >> n >> q;
	
	for(int i = 0; i <= n; i++) {
		adj[i].clear();
		vis[i] = false;
		st[i] = en[i] = cnt[i] = 0;
		depth[i] = 0;
		for(int j = 0; j < 20; j++) parent[i][j] = 0;
	}
	
	for(int u = 2; u <= n; u++) {
		int _parent;
		cin >> _parent;
		adj[_parent].push_back(u);
	}
	ans = 0;
	cin >> colors;
	colors = "#" + colors;
	
	
	_time = 0;
	dfs(1, 0);
	
	
	for(int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		
		if(st[u] > st[v]) swap(u, v);
		int lca = getLCA(u, v);
		if(lca == u) Q[i].l = st[u], Q[i].r = st[v];
		else Q[i].l = en[u], Q[i].r = st[v];
		
		Q[i].id = i;
	}
	
	sort(Q + 1, Q + q + 1);
	int l = 1, r = 0;
	for(int i = 1; i <= q; i++) {
		int L = Q[i].l, R = Q[i].r;
		
		if(R < l) {
			while(l > L) check(id[--l]);
			while(l < L) check(id[l++]);
			while(r < R) check(id[++r]);
			while(r > R) check(id[r--]);
		}
		else {
			while(r < R) check(id[++r]);
			while(r > R) check(id[r--]);
			while(l > L) check(id[--l]);
			while(l < L) check(id[l++]);
		}
		int u = id[l], v = id[r], lca = getLCA(u, v);
		if(lca != u and lca != v) check(lca);
		res[Q[i].id] = ans;
		if(lca != u and lca != v) check(lca);
	}
	
	for(int i = 1; i <= q; i++) cout << res[i] << endl;
}

void init_code()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{
    faster
	tc
    solve();
// A L H A M D U L I L L A H
// 1 2 3 2 1
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 *ll ext_gcd (ll A, ll B, ll &X, ll &Y )
{
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

ll modInv_general ( ll a, ll m ) {
    ll x, y;
    ext_gcd( a, m, x, y );

    
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}
* 
bool mark[lx];
vector<int> primes;

void sieve()
{
    mark[0] = mark[1] = true;
    
    for(int i = 3; i*i <= lx; i++)
    {
	if(!mark[i])
	{
	    for(int j = i*i; j < lx; j += i)
		mark[j] = true;
	}
    }
    
    primes.push_back(2);
    for(int i = 3; i < lx; i += 2)
    {
	if(!mark[i])
	{
	    primes.push_back(i);
	}
    }
}
* 
ll Big_Mod(ll a, ll b)
{
	if(!b) return 1;
	ll ans = Big_Mod(a, b/2);
	ans %= mod;
	ans *= ans;
	ans %= mod;
	
	if(b&1)
	{
		a %= mod;
		ans *= a;
		ans %= mod;
	}
	return ans;
}
* 
ll fact(ll n)
{
    ll ans=1;
    for(ll i=1; i<=n; i++)
        ans=(ans*i)%mod;
    return ans;
}

ll nCr(ll n, ll k)
{
    return fact(n)*1ll*Big_Mod(fact(k), mod-2)%mod*1ll*Big_Mod(fact(n-k), mod-2)%mod;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void number_of_divisors(li n)
{
    //Number of divisors of every number between 1 to n
    for(li i = 1; i*i <= n; i++)
    {
        for(li j = i*i; j <= n; j += i)
        {
            if(i*i == j)
                a[j]++;
            else
                a[j] += 2;
        }
    }
}

void sum_of_divisor()
{
    for(li i = 1; i * i <= 1e7; i++)
    {
        for(li j = i*i; j < 1e7; j += i)
        {
            if(j == i*i)
                a[j] += i;
            else
                a[j] += i+(j/i);
        }
    }
}
*/




