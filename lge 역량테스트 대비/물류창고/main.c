#include <stdio.h>
int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D
int doro[102][102];

void InputData(){
	int i;
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			if(i!=j) doro[i][j] = 1000;
		}
	}
	
	for (i = 0; i < M; i++){
		scanf("%d %d %d", &A[i], &B[i], &D[i]);
		doro[A[i]][B[i]] = D[i];
		doro[B[i]][A[i]] = D[i];
	}
}
int main(){
	int ans = -1;
	InputData();//	입력 함수
	
	for(int k=1; k<=N; k++){
		for(int i=1; i<=N; i++){
			if(k==i) continue;
			for(int j=1; j<i; j++){
				if(k==j) continue;
					if(doro[i][j] > doro[i][k] + doro[k][j]){
						doro[i][j] = doro[i][k] + doro[k][j];
						doro[j][i] = doro[i][k] + doro[k][j];
					}
			}
		}
	}
	
	ans = 10000;
	for(int i=1; i<=N; i++){
		int cur = 0;
		for(int j=1; j<=N; j++){
			if(doro[i][j] > cur) cur = doro[i][j];
		}
		if(ans > cur) ans = cur;
	}

	printf("%d\n", ans);//	정답 출력
	return 0;
}

