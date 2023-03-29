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
    int n , q;
    cin >> n >> q;

    vector < vector <int> > prefix (n , vector<int>(n) );

    int sum = 0;
    char temp;

    iterate(i,n)
    {
	iterate(j,n)
	{
	    cin >> temp;

	    if(temp == '*')
		sum++;

	    if(i == 0)
	    {
		prefix[i][j] = sum;
	    }
	    else
	    {
		prefix[i][j] = prefix[i-1][j] + sum;
	    }
	}

	sum = 0;
    }

    while(q-- > 0)
    {
	int y1 , x1 , y2 , x2 ;

	cin >> y1 >> x1 >> y2 >> x2 ;

	int ans = 0;

	ans += prefix[y2 -1 ][x2 - 1];

	if(y1 - 2 >= 0)
	    ans -= prefix[y1-2][x2 - 1];

	if(x1 -2 >= 0)
	    ans -= prefix[y2 - 1][x1 - 2];

	if(y1 - 2 >= 0 && x2 - 2 >= 0)
	    ans += prefix[y1-2][x1-2];

	cout << ans << endl;
    }

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
