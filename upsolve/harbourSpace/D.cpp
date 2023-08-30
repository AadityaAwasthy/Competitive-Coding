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

   vector<string> arr(n);

   iterate(i,n)
   {
       cin >> arr[i];
   }

   vector<vector<vector<int>>> prefix(n , vector<vector<int>>(n , vector<int>(3 , 0)));

   int ans = 0;

   for(int i = 0 ; i < n ; i++)
   {
       for(int j = 0 ; j < n ; j++)
       {
	   int current = 0;

	   for(int k = 0 ; k < 3 ; k++)
	   {
	       current += prefix[i][j][k];
	   }

	   if(i + 1 < n)
	   {
	       if(j - 1 >= 0)
	       {
		   prefix[i + 1][j - 1][0] = prefix[i][j][0];
	       }

	       if(j + 1 < n)
	       {
		   prefix[i + 1][j + 1][2] = prefix[i][j][2];
	       }

	       prefix[i + 1][j][1] = current; 
	   }

           if((arr[i][j] == '1' && current % 2 == 0) || (arr[i][j] == '0' && current % 2 == 1))
	   {
	       ans++;

	       if(i + 1 < n)
	       {
		   if(j - 1 >= 0) prefix[i + 1][j - 1][0]++;
		   if(j + 1 < n) prefix[i + 1][j + 1][2]++;
		   prefix[i + 1][j][1]++;
	       }
	   }
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
