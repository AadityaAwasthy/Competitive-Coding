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

vector<vector<int>> dp(5000 , vector<int>(5000 , -1));

vector<vector<int>> op = {{1 , 1} , {1 , 0} , {0 , 1}};

int editDistance(string &x , string &y , int a , int b)
{
    if(a == -1)
	return b + 1;

    if(b == -1)
	return a + 1;

    if(dp[a][b] != -1)
	return dp[a][b];

    if(x[a] == y[b])
	return dp[a][b] = editDistance(x , y , a - 1 , b - 1);

    dp[a][b] = INT_MAX;

    for(int i = 0 ; i < 3 ; i++)
    {
        dp[a][b] = min (dp[a][b] , editDistance(x, y , a - op[i][0] , b - op[i][1]) + 1);
    }

    return dp[a][b];
}


int solve(void)
{
    string x , y;
    cin >> x >> y;

    int a = x.length() - 1;
    int b = y.length() - 1;

    cout << editDistance(x , y , a , b);

    return 0;
}



int main()
{
    int t;

    t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
