This is the optimal version of prims algorithm. Here we use priority_queue for keeping track of nodes.
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

void solve()
{
    int node, edges, i;
    cin >> node >> edges;
  
    vector<pair<int, int> >adj[node];
  
    for(i = 1; i <= edges; i++) {
    	int u, v, wt;
    	cin >> u >> v >> wt;
    	adj[u].push_back({v, wt});
    	adj[v].push_back({u, wt});
    }
  
    int parent[node]; // node are considered from 0 to node-1; 0 based;
    int distance[node];
    bool mstSet[node];
    
    for(i = 0; i < node; i++) {
    	distance[i] = INT_MAX;
    	mstSet[i] = false;
    }
  
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    distance[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    
      while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(mstSet[u] == true) continue;
        mstSet[u] = true;

        for(auto it : adj[u]) {
          int v = it.first;
          int wt = it.second;

          if(mstSet[v] == false and wt < distance[v]) {
            parent[v] = u;
            distance[v] = wt;
            pq.push({distance[v], v});
          }
    	}
    }

    for(i = 1; i < node; i++) {
    	cout << i << " " << parent[i] << endl;
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


