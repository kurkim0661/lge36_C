#include <stdio.h>

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량
int save; //저장개수 
void Input_Data(void){
	int i;
	scanf("%d %d", &N, &S);
	for(i=0 ; i<N ; i++){
		scanf("%d %d", &C[i], &Y[i]);
	}
}

int main(void){
	long long ans = 0;
	int i;
	int j;
	
	Input_Data();		// 입력 함수
	
	for(i=0;i<N;i++){
		ans+=C[i]*Y[i];
//		if(save != 0){
//			save-=Y[i];	
//		}
		
		for(j=i+1;(C[j]-C[i])>(j-i)*S && j<N;j++){
			ans+=C[i]*Y[j] + (j-i)*S*Y[j];
//			save+=Y[j];
		}
		i=j-1;
	}
	
	printf("%lld\n", ans);		// 정답 출력
	return 0;
}

