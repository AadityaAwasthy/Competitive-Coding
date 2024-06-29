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


//Slighly tricky implementation of dfs, there two scenarios in this problem for every node it could either be:-
//-part of a cycle so we want it to have the cycle length as the answer
//-Not part of a cycle but ultimately will get connected to a cycle somewhere down the graph
//
//For the first part , when we encounter a node that is has not been visited and is part of a cycle, it can be inferred that none of its other node in the cycle have been visited, so we run dfs marking everynode with the time we came into it when we see a node that has been visited in the current path we calculate the length of the cycle with the help of the time variable and assign that value to every node in the cycle
//
//for the other case when we start traversing this type of node either it will connect to a previously discovered cycle or it will need to discover one itself, when it needs to discover the cycle , we will use a variable during backtracking to notify if we are in a cycle or not and update the done variable
void dfs(int current, int count, vector<int>& g, vector<int>& current_dfs, vector<int>& done, int& cycle)
{
    int next = g[current];
    current_dfs[current] = count;

    if(done[next] != -1)
    {
        done[current] = done[next] + 1;
        return;
    }

    if(current_dfs[next] != -1)
    {
        if(next == current)
        {
            done[current] = 1;
            return;
        }

        cycle = next;
        done[current] = current_dfs[current] - current_dfs[next] + 1;
        return;
    }

    dfs(next, count + 1, g, current_dfs, done, cycle);

    if(cycle == -1)
    {
        done[current] = done[next] + 1;
        return;
    }
    else 
    {
        done[current] = done[next];

        if(current == cycle)
        {
            cycle = -1;
            return;
        }

        return;
    }

    return;
}

int solve(void)
{
    int n;
    cin >> n;

    vector<int> g(n + 1);
    iterate(i,n) cin >> g[i + 1];

    vector<int> current_dfs(n + 1, -1);
    vector<int> done(n + 1, -1);

    iterate(i,n)
    {
        if(done[i + 1] != -1) continue;

        int cycle = -1;
        dfs(i + 1, 1, g, current_dfs, done, cycle);
    }

    iterate(i,n) cout << done[i + 1] << " ";

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
