#include <stdio.h>

int N;				//	����� ����
int P[310];		//	P[i]: i ����� ����� �� ��� ����
int sol;			//	����
int sum[310];
int main(void){
	int i;
	int j;
	int max;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &P[i]);
	sum[0] = 0;
	sum[1] = P[0];
	sum[2] = P[0]+P[1];
	
	for(i=3;i<=N;i++){
		sum[i] = P[i-1]+P[i-2]+sum[i-3];
		if(sum[i] < P[i-1]+sum[i-2]){
			sum[i] = P[i-1]+sum[i-2];
		}
	}
    printf("%d", sum[N]);	//	���� ���
    return 0;
}
