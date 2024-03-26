//9205_맥주마시면서 걸어가기 
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
	int x;
	int y;
};
point home;
point festival;
point store[100];
int n;
bool visited[100];

int DFS(int node,int x,int y)
{
	int xdiff = abs(festival.x - x);
	int ydiff = abs(festival.y - y);
	if(xdiff+ydiff<=1000) return 1;
	if(node == n) return 0;
	
	for(int i=0;i<n;i++)
	{
		if(visited[i] == true) continue;
		int dist = abs(store[i].x-x)+abs(store[i].y-y);
		if (dist <= 1000)
		{
			visited[i] = true;
			if(DFS(node+1,store[i].x,store[i].y)) return 1;
		}
	}
	return 0;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		cin>>home.x>>home.y;
		for(int j=0;j<n;j++)
			cin>>store[j].x>>store[j].y;
			
		cin>>festival.x>>festival.y;
		
		int result;
		result = DFS(0,home.x,home.y);
		
		if(result == 1) cout<<"happy\n";
		else cout<<"sad\n";
		for(int j=0;j<100;j++)
			visited[j]=false;
	}
	
	
	return 0; 
}
