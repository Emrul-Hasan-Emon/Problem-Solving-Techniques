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
