//21610 마법사상어와 비바라기 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M;
int map[51][51]={0};
bool cloudflag[51][51]={false};
vector<pair<int, int> >cloudmap;

int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,-1,-1,0,1,1,1,0,-1};

int right_range(int a)
{
	if(a<1) return N;
	if(a>N) return 1;
	return a;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin >> map[i][j];
		}
	}
	//start
	cloudmap.push_back({N,1});
	cloudmap.push_back({N,2});
	cloudmap.push_back({N-1,1});
	cloudmap.push_back({N-1,2});
	cloudflag[N][1] = true;
	cloudflag[N][2] = true;
	cloudflag[N-1][1] = true;
	cloudflag[N-1][2] = true;
	
	for(int k=0;k<M;k++)
	{
		int direction,distant;
		cin >> direction >> distant;
		//moving
		memset(cloudflag,false,sizeof(cloudflag));
		for(int i=0;i<cloudmap.size();i++)
		{
			int x = cloudmap[i].first;
			int y = cloudmap[i].second;	
			int next_x = x;
			int next_y = y;
			for(int j=0;j<distant;j++)
			{
				next_x = next_x + dx[direction];
				next_y = next_y + dy[direction];
				next_x = right_range(next_x);
				next_y = right_range(next_y);
			}
			cloudmap[i].first  = next_x;
			cloudmap[i].second = next_y;
			cloudflag[next_x][next_y] = true;
			//make rain
			map[next_x][next_y]++;
		}
		//water bug
		for(int i=0;i<cloudmap.size();i++)
		{
			int count = 0;
			int x = cloudmap[i].first;
			int y = cloudmap[i].second;
			
			for(int j=2;j<=8;j+=2)
			{
				int next_x = x + dx[j];
				int next_y = y + dy[j];
				if(next_x < 1 || next_x > N || next_y < 1 || next_y > N) continue;
				if(map[next_x][next_y]>=1) count++;
			}
			map[x][y] += count;
		}
		//clear
		cloudmap.clear();
		//make_cloud
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(cloudflag[i][j] == true) continue;
				if(map[i][j] < 2) continue;
				map[i][j] -=2;
				cloudmap.push_back({i,j});
			}
		}
		memset(cloudflag,false,sizeof(cloudflag));
		for(int i=0;i<cloudmap.size();i++)
		{
			int x = cloudmap[i].first;
			int y = cloudmap[i].second;
			cloudflag[x][y] = true;
		}
		
	}
	
	
	//finish
	int ans = 0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			ans += map[i][j];
		}
	}
	cout << ans << endl;

	return 0;
}
