

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

//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const double inf = 0.0000;
const int lx = 2e5 + 5;
const int mod = 998244353;
const int hs = 3797;

inline bool checkBit (int  n, int i) { return n&(1LL<<i); }
inline int  setBit (int n, int i) { return n|(1LL<<i);; }
inline int resetBit (int n, int i) { return n&(~(1LL<<i)); }

struct graph {
	int u;
	int v;
	int w;
	int idx;
	
	bool operator < (const graph ob) const {
		return w < ob.w;
	}
};

int cost[lx];
int bap[lx], n, m;
graph temp;
vector<graph> adj;
set<int> e[lx];

int find(int x)
{
	if(x == bap[x]) return x;
	return bap[x] = find(bap[x]);
}

void answer(int u, int v, int w)
{
	u = find(u);
	v = find(v);
	
	if(e[u].size() < e[v].size())
		swap(u, v);
	bap[v] = u;
	
	while(e[v].begin() != e[v].end()) {
		if(e[u].find(*e[v].begin()) != e[u].end()) {
			cost[*e[v].begin()] -= w;
		}
		else e[u].insert(*e[v].begin());
		e[v].erase(e[v].begin());
	}
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) bap[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> temp.u >> temp.v >> temp.w;
		temp.idx = i;
		cost[i] = temp.w;
		adj.push_back(temp);
		
		e[temp.u].insert(i);
		e[temp.v].insert(i);
	}

	sort(adj.begin(), adj.end());
	ll ans = 0;
	for(int i = 0; i < m; i++) {
		int u = adj[i].u;
		int v = adj[i].v;
		int w = adj[i].w;
		int idx = adj[i].idx;
		
		if(find(u) == find(v)) continue;
		
		answer(u, v, w);
		ans += w;
	} 
	for(int i = 1; i <= m; i++) cout << ans + 1LL * cost[i] << ' '; cout << endl;
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
