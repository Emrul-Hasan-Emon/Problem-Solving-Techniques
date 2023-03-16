The concept used is here combinatorics and sub tree concept. First we find the size of each sub stree. Then the rest operation.
  
Problem: https://codeforces.com/problemset/problem/1401/D

typedef long long int ll;

vector<ll> adj[lx];
ll subtree[lx];
map<pair<ll, ll>, ll> mp;

void dfs(ll node, ll parent)
{
    subtree[node] = 1;
    for(int c : adj[node])
    {
	    if(c != parent)
	    {
	       dfs(c, node);
	       subtree[node] += subtree[c];
    	}
    }
}

void again_dfs(ll node, ll parent, ll n)
{
    ll total = n - subtree[node];
    ll sum = 0;
    
    for(int c : adj[node])
    {
    	if(c != parent)
	    {
	       ll rem = subtree[node] - subtree[c];
	       sum = (total + rem) * subtree[c];
	    
	       mp[{node, c}] = sum;
         // or it can be mp[{c, node}] = sum
	       // node to c edge is used sum times.
	    
	        again_dfs(c, node, n);
  	}
   }
}

void solve()
{
    ll n;
    cin >> n;

    for(ll i = 1; i < n; i++)
    {
	    ll u, v;
	    cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    dfs(1, -1);
    again_dfs(1, -1, n);

}
