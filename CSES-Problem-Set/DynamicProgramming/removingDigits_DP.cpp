#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(n) for(int i = 0 ; i < n ; i++)
typedef long long ll;
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001

int main()
{
    int n;
    cin>>n;

    int DP[n+1];
    iterate(n+1) DP[i] = INF;
    DP[0] = 0;

    for(int number = 1 ; number <= n ; number++)
    {
        int temp = number;

        while(temp != 0)
        {
            int digit = temp%10;

            DP[number] = min(DP[number] , DP[number - digit] + 1);

            temp /= 10;
        }
    }

    cout<<DP[n];
}