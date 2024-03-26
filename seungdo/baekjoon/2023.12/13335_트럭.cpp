//13335_Ʈ�� 
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	queue<pair<int,int> > q; //first = time , second = weight;
	vector<int> truck;
	int n,w,l,count=0;
	int time=1;
	int bridge_weight=0;
	
	bool flag;
	
	cin>>n>>w>>l;
	
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		truck.push_back(temp);
	}
	int i = 0;

	while(true)
	{
		if(q.empty()==false)
		{
			if(time == q.front().first + w) //�ٸ����̸�ŭ �������� ���������ֱ� 
			{
				bridge_weight -= q.front().second;
				q.pop(); //�ٸ��� ������
				count++; 	//����� Ʈ���� �������� 
				if(count == n) break; //Ʈ���� �� ��������
			}
		}
		if(i< n && bridge_weight+truck[i] <= l) //���� ���������� , �ٸ��� ����Ʈ���� ������ �ߵ����ִٸ� 
		{
			bridge_weight += truck[i];
			q.push(make_pair(time,truck[i])); //���Խð� , �ش�Ʈ������ ���� 
			i++;
		}
		time++;
	}
	cout<<time<<"\n";
	return 0;
}
