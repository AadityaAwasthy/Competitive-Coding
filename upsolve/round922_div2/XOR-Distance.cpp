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
   ll a , b , r;
   ll i;
   cin >> a >> b >> r;

   for(i = 59 ; i >= 0 ; i--)
   {
       if((a^b) & (1ll << i)) break;
   }

   auto solve = [&] (ll x , ll y , ll i , ll r) -> ll
   {
       if(r < 0) return LLONG_MAX;

       for( ; i >= 0 ; i--)
       {
	   if((r >> i) && (!(x & (1ll << i))) && (y & (1ll << i)))
	   {
	       x ^= (1ll << i);
	       y ^= (1ll << i);
	       r -= (1ll << i);
	   }
       }

       return y - x;
   };

   cout << min(solve(min(a , b) , max(a , b) , i - 1 , r) , solve(max(a , b) ^ (1ll << i) , min(a , b) ^ (1ll << i) , i - 1 , r - (1ll << i)));

   return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
