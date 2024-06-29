#include<bits/stdc++.h>
#include <fstream>
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

// Implementation of the kruskal minimum spanning tree algorithm
 
void helper(vector<pair<pair<int, int>, int>>& a)
{
    for(auto& itr : a)
    {
        cout << itr.first.first << " "<< itr.first.second << " " << itr.second << endl;
    }
 
    return;
}
 
class dsu 
{
    private:
        vector<int> parent;
        vector<int> size;
 
    public:
        dsu(int n)
        {
            parent = vector<int>(n + 1);
            size = vector<int> (n + 1, 1);
 
            iterate(i,n)
            {
                parent[i + 1] = i + 1;
            }
        }
 
        int findParent(int a)
        {
            if(parent[a] == a)
                return a;
            return parent[a] = findParent(parent[a]);
        }
 
        void join(int a, int b)
        {
            int par_a = findParent(a);
            int par_b = findParent(b);
 
            if(par_a == par_b) return;
 
            if(size[par_a] < size[par_b])
                swap(par_a, par_b);
 
            parent[par_b] = par_a;
            size[par_a] += size[par_b];
        }
 
        bool isSame(int a, int b)
        {
            int par_a = findParent(a);
            int par_b = findParent(b);
 
            return par_a == par_b;
        }
};
 
int solve(void)
{
    int n, m;
    cin >> n >> m;
 
    vector<pair<pair<int, int>, int>> edges(m);
 
    iterate(i,m)
    {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }
 
    auto cmp = [] (pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) -> bool
    {
        return a.second < b.second;
    };
 
    sort(edges.begin() , edges.end(), cmp);
 
    ll ans = 0;
    dsu myDsu = dsu(n);
 
    for(auto &itr : edges)
    {
        int a = itr.first.first;
        int b = itr.first.second;
        ll cost = itr.second;
 
        if(myDsu.isSame(a, b)) continue;
        myDsu.join(a, b);
        ans += cost;
    }
 
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(!myDsu.isSame(i + 1, i + 2))
        {
            cout << "IMPOSSIBLE";
            return 0;
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
    t = 1;
 
    while(t-- > 0)
    {
        solve();
        cout << endl;
    }
 
    return 0;
}
