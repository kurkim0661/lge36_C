#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 987654321;

int N;//후보자 수
int A[100000 + 10];//기질 값
int precal[100000 + 10];
int left_;
int right_;

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	
}

void solve(void)
{
	int min = MAX;
	int temp = 0;
	int litr = 0;
	int ritr = N-1;
	while(litr < ritr) 
	{
		temp = A[ritr] + A[litr];
		if(min > abs(temp))
		{
			min = temp;
			left_= litr;
			right_= ritr;
		}
		if(temp < 0)
		{
			litr++;
		//	cout<<A[litr]<<endl;
		}
		else if(temp > 0){
			ritr--;
			//cout<<A[ritr]<<endl;
		}
		else break;
	cout<<left_<<" "<<right_<<endl;

	}
	
	return 0;
}
int main(){
	InputData();
	solve();	

	return 0;
}
