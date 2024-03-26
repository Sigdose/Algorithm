//2785_체인 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,temp;
	vector<int> v;
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end()); //3 4 5 7 9
	int count = N; //현재 체인의 개수 
	int answer = 0; //고리의 최소개수 
	int start = 0; // 가장적은체인부터 시작 
	while(true)
	{
		if(v[start]==1) //한개짜리 고리 
		{
			count-=2; // 체인이 두개가줄었음(한개짜리가 고리로감) 
			answer++; //고리가 하나늘었다 
			start++; //다음체인 
		}
		else
		{
			v[start]--;
			count--;
			answer++;
		}
		
		if(count<=1)
		{
			cout<<answer<<endl;
			return 0;	
		}
	}
	return 0;
}
