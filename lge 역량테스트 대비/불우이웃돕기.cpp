#include <iostream>
#include <cstring>
using namespace std;

int N;//보내려는 물품 개수
int num[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
int C[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
int sol[10];//보내는 BOX 개수
int presum[10];
int count[453320];
const int MAX = 987654321;
void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}
void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}

#if 1
int solve(int n)
{
	int &ret = count[n];
	if(n == 0)
	{
		return 0;
	}
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < 10; i++)
	{
		if(n >= num[i] && C[i] > 0)
		{
			--C[i];
			if(n-num[i] < 0)
			{
				continue;
			}
			if(presum[i] >= n)
			ret = max(ret, 1 + solve(n-num[i]));
			C[i]++;
		}
	}

	return ret;
}
void reconstruct(int n) 
{
	for(int i = 9; i >= 0; i--)
	{
		if(n-num[i] < 0)
		{
			continue;
		}
		if(solve(n) == (solve(n-num[i]) + 1))
		{
		//	cout<<"i는 : "<<i<<endl;
			sol[i]++;
			reconstruct(n-num[i]);
			break;
		}
	}
	return ;
}
#endif
int main(){
	int ans = -1;
	memset(count, -1, sizeof(count));
	InputData();//	입력 함수
	presum[0] = C[0];
	for(int i = 1; i < 10; i++)
	{
		presum[i] = presum[i - 1] + C[i]*num[i];
	}
	ans = solve(N);
	reconstruct(N);
	//	코드를 작성하세요


	OutputData(ans);//	출력 함수

	return 0;
}
