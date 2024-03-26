//20056_마법사상어와파이어볼 
#include<iostream>
#include<vector>
using namespace std;

int dy[] = {0,1,1,1,0,-1,-1,-1};
int dx[] = {-1,-1,0,1,1,1,0,-1};
int N,M,K;

struct fireball{
	int m,s,d;
	//s 속력
	//d 방향 
};
vector<fireball> fireBall[51][51];

int fixRange(int x)
{
	if(x < 1) return x+N;
	else if(x > N) return x-N;
	return x;
}
void move()
{
	vector<fireball> ball[51][51];
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=0;k<fireBall[i][j].size();k++)  
			{	//전체맵을 돌며 파이어볼을 찾아서 사이즈(k)만큼 반복
				int s = fireBall[i][j][k].s%N;
				int d = fireBall[i][j][k].d;
				
				int nx = i+dx[d] * s;
				int ny = j+dy[d] * s;
				nx = fixRange(nx);
				ny = fixRange(ny);
				
				ball[nx][ny].push_back(fireBall[i][j][k]);
			}
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			fireBall[i][j].clear();
			fireBall[i][j] = ball[i][j];
		}
	}
}

void divide()
{
	vector<fireball> ball[51][51];
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(fireBall[i][j].size()==1)
			{
				ball[i][j] = fireBall[i][j];
			}
			else if(fireBall[i][j].size() >= 2)
			{
				int totalS = 0;
				int totalM = 0;
				bool even = false;
				bool odd = false;
				
				for(int k=0;k<fireBall[i][j].size();k++)
				{
					int dir = fireBall[i][j][k].d;
					if(dir % 2 == 0) even = true;
					else odd = true;
					
					totalS += fireBall[i][j][k].s;
					totalM += fireBall[i][j][k].m;
				}
				int m = totalM/5;
				int s = totalS/fireBall[i][j].size();
				int dir = even && odd ? 1 : 0;
				if (m>0)
				{
					for(int d=dir;d<8;d+=2)
						ball[i][j].push_back({m,s,d});
				}
			}
			
			fireBall[i][j].clear();
			fireBall[i][j] = ball[i][j];
		}
		
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int map[51][51] = {0};

	
	cin >> N >> M >> K;
	for(int i=0;i<M;i++)
	{
		int x,y,m,s,d;
		cin>>x>>y>>m>>s>>d;
		fireBall[x][y].push_back({m,s,d});
	}
	for(int i=0;i<K;i++) //k번 이동 
	{
		move();
		divide();
	}
	long long total = 0LL;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			for(int k=0;k<fireBall[i][j].size();k++)
			{
				total += fireBall[i][j][k].m;
			}
		}
	}
	cout << total;
    
    return 0;
}
