// KMP

The problem is you are given two strings. One is text and another one is pattern. You have to say how many times pattern can be found
in string text as a substring.

Sample Input:
aabxaaabaabaabaax
aabaab

Sample Output:
2


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
const int lx = 1e7 + 2;
const int mod = 1000000007;
const int hs = 3797;

inline bool checkBit (int  n, int i) { return n&(1LL<<i); }
inline int  setBit (int n, int i) { return n|(1LL<<i);; }
inline int resetBit (int n, int i) { return n&(~(1LL<<i)); }

int lps[lx];

void calLPS(string pattern)
{
    int len = pattern.size();
    lps[0] = 0;
    for(int i = 1, k = 0; i < len; i++) {
	while(k > 0 and pattern[i] != pattern[k]) {
	    k = lps[k - 1];
	}
	if(pattern[i] == pattern[k]) k++;
	lps[i] = k;
    }
}

int KMP(string text, string pattern)
{
    calLPS(pattern);
    int matches = 0;
    
    for(int i = 0, k = 0; i < (int)text.size(); i++) {
	while(k > 0 and pattern[k] != text[i]) {
	    k = lps[k - 1];
	}
	if(pattern[k] == text[i]) k++;
	if(k == pattern.size()) {
	    matches++;
	    k = lps[k - 1];
	}
    }
    return matches;
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;
    
    cout << "Number of times that pattern string is present in text string is : ";
    cout << KMP(text, pattern) << endl;
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
