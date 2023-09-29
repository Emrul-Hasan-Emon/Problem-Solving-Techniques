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
typedef pair < li, li >                 pli;
typedef pair < pair<ll, ll>, ll>        pll;
typedef map < li,li >                   mli;
typedef map < ll,ll >                   mll;
typedef vector < pair < li, li > >      vpi;
typedef vector < pair < ll, ll > >      vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(int qq = b; qq < c; qq++) cout<<a[qq] spc; cout nl;
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

const int lx = 1e6 + 7;
const int mx = 1e4 + 7;
const ll mod = 998244353;

int a[lx], cnt[lx], block_size;
int sum = 0;
vector<pll>v;

bool comp(pll p1, pll p2)
{
    int blk1 = p1.F.F/block_size;
    int blk2 = p2.F.F/block_size;

    if(blk1 != blk2) return blk1 < blk2;
    return p1.F.S < p2.F.S;
}

void add(int idx)
{
    int x = a[idx];
    if(x == -1) return;
    if (cnt[x] == x) sum--, cnt[x]++;
    else if(cnt[x] == x-1) sum++, cnt[x]++;
    else cnt[x]++;
}

void Remove(int idx)
{
	int x = a[idx];
	if(x == -1) return;
    if(cnt[x] == 0) return;

    if(cnt[x] == x) sum--, cnt[x]--;
    else if(cnt[x] == x+1) sum++, cnt[x]--;
    else cnt[x]--;
}

void solve()
{
    int n, i, q, l, r;
    cin >> n >> q;
    for(i = 1; i <= n; i++) 
    {
    	cin >> a[i];
    	if(a[i] > 1e5) a[i] = -1;
    }
    block_size = sqrt(n)+1;

    for(i = 1; i <= q; i++)
    {
        cin >> l >> r;
        v.push_back(make_pair(make_pair(l, r), i));
    }

    sort(len(v), comp);
    int ml = 1, mr = 0;

    //for(auto p : v) co(p.F.F sp p.F.S sp p.S);
    map<int, int>m;

    for(i = 0; i < (int)v.size(); i++)
    {
        l = v[i].F.F;
        r = v[i].F.S;

        while(mr < r)
        {
            mr++;
            add(mr);
        }
        while(mr > r)
        {
            Remove(mr);
            mr--;
        }
        while(ml < l)
        {
            Remove(ml);
            ml++;
        }
        while(ml > l)
        {
            ml--;
            add(ml);
        }
        m[v[i].S] = sum;
    }
    for(auto p : m) co(p.S);
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

