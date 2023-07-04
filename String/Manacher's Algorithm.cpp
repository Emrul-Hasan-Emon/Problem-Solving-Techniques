Manacher's Algorithm is used to find longest palindromic substring in a string. It works in linear time.


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

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const double inf = 0.0000;
const int lx = 2e5 + 23;
const int mod = 998244353;
const int hs = 3797;

int p[lx];
void manachers_algorithm(string s)
{
    //First modify the string
    string t = "#";
    for(char c : s) {
	t += c;
	t += '#';
    }
    t = "-" + t + "?";
    int l = 1, r = 1, n = s.size();
    for(int i = 1; i < n; i++) {
	p[i] = max(0, min(r - i, p[l + r - i]));
	
	while(s[i - p[i]] == s[i + p[i]]) {
	    ++p[i];
	}
	if(i + p[i] > r) {
	    l = i - p[i];
	    r = i + p[i];
	}
    }
}

void solve()
{
    
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
