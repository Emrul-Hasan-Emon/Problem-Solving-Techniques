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

const int lx = 1e5 + 7;
const ll mod = 998244353;

int a[lx], cs;
vector<int> tree[4*lx];
vector<ll> sum[4*lx];

void build(int node, int b, int e)
{
	if(b == e)
	{
		tree[node].push_back(a[b]);
		sum[node].push_back(a[b]);
		return;
	}
	
	int l = 2*node;
	int r = 2*node + 1;
	int m = (b+e) >> 1;
	
	build(l, b, m);
	build(r, m+1, e);
	
	int i = 0, j = 0;
	while(true)
	{
		if(i == tree[l].size() and j == tree[r].size()) break;
		if(i < tree[l].size() and j < tree[r].size())
		{
			if(tree[l][i] <= tree[r][j])
			{
				tree[node].push_back(tree[l][i]);
				i++;
			}
			else
			{
				tree[node].push_back(tree[r][j]);
				j++;
			}
		}
		else if(i < tree[l].size())
		{
			tree[node].push_back(tree[l][i]);
			i++;
		}
		else
		{
			tree[node].push_back(tree[r][j]);
			j++;
		}
	}
	
	ll total = 0;
	for(int c : tree[node])
	{
		total += c;
		sum[node].push_back(total);
	}
}

pll query(int node, int b, int e, int i, int j, ll x)
{
	if(b > j or e < i) return pll(0, 0);
	if(b >= i and e <= j)
	{
		int idx = lower_bound(len(tree[node]), x) - tree[node].begin();
		if(idx == 0) return pll(0, 0);
		else return pll(sum[node][idx-1], idx);
	}
	
	int l = 2*node;
	int r = 2*node + 1;
	int m = (b+e) >> 1;
	
	pll p1 = query(l, b, m, i, j, x);
	pll p2 = query(r, m+1, e, i, j, x);
	pll ans = {0, 0};
	
	ans.first = p1.first + p2.first;
	ans.second = p1.second + p2.second;
	
	return ans;
}

void solve()
{
    int n, i;
    cin >> n;
    
    for(i = 1; i <= n; i++) cin >> a[i];
    for(i = 0; i <= 4*n; i++)
    {
    	tree[i].clear();
    	sum[i].clear();
    }
    
    build(1, 1, n);
    int q; cin >> q;
    cout << "Case " << ++cs << ":\n";
    while(q--)
    {
    	int l, r;
    	ll x;
    	cin >> l >> r >> x;
    	
    	ll result = 0;
    	pll p1 = query(1, 1, n, l, r, x);
    	
    	result = abs((p1.first) - (x * p1.second));
    	
    	pll p2 = query(1, 1, n, l, r, 1e15);
    	p2.first -= p1.first;
    	p2.second -= p1.second;
    	
    	result += abs((p2.first) - (x * p2.second));
    	
    	cout << result << '\n';
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
    tc
    solve();

// A L H A M D U L I L L A H
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 2 3 4 5....
// Emrul Hasan Emon
}


