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

int n , m;

vector<vector<int>> mv = {{1, 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

bool isValid(int x , int y)
{
    if(x < 0 || y < 0 || x >= m || y >= n)
	return false;

    return true;
}

char move(int i)
{
    if(i == 0)
	return 'R';
    if(i == 1)
	return 'L';
    if(i == 2)
	return 'D';
    
    return 'U';
}

int index(char a)
{
    if(a == 'R')
	return 0;
    if(a == 'L')
	return 1;
    if(a == 'D')
	return 2;

    return 3;
}
bool find(int x, int y, vector<vector<char>> &graph , vector<vector<bool>> &visited , vector<vector<char>> &path)
{
    queue<pair<int , int>> q;

    q.push(make_pair(x , y));

    visited[y][x] = true;

    while(!q.empty())
    {
	auto current = q.front();
	q.pop();

	x = current.first;
	y = current.second;


	iterate(i,4)
	{
	    int newX = x + mv[i][0];
	    int newY = y + mv[i][1];

	    if(isValid(newX ,newY) && !visited[newY][newX])
	    {
		path[newY][newX] = move(i);

		if(graph[newY][newX] == 'B')
		    return true;

		if(graph[newY][newX] == '.')
		{
		    visited[newY][newX] = true;

		    q.push(make_pair(newX , newY));
		}
	    }
	}
    }

    return false;
}

void findPath(int x , int y , vector<vector<char>> &graph , vector<vector<char>>&path, vector<char> &ans)
{
    while(graph[y][x] != 'A')
    {
	int id = index(path[y][x]);

	ans.push_back(path[y][x]);

	x = x + (-1)*mv[id][0];
	y = y + (-1)*mv[id][1];
    }

    return ;
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> graph(n , vector<char>(m));
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    vector<vector<char>> path(n , vector<char>(m, 'N'));

    int x , y;
    int bx , by;

    iterate(i,n)
    {
	iterate(j,m)
	{
	    cin >> graph[i][j];

	    if(graph[i][j] == 'A')
	    {
		x = j;
		y = i;
	    }

	    if(graph[i][j] == 'B')
	    {
		bx = j;
		by = i;
	    }
	}
    }

    if(find(x , y , graph , visited , path))
    {
	cout << "YES" << endl;
	
	vector<char> ans;
	findPath(bx , by , graph , path , ans);

	cout << ans.size() << endl;

	reverse(ans.begin() , ans.end());

	for(auto itr : ans)
	    cout << itr;
    }
    else
    {
	cout << "NO";
    }

    cout << endl;

    return 0;
}
