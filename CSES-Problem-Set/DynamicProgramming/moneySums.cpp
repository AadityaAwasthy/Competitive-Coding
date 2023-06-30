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
   int n;
   cin >> n;

   vector<int> arr(n);
   iterate(i,n) cin >> arr[i];

   vector<bool> dp(100001 , false);
   dp[0] = true;

   int ans = 0;
   int prev = 0;

   for(int i = 0 ; i < n ; i++)
   {
       for(int j = prev ; j >= 0 ; j--)
       {
           if(dp[j] && !dp[j + arr[i]])
	   {
	       dp[j + arr[i]] = true;
	       ans++;
	   }
       }

       prev += arr[i];
   }

   cout << ans << endl;

   for(int i = 1 ; i <= prev ; i++)
   {
      if(dp[i]) cout << i << " ";
   }

   return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
