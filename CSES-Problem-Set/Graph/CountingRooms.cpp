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

vector<vector<int>> neighbours = {{0 , 1} , {0 , -1} , {1 , 0}, {-1 , 0}};

int n , m;

bool isValid(int x , int y)
{
    if(x < 0 || x >= m || y < 0 || y >= n)
	return false;

    return true;
}

void dfs(int x , int y , vector<vector<char>>& graph ,vector<vector<bool>>& visited)
{
    visited[y][x] = true;

    for(int i = 0 ; i < 4 ; i++)
    {
	int nextX = x + neighbours[i][0];
	int nextY = y + neighbours[i][1];

	if(isValid(nextX , nextY) && !visited[nextY][nextX] && graph[nextY][nextX] == '.')
	    dfs(nextX , nextY , graph , visited);
    }

    return ;
}

int main()
{
    cin >> n >> m ;

    vector<vector<char>> graph(n , vector<char>(m));

    iterate(i,n)
    {
	iterate(j,m)
	{
	    cin >> graph[i][j];
	}
    }

    vector<vector<bool>> visited(n , vector<bool>(m , false));

    int countRooms = 0;

    iterate(i,n)
    {
	iterate(j,m)
	{
	    if(graph[i][j] == '.' && !visited[i][j])
	    {
		countRooms++;

		dfs(j , i , graph , visited);
	    }
	}
    }


    cout << countRooms << endl;

    return 0;
}
