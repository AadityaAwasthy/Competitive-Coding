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

ll trie[1000005][26] = {0};
bool isEnd[1000005] = {false};
ll nextIndex = 0;

ll dp[100005] = {0};

void insert(string s)
{
    ll current = 0;

    for(ll i = 0 ; i < s.length() ; i++)
    {
        ll childIndex = s[i] - 'a';

	if(!trie[current][childIndex]) trie[current][childIndex] = ++nextIndex;

	current = trie[current][childIndex];
    }

    isEnd[current] = true;

    return ;
}

string inp;

void search(ll index)
{
    ll current = 0;

    for(ll i = index ; i < inp.size() ; i++)
    {
        ll childIndex = inp[i] - 'a';

	if(!trie[current][childIndex]) return;

	current = trie[current][childIndex];

	if(isEnd[current])
	{
	    dp[i+1] += dp[index];

	    dp[i+1] %= MOD;
	}

    }

    return;
}


int solve(void)
{
    cin >> inp;

    int n ;
    cin >> n;

    iterate(i,n)
    {
	string temp;
	cin >> temp;

	insert(temp);
    }

    dp[0] = 1;

    for(int i = 0 ; i < inp.size() ; i++)
    {
	search(i);
    }

    cout << dp[inp.size()] <<  endl;

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
