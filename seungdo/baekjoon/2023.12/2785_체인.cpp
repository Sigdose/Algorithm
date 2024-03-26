//2785_ü�� 
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
	int count = N; //���� ü���� ���� 
	int answer = 0; //���� �ּҰ��� 
	int start = 0; // ��������ü�κ��� ���� 
	while(true)
	{
		if(v[start]==1) //�Ѱ�¥�� �� 
		{
			count-=2; // ü���� �ΰ����پ���(�Ѱ�¥���� ���ΰ�) 
			answer++; //���� �ϳ��þ��� 
			start++; //����ü�� 
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
