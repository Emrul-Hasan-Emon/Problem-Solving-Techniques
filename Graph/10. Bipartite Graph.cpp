What is Bipartite Graph?
-> Suppose you have a graph consists of nodes and edges. You have to color the graph with two color Black and White. You have to color in such a way so that no two adjacent
node have same color. It means parent and child must be colored in different color. If you can do this, then you can say this graph is a Bipartite Graph.

So, if color can be colored with two color in such a way that no two adjacent node have same color at that time that graph is known as Bipartite Graph.
Find whether a graph is Bipartite or not.

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

const int lx = 5e3 + 123;
const ll mod = 1e9+7;
vector<int>adj[lx];
bool vis[lx];
int color[lx];

bool BFS(int source, int node)
{
    for(int i = 0; i <= node; i++)
    {
        vis[i] = false;
        color[i] = -1;
    }
    queue<int>q;
    q.push(source);
    vis[source] = true;
    color[source] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int c : adj[x])
        {
            if(vis[c] == false)
            {
                vis[c] = true;
                if(color[x] == 1) color[c] = 0;
                else color[c] = 1;
                q.push(c);
            }
            else
            {
                if(color[c] == color[x]) return false;
            }
        }
    }
    return true;
}

void solve()
{
	int node, edge;
	cin >> node >> edge;
	for(int i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(BFS(1, node))
        cout << "It is a Bipartite Graph\n";
    else
        cout << "It is not a Bipartite Graph";
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

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
