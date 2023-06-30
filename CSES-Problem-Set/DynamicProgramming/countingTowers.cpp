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

ll dp[1000001][2];

void pre(void)
{
    dp[1][0] = dp[1][1] = 1;

    for(int i = 2 ; i < 1000001 ; i++)
    {
        dp[i][0] = (dp[i-1][0]*4 % MOD + dp[i-1][1]) % MOD;
	dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1] % MOD) % MOD;
    }

    return;
}

int solve(void)
{
    int n;
    cin >> n;

    cout << (dp[n][0] + dp[n][1]) % MOD;

    return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int t;
    cin >> t;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
