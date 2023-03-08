#include<bits/stdc++.h>
using namespace std;
#define range(a,b,c,i) for(int i = a ; i < b ; i += c)
#define iterate(i,n) for(int i = 0 ; i < n ; i++)
#define INF 1e9
#define MOD 1000000007
#define MAXN 1000001
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define pi(x) printf("%d ",x)
#define endl "\n"
#define deb(x) cout << #x << " = " << x << "\n";
#define arrout (a) for(auto itr : a) cout << itr << " "
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

void makeSet(vector<int> &dsu)
{
    for(int i = 0 ; i < dsu.size() ; i++)
    {
        dsu[i] = -1;
    }

    return ;
}

int find (vector<int> &dsu , int current)
{
    if(dsu[current] < 0)
	return current;

    return find (dsu , dsu[current]);
}

void unionSet (vector<int> &dsu , int root1 , int root2)
{
    root1 = find(dsu , root1);
    root2 = find(dsu , root2);

    if(root1 == root2)
	return ;

    if(dsu[root2] < dsu[root1])
    {
	dsu[root2] += dsu[root1];
	dsu[root1] = root2;
    }
    else
    {
	dsu[root1] += dsu[root2];
	dsu[root2] = root1;
    }

    return ;
}


int main()
{
    int n , m;
    cin >> n >> m;

    vector<int> dsu(n + 1);
    makeSet(dsu);

    while(m-- > 0)
    {
	int a , b;
	cin >> a >> b;

 	unionSet(dsu , a, b);
    }

    int global = find(dsu , 1);
    
    vector < pair <int,int> > ans;

    for(int i = 2 ; i <= n ; i++)
    {
	int current = find(dsu , i);

	if(current == global)
	    continue;

	ans.push_back(make_pair(1 , i));
	
	dsu[current] = global;
    }

    cout << ans.size() << endl;

    for(auto itr : ans)
    {
	cout << itr.first << " " << itr.second << endl;
    }

  return 0;
}
