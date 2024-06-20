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

vector<int> topologicalSort(int n, int m, vector<vector<int>>& requirements, vector<int>& numReq)
{
    vector<int> ret;
    queue<int> q;
    for(int i = 1; i <= n; i++) if(numReq[i] == 0) q.push(i);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        
        ret.push_back(current);

        for(auto &itr : requirements[current])
        {
            numReq[itr]--;
            if(numReq[itr] == 0) q.push(itr);
        }
    }

    return ret;
}

int solve(void)
{
    int n , m;
    cin >> n >> m;

    vector<vector<int>> requirements(n + 1);
    vector<int> numReq(n + 1, 0);
    iterate(i,m) 
    {
        int a, b;
        cin >> a >> b;
        requirements[a].push_back(b);
        numReq[b]++;
    }

    vector<int> sorted = topologicalSort(n, m, requirements, numReq);

    if(sorted.size() == n)
    {
        arrout(sorted);
    }
    else 
    {
        cout << "IMPOSSIBLE";
    }

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
