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
   int n , k , d;
   cin >> n >> k >> d;

   vector<int> arr(n) , days(k);
   iterate(i,n) cin >> arr[i];
   iterate(i,k) cin >> days[i];

   int ans = INT_MIN;

   for(int i = 1 ; i <= min(2*n , d) ; i++)
   {
       int count = 0;

       iterate(j,n)
       {
	   if(arr[j] == j + 1) count++;
       }

       ans = max(ans , count + ((d - i)/2));

       iterate(j,days[(i - 1)%k])
       {
	   arr[j]++;
       }
   }

   cout << ans;

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
