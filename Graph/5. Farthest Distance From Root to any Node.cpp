This problem is about farthest distance. It means I have given a graph. I have to find maximum distance between root to any node.


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

const int lx = 3e4+123;
const ll mod = 1e9+7;

// Code Ends Here

vector<int>adj[lx];
vector<int>cost[lx];
bool vis[lx];
ll dis[lx];

void dfs(int vertice, ll distance)
{
    vis[vertice] = true;
    dis[vertice] = distance;
    int i, x, c;

    for(i = 0; i < adj[vertice].size(); i++)
    {
        x = adj[vertice][i];
        c = cost[vertice][i];

        if(!vis[x])
        {
            dfs(x, distance + c);
        }
    }
}

void solve()
{

    int node, edge, i;
    cin >> node >> edge;

    for(i = 0; i <= node+2; i++)
    {
        adj[i].clear();
        cost[i].clear();
    }
    for(i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    for(i = 0; i <= node+2; i++)
        vis[i] = false, dis[i] = 0;

    dfs(1, 0);
    ll distance = 0;

    for(i = 1; i <= node; i++)
    {
        if(distance < dis[i])
        {
            distance = dis[i];
        }
    }
    cout << distance << endl;
}

// Code Finish Here

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
