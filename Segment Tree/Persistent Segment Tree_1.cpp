Problem Link: https://www.hackerrank.com/contests/morgan-stanley-2015/challenges/wet-shark-and-kth-largest-number/problem


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
const int lx = 1e5 + 10;
const int mod = 1000003;
const int hs = 3797;

inline bool checkBit (int  n, int i) { return n&(1LL<<i); }
inline int  setBit (int n, int i) { return n|(1LL<<i);; }
inline int resetBit (int n, int i) { return n&(~(1LL<<i)); }

int a[lx];
vector<int> indices[lx];

struct Node {
    Node *left;
    Node *right;
    int cnt;
    
    Node() {
        left = NULL;
        right = NULL;
        cnt = 0;
    }
};

Node *root = new Node();
Node *x[lx];

int sum(Node *temp)
{
    if(temp) return temp->cnt;
    return 0;
}

Node *Insert(Node *node, int b, int e, int idx)
{
    Node *temp = new Node();
    if(node) *temp = *node;
    
    if(b == idx and e == idx) {
        temp->cnt += 1;
        return temp;
    }
    
    int mid_idx = (b + e) / 2;
    if(idx <= mid_idx) {
        temp->left = Insert(temp->left, b, mid_idx, idx);
    }
    else {
        temp->right = Insert(temp->right, mid_idx + 1, e, idx);
    }
    temp->cnt = sum(temp->left) + sum(temp->right);
    return temp;
}

int query(Node *node, int b, int e, int k)
{
    if(b == e) return b;
    int mid = (b + e) / 2;
    int koyta = sum(node->left);
    
//    co(b sp e sp koyta sp mid);
    
    if(koyta >= k) {
        return query(node->left, b, mid, k);
    }
    else {
        return query(node->right, mid + 1, e, k - koyta);
    }
}

void solve() 
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }
    
    x[100001] = root;
    for(int i = 100000; i >= 1; i--) {
        x[i] = x[i + 1];
        for(int j  = 0; j < (int)indices[i].size(); j++) {
            x[i] = Insert(x[i], 1, 100000, indices[i][j]);
        }
    }
    while(q--) {
        int l, k;
        cin >> l >> k;
        
        cout << a[query(x[l], 1, 100000, k)] << endl;
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
// 1 2 3 2 1
}

