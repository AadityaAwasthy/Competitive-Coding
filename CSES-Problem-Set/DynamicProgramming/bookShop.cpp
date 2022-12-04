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
    int n,x;

    cin >> n >> x;

    int price[n] ;
    int pages[n] ;

    iterate(n) cin >> price[i];
    iterate(n) cin >> pages[i];

    vector<vector<int>> dp(n+1 , vector<int>(x+1,0));

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= x ; j++)
        {
            dp[i][j] = dp[i-1][j] ;

            int left = j - price[i-1];

            if(left >= 0)
            {
                dp[i][j] = max(dp[i][j] , dp[i-1][left] + pages[i-1]);
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}