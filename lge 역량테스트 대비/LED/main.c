#include <stdio.h>

int N;//LED ��
int S[100000 + 10];//LED ����
int P[100000 + 10];
int cnt = 1;
int cur_cnt = 1;
int prev_cnt = 1;
int max_cnt;
void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &S[i]);
	}
}

int main(void){
	int ans = -1;
	int i;
	int j;
	int cnt_same = 1;
	
	Input_Data();		//	�Է� �Լ�
	for(i=0;i<N;i++){
		if(S[i] != S[i+1]){
			cnt++;
			cur_cnt = cnt;
			if(S[i+1] == S[i+2]){
			prev_cnt = cnt;	
			}
		}
		else if(S[i] == S[i+1]){
			cnt = 1;
			
			if(S[i+1] != S[i+2] &&S[i] != S[i-1]){
						
			}
		}
		
		if(S[i+1] != S[i+2] && S[i] == S[i+1]){
				
		}
	}
	//	�ڵ带 �ۼ��ϼ���
	
	
	
	
	printf("%d\n", ans);		//	���� ���
	return 0;
}

