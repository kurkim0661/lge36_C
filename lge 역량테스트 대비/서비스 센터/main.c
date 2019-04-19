#include <stdio.h>

int N, Q, sol;
int T[101];
int engineer[6];
int min_engineer;
int min_idx;
void Input_Data(void){
	int i;
	scanf("%d %d",&N,&Q);	// 엔지니어의 수, 고객의 수
	for(i=0;i<Q;i++){
		scanf("%d",&T[i]);			// 고객의 업무처리 시간
	}
}

int main(void){
	int i;
	int j;
	int min = 501;
	int max = -1;
	Input_Data();				// 입력 함수
	
	for(i = 0; i < N; i++) {  // 각 엔지니어에게 업무 할당(초기화)
		engineer[i] = T[i];
		if(min > engineer[i]) {
			min_idx = i;
			min = engineer[i];
		}
	}
	min = 501;
	for(i = N; i < Q; i++) {
		engineer[min_idx] += T[i];
		min = 501;
		for(j = 0; j < N; j++){
			
			if(min > engineer[j]){
				min = engineer[j];	
				min_idx = j;
			}
		}
	}
	//	코드를 작성하세요
	
	for(i = 0; i < N; i++) {
		if(max < engineer[i]) {
			max = engineer[i];	
		}
	}
	
	

	printf("%d\n",max); 	//	정답 출력

	return 0;
}
