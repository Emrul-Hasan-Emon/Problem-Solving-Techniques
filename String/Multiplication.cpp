
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
typedef pair < ll, ll >                pll;
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

const int lx=1e6+123;
const ll mod = 1000000007;

void solve()
{
    int i, j, k, l, zr;
    string s, t, w, u, v, res;
    cin>>s>>t;

    if(t>s)
        swap(s, t);

    for(i=t.size()-1, zr=0; i>=0; i--, zr++)
    {
        w.clear();
        k=zr;
        while(k--)
            w+='0';

        int carry=0, x, y;
        for(j=s.size()-1; j>=0; j--)
        {
            x=(s[j]-'0')*(t[i]-'0');
            x=x+carry;
            y=x%10; x/=10;

            w=(char)(y+'0')+w;
            carry=x;
        }

        if(carry)
            w=(char)(carry+'0')+w;

        if(res.empty())
            res=w;
        else
        {
            while(res.size()<w.size())
                res='0'+res;
            while(w.size()<res.size())
                w='0'+w;

            carry=0; v.clear();
            for(j=w.size()-1; j>=0; j--)
            {
                x=(w[j]-'0')+(res[j]-'0')+carry;
                y=x%10; x/=10;
                v=(char)(y+'0')+v;
                carry=x;
            }
            if(carry)
                v=(char)(carry+'0')+v;
            res=v;
        }
    }
    cout<<res<<endl;
}

void init_code()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{
    faster
  //  init_code();
    solve();
// A L H A M D U L I L L A H
// 1 2 3 2 1
}

//I am a failure
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

ll fact(ll n)
{
    ll ans=1;
    for(ll i=1; i<=n; i++)
        ans=(ans*i)%mod;
    return ans;
}

ll Big_Mod(ll a, ll b)
{
    if(b==0)
        return 1;

    ll ans;
    ans=Big_Mod(a, b/2);
    ans=(ans*ans)%mod;

    if(b&1)
        ans=(ans*a)%mod;

    return ans;
}

ll nCr(ll n, ll k)
{
    return fact(n)*1ll*Big_Mod(fact(k), mod-2)%mod*1ll*Big_Mod(fact(n-k), mod-2)%mod;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void number_of_divisors(li n)
{
    //Number of divisors of every number between 1 to n
    for(li i = 1; i*i <= n; i++)
    {
        for(li j = i*i; j <= n; j += i)
        {
            if(i*i == j)
                a[j]++;
            else
                a[j] += 2;
        }
    }
}

void sum_of_divisor()
{
    for(li i = 1; i * i <= 1e7; i++)
    {
        for(li j = i*i; j < 1e7; j += i)
        {
            if(j == i*i)
                a[j] += i;
            else
                a[j] += i+(j/i);
        }
    }
}

*/

