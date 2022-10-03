#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(n) for(int i = 0 ; i < n ; i++)
typedef long long ll;
#define MOD 1000000007
#define MAXN 1000001

int largestDigit(int number)
{
    int largestDigit = INT_MIN;
    int digit;

    while(number != 0)
    {
        digit = number%10;
        number /= 10;

        if(digit > largestDigit)
            largestDigit = digit;
    }

    return largestDigit;
}

int main()
{
    int n;
    cin>>n;

    int stepCount = 0;

    while(n != 0)
    {
        n -= largestDigit(n);
        stepCount++;
    }

    cout<<stepCount<<endl;
}