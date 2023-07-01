#include<bits/stdc++.h>
using namespace std;
#define iterate(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001
#define endl "\n"
#define deb(x) cout << #x << " = " << x << "\n";
#define arrout(a) for(auto itr : a) cout << itr << " "
#define arrin(a) for(auto& itr : a) cin >> itr;
typedef long long ll;

int solve(void)
{
   ll n; 
   cin >> n;

   ll total = (n * (n + 1)) / 2;

   if(total % 2 == 1)
   {
       cout << 0;
       return 0;
   }

   ll target = total / 2;

   vector<ll> dp(target + 1 , 0);
   dp[0] = 1;


   for(int i = 1 ; i < n ; i++)
   {
       for(int j = target ; j >= 0 ; j--)
       {
           if(dp[j] != 0 && j + i <= target)
	   {
	       dp[i + j] += dp[j];
	       dp[i + j] %= MOD;
	   }
       }
   }

   cout << dp[target];

   return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
