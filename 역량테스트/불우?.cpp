#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int P[10000 + 10];
int T[10000 + 10];
int checkpoint[10000 + 10];
int ret = 0;
int max1 = -1;
pair<int, int> p[10000 + 10];
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

bool cmp1(int a, int b)
{
	return P[a]>P[b];
}
void InputData(void)
{
	memset(checkpoint,0,sizeof(checkpoint));
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>P[i];
	}

	for(int i = 0; i < N; i++)
	{
		cin>>T[i];
		if(max1 < T[i])
		{
			max1 = T[i];
		}
	}
	for(int i =0; i < N; i++)
	{
		p[i] = make_pair(P[i],T[i]);
	}
	return ;
}
void solve(void)
{
	for(int i = 0; i < N; i++)
	{
		if(checkpoint[p[i].second] == 0)
		{
			checkpoint[p[i].second] = p[i].first;
			ret += checkpoint[p[i].second];
			//cout<<ret<<"위치"<<p[i].second<<endl;
		}
		else 
		{
			for(int j = 0; j < N; j++)
			{
				if(p[i].second - j <= 0)
				{
					break;
				}
				if((checkpoint[p[i].second - j]) == 0)
				{
					checkpoint[p[i].second - j] = p[i].first;
					ret += p[i].first;
					//cout<<ret<<"위치"<<p[i].second-j<<endl;
					break;
				}
				else
				{
					if(checkpoint[p[i].second - j] < p[i].first)
					{
						ret -= checkpoint[p[i].second - j];
						cout<<ret<<"위치."<<p[i].second-j<<endl;
						checkpoint[p[i].second -j] = p[i].first;
						ret += p[i].first;
						//cout<<ret<<"위치"<<p[i].second-j<<endl;
					}
				}
			}
			
		}
	}
}

int main(void)
{
	InputData();
	sort(p, p + N, cmp);
#if 0
	for(int i = 0; i < N; i++)
	{
		cout<<p[i].first<<" ";
	}
	cout<<endl;
	for(int i = 0; i < N; i++)
	{
		cout<<p[i].second<<" ";
	}
	cout<<endl;
	solve();
	for(int i = 1; i < max1 + 1; i++)
	{
		cout<<checkpoint[i]<<" ";
		
	}
	cout<<endl;
#endif
	cout<<ret<<endl;
	return 0;
}
