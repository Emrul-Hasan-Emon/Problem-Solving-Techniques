
// There will be multiple query and in each query we have to find number of sub segment which has sum equal to k
The problem: https://codeforces.com/contest/877/problem/F

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
const int lx = 4e5 + 10;
const int mod = 998244353;
const int hs = 3797;

inline bool checkBit (int  n, int i) { return n&(1LL<<i); }
inline int  setBit (int n, int i) { return n|(1LL<<i);; }
inline int resetBit (int n, int i) { return n&(~(1LL<<i)); }

int a[lx], t[lx];
int n, k;
map<ll, int> mp;
int o[lx], Plus[lx], Minus[lx], cnt[lx];
int l, r;
ll p[lx];

const int block = 320;
struct Query {
	int l, r, idx;
	bool operator < (Query q) const {
		int b1 = l / block;
		int b2 = q.l / block;
		
		if(b1 == b2) return r < q.r;
		return b1 < b2;
	}
};
ll res[lx], ans = 0;

ll query(int x, int y)
{
	while(x < l) {
		--l;
		ans += cnt[Plus[l]];
		cnt[o[l]]++;
	}
	while(r < y) {
		++r;
		ans += cnt[Minus[r]];
		cnt[o[r]]++;
	}

	while(l < x) {
		cnt[o[l]]--;
		ans -= cnt[Plus[l]];
		l++;
	}
	while(y < r) {
		cnt[o[r]]--;
		ans -= cnt[Minus[r]];
		r--;
	}
	return ans;
}

void solve() 
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		if(t[i] == 1) p[i] = p[i - 1] + a[i];
		else p[i] = p[i - 1] - a[i];
	}
	
	for(int i = 0; i <= n; i++) {
		mp[p[i]];
		mp[p[i] + k];
		mp[p[i] - k];
	}
	
	int idx = 0;
	for(auto &it : mp) {
		it.second = ++idx;
	}
	
	for(int i = 0; i <= n; i++) {
		o[i] = mp[p[i]];
		Plus[i] = mp[p[i] + k];
		Minus[i] = mp[p[i] - k];
	}
	cnt[o[0]]++;
	
	l = 0; r = 0;
//	for(int i = 1; i <= n; i++) cout << p[i] << ' '; cout << endl;
	
	int qr;
	vector<Query> Q;
	cin >> qr;
	for(int i = 0; i < qr; i++) {
		int x, y;
		cin >> x >> y;
		Query q;
		q.l = x - 1;
		q.r = y;
		q.idx = i;
		Q.push_back(q);
	}
	
	sort(Q.begin(), Q.end());
	
	for(auto it : Q) {
		res[it.idx] = query(it.l, it.r);
//		co(it.l sp it.r sp ans);
	}
	for(int i = 0; i < qr; i++) cout << res[i] << endl;
}

void init_code()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{
    faster
	
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
