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

const int mx = 1e5 + 7;
const ll mod = 998244353;

int arr[mx];
int tree[mx * 4];

void build(int node, int b, int e)
{
    if (b == e) 
    {
        tree[node] = arr[b];
        return;
    }
    
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    
    build(Left, b, mid);
    build(Right, mid + 1, e);
    
    tree[node] = tree[Left] + tree[Right];
}

int query_sum(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
        
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    
    int p1 = query_sum(Left, b, mid, i, j);
    int p2 = query_sum(Right, mid + 1, e, i, j);
    
    return p1 + p2; //বাম এবং ডান পাশের যোগফল
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
        
    if (b >= i && e <= i) 
        { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    
    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    build(1, 1, n);

    cout << query_sum(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 2);
    cout << query_sum(1, 1, n, 2, 2) << endl;
    return 0;
}
