https://codeforces.com/problemset/problem/514/C

///              B I S M I L L A H I R  R A H M A N I R  R A H I M

// ============================================================================ //
// ||                                                                        || //
// ||             International University of Business Agriculture           || //
// ||                    and Technology, Dhaka, Bangladesh                   || //
// ||                           Emrul Hasan Emon                             || //
// ||                                                                        || //
// ============================================================================ //

#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef bool                      boo;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    l1;
typedef double                    db;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < li, li >                pli;
typedef pair < ll, li >                pll;
typedef map < li,li >                  mli;
typedef map < ll,ll >                  mll;
typedef vector < pair < li, li > >     vpi;
typedef vector < pair < ll, ll > >     vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(int ii = 0; ii < n ; ii++) cin >> a[ii]
#define out_i(a, b, c)            for(int ii = b; ii < c; ii++) cout << a[ii] spc; cout nl;
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
#define cn                        cout<<"NO" nl
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

const ll lx = 6e5 + 7;
const ll mod = 998244353;

ll power1[lx], power2[lx];
ll mod1 = 1e9+9, mod2 = 1e9+7;
ll pr1 = 43, pr2 = 107;

void ini()
{
	power1[0] = 1;
	power2[0] = 1;
	
	for(int i = 1; i < lx; i++)
	{
		power1[i] = (power1[i-1] * pr1) % mod1;
		power2[i] = (power2[i-1] * pr2) % mod2;
	}
}

ll get_hash1(string s)
{
	ll val = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		val = (val + ((s[i]-'a'+1) * power1[i])) % mod1;
	}
	return val;
}

ll get_hash2(string s)
{
	ll val = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		val = (val + ((s[i]-'a'+1) * power2[i])) % mod2;
	}
	return val;
}

ll get_new_hash1(ll val, char prv, int pos, char ch)
{
	val %= mod1;
	val = (val - ((prv-'a'+1) * power1[pos])) % mod1;
	while(val < 0) val += mod1;
	val = (val + ((ch-'a'+1) * power1[pos])) % mod1;
	while(val < 0) val += mod1;
	val %= mod1;
	
	return val;
}

ll get_new_hash2(ll val, char prv, int pos, char ch)
{
	val %= mod2;
	val = (val - ((prv-'a'+1) * power2[pos])) % mod2;
	while(val < 0) val += mod2;
	val = (val + ((ch-'a'+1) * power2[pos])) % mod2;
	while(val < 0) val += mod2;
	val %= mod2;
	
	return val;
}

void solve()
{
	ini();
    int n, m, i;
    string s;
    
    map<pair<ll, ll>, ll>mp;
    
    cin >> n >> m;
    while(n--)
    {
    	cin >> s;
    	ll now1 = get_hash1(s);
    	ll now2 = get_hash2(s);
    	
    	mp[ {now1, now2}]++;
    //	co(now1 sp now2);
    }
 //   cout nl;
    

    while(m--)
    {
    	cin >> s;
    	ll x = get_hash1(s);
    	ll y = get_hash2(s);
    	
    	bool ok = false;
    	for(int j = 0; j < (int)s.size(); j++)
    	{
    		for(char ch = 'a'; ch <= 'c'; ch++)
    		{
    			if(ch == s[j]) continue;
    			ll e = get_new_hash1(x, s[j], j, ch);
    			ll f = get_new_hash2(y, s[j], j, ch);
    			
    			// co(e sp f);
    			// co((mp[{e, f}]));
    			
    			if(mp[ {e, f}])
    			{
    				ok = true;
    				break;
    			}
    		}
    	}
    	
    	if(ok == true) cy;
    	else cn;
    	
    }
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
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 2 3 4 5....
// Emrul Hasan Emon
}
