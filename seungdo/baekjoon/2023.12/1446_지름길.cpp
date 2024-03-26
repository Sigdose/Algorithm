//1446_Áö¸§±æ 
#include <iostream>
#include <algorithm>
using namespace std;

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,D,map[10002]={0,};
	int from,to,dis;
	vector<pair<int, int> > v[10001];
	cin>>N>>D;
	for(int i=0;i<N;i++)
	{
		cin>>from>>to>>dis;
		v[to].push_back({from,dis});
	}
	map[0] = 0;
	for(int i=1;i<=D;i++)
	{
		map[i] = map[i-1]+1;
		for(auto a:v[i])
		{
			map[i] = min(map[i],map[a.first]+a.second);
		}
	}
	cout << map[D] <<"\n";

	return 0; 
}
