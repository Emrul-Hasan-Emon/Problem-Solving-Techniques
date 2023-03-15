....................Problem: Find whether e given number prime or not.

***************************Brute  Force***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    
    for(int i = 2; i < n; i++)
    {
	if(n%i == 0)
	{
	    flag = false;
	    break;
	}
    }
    
    if(flag == true) cout << "Prime\n";
    else cout << "Not Prime\n";
}

***************************Optimized Version - SQRT version***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool flag = true;
    
    for(int i = 2; i * i <= n; i++)
    {
	if(n%i == 0)
	{
	    flag = false;
	    break;
	}
    }
    
    if(flag == true) cout << "Prime\n";
    else cout << "Not Prime\n";
}



....................Problem: Find number of divisor of a number. (NOD)

***************************Brute  Force***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int divisor = 0;
    
    for(int i = 1; i <= n; i++)
    {
	      if(n%i == 0) divisor++;
    }
    cout << divisor << endl;
}

***************************Optimized Version - SQRT version***************************
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int divisor = 0;
    
    for(int i = 1; i * i <= n; i++)
    {
	    if(i*i == n) divisor++;
	    else if(n%i == 0) divisor += 2;
    }
    cout << divisor << endl;
}


....................Problem: Find sum of divisors of a number. (SOD)

***************************Brute  Force***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    
    for(int i = 1; i <= n; i++)
    {
	      if(n%i == 0) sum += i;
    }
    cout << sum << endl;
}

***************************Optimized Version - SQRT version***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    
    for(int i = 1; i * i <= n; i++)
    {
	    if(i*i == n) sum += i;
	    else if(n%i == 0)
      {
        sum += i;
        sum += n/i;
      }
    }
    cout << sum << endl;
}



....................Problem: Find number of divisor for every number 1 to n. (NOD)

***************************Brute  Force***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
	int x = i;
	int divisor = 0;
	for(int j = 1; j * j <= x; j++)
	{
	    if(j * j == x) divisor++;
	    else if(x%j == 0) divisor += 2;
	}
	cout << "Numbe of divisor for " << i << " is " << divisor << endl;
    }
}

***************************Optimized Version - SQRT version***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int a[n + 5];
    for(int i = 1; i <= n; i++) a[i] = 0;
    
    for(int i = 1; i * i <= n; i++)
    {
        for(int j = i * i; j <= n; j += i)
        {
            if(i*i == j) a[j]++;
            else a[j] += 2;
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
	cout << "Number of divisor of " << i << " is " << a[i] << endl;
    }
}

....................Problem: Find sum of divisors for every number 1 to n. (NOD)

***************************Brute  Force***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
	int x = i;
	int sum = 0;
	for(int j = 1; j * j <= x; j++)
	{
	    if(j * j == x) sum += j;
	    else if(x%j == 0)
	    {
		sum += j;
		sum += x/j;
	    }
	}
	cout << "Sum of divisors for " << i << " is " << sum << endl;
    }
}

***************************Optimized Version - SQRT version***************************

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int a[n + 5];
    for(int i = 1; i <= n; i++) a[i] = 0;
    
    for(int i = 1; i * i <= n; i++)
    {
        for(int j = i*i; j <= n; j += i)
        {
            if(j == i*i) a[j] += i;
            else
            {
		a[j] += i;
		a[j] += j/i;
	    }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
	cout << "Sum of divisors of " << i << " is " << a[i] << endl;
    }
}

....................Problem: Sieve and Storing Primes in a vector

bool mark[lx];
vector<int> primes;
 
void sieve()
{
    mark[0] = mark[1] = true;
    
    for(int i = 3; i*i <= lx; i++)
    {
	if(!mark[i])
	{
	    for(int j = i*i; j < lx; j += i)
		mark[j] = true;
	}
    }
    
    primes.push_back(2);
    for(int i = 3; i < lx; i += 2)
    {
	if(!mark[i])
	{
	    primes.push_back(i);
	}
    }
}

....................Problem: Prime Factorization

#include<bits/stdc++.h>
using namespace std;

const int lx = 1e6;

bool mark[lx];
vector<int> primes;
 
void sieve()
{
    mark[0] = mark[1] = true;
    
    for(int i = 3; i*i <= lx; i++)
    {
	if(!mark[i])
	{
	    for(int j = i*i; j < lx; j += i)
		mark[j] = true;
	}
    }
    
    primes.push_back(2);
    for(int i = 3; i < lx; i += 2)
    {
	if(!mark[i])
	{
	    primes.push_back(i);
	}
    }
}

void factorize(int n)
{
    vector<pair<int, int> > v;
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= n; i++)
    {
	if(n%primes[i] == 0)
	{
	    int cnt = 0;
	    while(n%primes[i] == 0)
	    {
		n /= primes[i];
		cnt++;
	    }
	    v.push_back({primes[i], cnt});
	}
    }
    if(n > 1) v.push_back({n, 1});
    for(auto it : v) cout << it.first << " " << it.second << endl;;
}

int main()
{
    sieve();
    int n;
    cin >> n;
    factorize(n);
}

....................Problem: Find number of integers from 1 to n are co-prime with n. (Euler Totient Function)

void euler_totient(int n)
{
    int result = n;
    int m = n;
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= n; i++)
    {
	if(n%primes[i] == 0)
	{
	    int cnt = 0;
	    while(n%primes[i] == 0)
	    {
		n /= primes[i];
		cnt++;
	    }
	    result = result - (result / primes[i]);
	}
    }
    if(n > 1) result = result - (result / n);
    cout << "Number of integers co-prime with " << m << " are " << result << endl;
}

....................Problem: Find the summation of integers from 1 to n which are co-prime with n. (Euler Totient Function)
	
void euler_totient(int n)
{
    int result = n;
    int m = n;
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= n; i++)
    {
	if(n%primes[i] == 0)
	{
	    int cnt = 0;
	    while(n%primes[i] == 0)
	    {
		n /= primes[i];
		cnt++;
	    }
	    result = result - (result / primes[i]);
	}
    }
    if(n > 1) result = result - (result / n);

    // Now for summation we have a formula
    // sum = (euler(n) / 2) * n
    
    int sum = (result * m) / 2;
    cout << "Sum of integers which are co-prime with " << m << " is " << sum << endl;
}

....................Problem: Find number of integers from 1 to n that has gcd k with n. (Euler Totient Function)

void euler_totient(int n, int k)
{
    // First divide n/k and then find totient of n/k. That will be the answer.
    // Because which has gcd 1 with n/k, they will have gcd k with (n/k)*k or n obviously
    n /= k;
    int result = n;
    int m = n;
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= n; i++)
    {
	if(n%primes[i] == 0)
	{
	    int cnt = 0;
	    while(n%primes[i] == 0)
	    {
		n /= primes[i];
		cnt++;
	    }
	    result = result - (result / primes[i]);
	}
    }
    if(n > 1) result = result - (result / n);

    cout << result << endl;
}
