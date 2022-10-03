#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(n) for(int i = 0 ; i < n ; i++)
typedef long long ll;
#define MOD 1000000007
#define MAXN 1000001

int main()
{
    int n,x;
    cin>>n>>x;

    int coins[n];
    iterate(n) cin>>coins[i];

    int DP[x+1];
    iterate(x+1) DP[i] = 0;
    DP[0] = 1;

    for(int coin : coins)
    {
        iterate(x+1)
        {
            if(i-coin >= 0)
            {
                DP[i] += DP[i - coin];
                DP[i] %= MOD;
            }
        }
    }

    cout<<DP[x]<<endl;
}