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

char graph[1001][1001];
int minMoveMonster[1001][1001];
vector<vector<int>> neighbour = {{1,0} , {-1 , 0} , {0 , 1} , {0 , -1}};
pair<int , int> path[1001][1001];
vector<vector<bool>> visited(1001 , vector<bool>(1001 , false));
vector<char> ans;
int n , m;
pair<int , int> dest;


bool canMove (int x , int y)
{
    if(x <= m && x >= 1 && y <= n && y >= 1 && graph[y][x] != '#')
	return true;

    return false;
}

void bfs (int x , int y)
{
    queue<pair<int , int>> q;

    q.push (make_pair(x , y));

    while(!q.empty())
    {
	pair<int , int> current = q.front();
	q.pop();

	x = current.first;
	y = current.second;

	int dist = minMoveMonster[y][x];

	for(int i = 0 ; i < 4 ; i++)
	{
	    int newX = x + neighbour[i][0];
	    int newY = y + neighbour[i][1];

	    if(canMove(newX , newY) && minMoveMonster[newY][newX] > dist + 1)
	    {
		int flag = 0;

		for(int i = 0 ; i < 4 ; i++)
		{
		    int checkX = newX + neighbour[i][0];
		    int checkY = newY + neighbour[i][1];

		    if(canMove(checkX , checkY) && checkX != x && checkY != y && graph[checkY][checkX] == 'M')
		    {
			flag = 1;
			break;
		    }
		}

		if(flag)
		    break;

		minMoveMonster[newY][newX] = dist + 1;

		q.push(make_pair(newX , newY));
	    }
	}
    }

    return ;
}

bool bfsAns(int x , int y)
{
    queue<pair<int , int>> q;

    q.push(make_pair(x , y));
    q.push(make_pair(0 , 0));

    int dis = 0;

    visited[y][x] = true;

    while(!q.empty())
    {
	auto current = q.front();
	q.pop();

	x = current.first;
	y = current.second;

	if(x == 0 && y == 0)
	{
	    dis++;

	    if(!q.empty())
		q.push(make_pair(0 , 0));
	    else
		break;
	    
	    continue;
	}

	if(x == m || x == 1 || y == n || y == 1)
	{
	    dest.first = x;
	    dest.second = y;

	    return true;
	}

	for(int i = 0 ; i < 4 ; i++)
	{
	    int newX = x + neighbour[i][0];
	    int newY = y + neighbour[i][1];

	    if(canMove(newX , newY) && !visited[newY][newX]  && dis + 1 < minMoveMonster[newY][newX])
	    {
		visited[newY][newX] = true;

		path[newY][newX] = current;
		
		q.push(make_pair(newX , newY));
	    }
	}
    }

    return false;
}

char retrace(int fromX ,int fromY , int toX , int toY)
{
    int x = toX - fromX;
    int y = toY - fromY;

    if(x == 1) return 'R';
    if(x == -1) return 'L';
    if(y == 1) return 'D';
    if(y == -1) return 'U';

    return -1;
}

int solve(void)
{
    cin >> n >> m;

    int x , y;

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j =1 ; j <= m ;j++)
        {
	    cin >> graph[i][j];

	    minMoveMonster[i][j] = INT_MAX;

	    if(graph[i][j] == 'M')
		minMoveMonster[i][j] = 0;

	    if(graph[i][j] == 'A')
	    {
		x = j;
		y = i;
	    }
        }
    }


    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(graph[i][j] == 'M')
		bfs(j , i);
        }
    }


    if(bfsAns(x , y))
    {
	cout << "YES" << endl;

	auto current = dest;
	
	while(current.first != x || current.second != y)
	{
	    int fromX = path[current.second][current.first].first;
	    int fromY = path[current.second][current.first].second;


	    ans.push_back(retrace(fromX , fromY , current.first , current.second));

	    current = path[current.second][current.first];
	}

	cout << ans.size() << endl;

	reverse(ans.begin() , ans.end());

	for(auto itr : ans)
	    cout << itr;
    }

    else
	cout << "NO";

     return 0;
}



int main()
{
    int t = 1;

    while(t-- > 0)
    {
        solve();
	cout << endl;
    }

    return 0;
}
