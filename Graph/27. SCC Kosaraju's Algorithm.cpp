You are a directed graph consists of nodes and edges. You have to find the strongly connected component. Strongly Connected Component means if you start from any node in
that component you can reach to that component again. And you have to print strongly connected component. It can be done by Kosaraju's Algorithm. This algorithm works in
three steps.

1st Step : Find topological sort for the whole graph. And put the sort in a stack
2nd Step : Transpose the graph. It means direction of edges will change.
3rd Step : Start with the stack.

Code:

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

const ll lx=2e6+7;
const ll mod = 998244353;

vector<int>adj[lx];
vector<int>transpose[lx];
bool vis[lx];
stack<int>s, ss;

void dfs(int node)
{
	vis[node] = true;
	for(int c : adj[node]) {
		if(vis[c] == false)
			dfs(c);
	}
	s.push(node);
	ss.push(node);
}

void revDfs(int node)
{
	vis[node] = true;
	cout << node << " ";
	for(int c : transpose[node]) {
		if(vis[c] == false)
			revDfs(c);
	}
}

void solve()
{
	int node, edge, i;
	cin >> node >> edge;
	for(i = 1; i <= edge; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	memset(vis, false, sizeof(vis));
	for(i = 1; i <= node; i++) {
		if(vis[i] == false)
			dfs(i);
	}
	
	for(i = 1; i <= node; i++) {
		vis[i] = false;
		for(int c : adj[i]) {
			transpose[c].push_back(i);
		}
	}
/*	while(!ss.empty()) {
		cout << ss.top() << " ";
		ss.pop();
	}
*/
//	cout << endl;
	while(!s.empty()) {
		int x = s.top();
		s.pop();
		if(vis[x] == false) {
			cout << "SCC : ";
			revDfs(x);
			cout << endl;
		}
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
