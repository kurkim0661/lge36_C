#include <stdio.h>
#define MAX 100000000
int N, M;//공장 수, 도로 정보 수
//int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D
int ary[101][101];
int a;
int b;
int c;
void InputData(){
	int i;
	
	for (i = 0; i < M; i++){
		scanf("%d %d %d", &a, &b, &c);
		ary[a][b] = c;
		ary[b][a] = c;
	}
}
int main(){
	int i;
	int j;
	int k;
	int min = 10100000;
	int sum = 0;
	int max = 0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++){
			ary[i][j] = MAX;
			if(i==j)ary[i][j] = 0;
		}
	}
	InputData();//	입력 함수
	
	
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (ary[i][k] + ary[k][j] < ary[i][j]) {
					ary[i][j] = ary[i][k] + ary[k][j];
				}
			}
		}
	}
	
//	for (i = 0; i < N; i++){
//			ary[i][i] = 0;
//	}

	
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++){
			if (max < ary[i][j] && i!=j) max = ary[i][j];
			
		}
		if (min > max) {
			min = max;
		}
		max = 0;
	}
	printf("%d\n", min);//	정답 출력
	return 0;
}

