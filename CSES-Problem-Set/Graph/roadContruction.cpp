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

// Basic DSU implementation with some adjustments to calculate maxSize of component at any time and number of compenents

class dsu 
{
    private:
        vector<int> parent;
        vector<int> size;
        int count;
        int maxSize;

    public:
        dsu(int n)
        {
            parent = vector<int>(n + 1);
            size = vector<int> (n + 1, 1);
            count = n;
            maxSize = 1;

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

            count--;
            maxSize = max(maxSize, size[par_a]);
        }

        bool isSame(int a, int b)
        {
            int par_a = findParent(a);
            int par_b = findParent(b);

            return par_a == par_b;
        }

        int numComponents()
        {
            return count;
        }

        int maxComponent()
        {
            return maxSize;
        }
};

int solve(void)
{
    int n, m;
    cin >> n >> m;

    dsu myDsu = dsu(n);

    iterate(i,m)
    {
        int a, b;
        cin >> a >> b;

        myDsu.join(a, b);

        cout << myDsu.numComponents() << " " << myDsu.maxComponent() << endl;
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
