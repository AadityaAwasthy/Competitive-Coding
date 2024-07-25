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

// This problem was solved using eulerian tours.

int solve(void)
{
    int n;
    cin >> n;

    if(n == 1) {
        cout << "10";
        return 0;
    }

    vector<vector<int>> g((1 << (n - 1)));

    for(int i = 0; i < (1 << (n - 1)); i++) {
        int son = (i << 1) % (1 << (n - 1));

        g[i].push_back(son);
        g[i].push_back(son|1);
    }

    vector<int> path;
    stack<int> stk;
    stk.push(0);

    while(!stk.empty()) {
        int current = stk.top();

        if(!g[current].empty()) {
            stk.push(g[current].back());
            g[current].pop_back();
        } else {
            path.push_back(current & 1);
            stk.pop();
        }
    }

    for(int i = 0; i < n - 2; i++) path.push_back(0);

    for(auto &itr: path) cout << itr;

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
