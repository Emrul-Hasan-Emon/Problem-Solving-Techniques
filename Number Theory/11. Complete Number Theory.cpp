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


