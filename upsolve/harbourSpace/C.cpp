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

   int prev;

   vector<int> arr;

   while(n != 0)
   {
       arr.push_back(n);

       prev = n;

       n -= n & (-n);
   }

   n = prev;

   while(n != 1)
   {
       n /= 2;

       arr.push_back(n);
   }

   cout << arr.size() << endl;
   for(auto &itr : arr) cout << itr << " ";

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
