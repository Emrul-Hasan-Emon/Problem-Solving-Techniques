This code complexity is O(n*n)

Problem: https://www.hackerrank.com/contests/practice-contest-1613327933/challenges/longest-decreasing-subsequence-2

Code:

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
typedef pair < ll, ll >                pll;
typedef map < li,li >                  mli;
typedef map < ll,ll >                  mll;
typedef vector < pair < li, li > >     vpi;
typedef vector < pair < ll, ll > >     vpl;
 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(i=b; i<c; i++) cout<<a[i] spc; cout nl;
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
 
const int lx = 1e6 + 123;
const ll mod = 998244353;
const int mxm = 1e3 + 12;

int dp[lx];
int a[lx];

void solve()
{
	int n, i, j;
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i] = 1;
	}
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j < i; j++)
		{
			if(a[j] > a[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for(i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	
	cout << ans << '\n';
	
}

void init_code()
{
    freopen("dataset1.txt", "r", stdin);
//    freopen("dataset1.txt", "w", stdout);
}
 
int main()
{
    faster
//    init_code();
    
    solve();
 
// A L H A M D U L I L L A H
// 1 2 3 2 1
}

