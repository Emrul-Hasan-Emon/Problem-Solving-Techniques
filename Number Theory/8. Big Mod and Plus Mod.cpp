// ============================================================================ //
// ||                                                                        || //
// ||             International University of Business Agriculture           || //
// ||                    and Technology, DHaka, Bangladesh                   || //
// ||                           Emrul Hasan Emon                             || //
// ||                                                                        || //
// ============================================================================ //


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

const double inf = 0.0000;
const int lx = 1e5 + 23;
const int mod = 1e9 + 7;
const int hs = 3797;

lu PlusMod(lu a, lu b, lu m)
{
	
	if(!b) return 0;
	lu ans = PlusMod(a, b/2, m);

	if(m-ans > ans) ans = ans + ans; // For overcoming overflow
	else ans = ans + (ans - m);
	
	if(b&1)
	{
		if(m-ans > a) ans += a;
		else ans = ans + (a - m);
	}
	return ans;
}

lu BigMod(lu a, lu b, lu m)
{
	if(!b) return 1;
	lu ans = BigMod(a, b/2, m);
	ans %= m;
	ans = PlusMod(ans, ans, m);
	
	if(b&1) ans = PlusMod(ans, a, m)%m;
	return ans%m;
}

lu PowerMod(lu a, lu b)
{
	if(!b) return 1;
	lu ans = PowerMod(a, b/2);
	ans *= ans;
	
	if(b&1) ans *= a;
	return ans;
}

void solve()
{
    
}

int main()
{
    faster
    
    solve();
// A L H A M D U L I L L A H
// 1 2 3 2 1
}
