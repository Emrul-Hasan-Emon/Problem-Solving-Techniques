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
typedef unsigned long long int    lu;
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

const ll lx = 1e5 + 7;
const ll mod = 998244353;
const lu hs = 3797;

lu pref[lx], suf[lx], f[lx];

lu Fhash(int x, int y)
{
	return pref[y] - f[y-x+1]*pref[x-1];
}

lu Rhash(int x, int y)
{
	return suf[x] - f[y-x+1]*suf[y+1];
}

bool check(int n, int m)
{
	bool ok = false;
	for(int i = 1; i <= n-m+1; i++)
	{
		lu a = Fhash(i, i+m-1);
		lu b = Rhash(i, i+m-1);
			
		if(a == b) ok = true;
	}
	return ok;
}
void solve()
{
	int n, i, ans, l, r, m;
	string s;
	cin >> n >> s;
	
	s = '0'+s;
	
	for(i = 1; i <= n; i++)
		pref[i] = pref[i-1]*hs + s[i];
	for(i = n; i ; i--)
		suf[i] = suf[i+1]*hs + s[i];
	f[0] = 1;
	
	for(i = 1; i <= n; i++) f[i] = f[i-1]*hs;
	
	l = 1, r = n;
	while(l <= r)
	{
		m = (l+r)/2;
		
		if(check(n, m))
		{
			ans = m;
			l = m+1;
		}
		else if(check(n, m+1))
		{
			ans = m+1;
			l = m+1;
		}
		else if(check(n, m-1))
		{
			ans = m-1;
			l = m+1;
		}
		else
			r = m-1;
	}
	co(ans);
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

