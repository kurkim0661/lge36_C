#include <stdio.h>

int N, Q, sol;
int T[101];
int engineer[6];
int min_engineer;
int min_idx;
void Input_Data(void){
	int i;
	scanf("%d %d",&N,&Q);	// �����Ͼ��� ��, ���� ��
	for(i=0;i<Q;i++){
		scanf("%d",&T[i]);			// ���� ����ó�� �ð�
	}
}

int main(void){
	int i;
	int j;
	int min = 501;
	int max = -1;
	Input_Data();				// �Է� �Լ�
	
	for(i = 0; i < N; i++) {  // �� �����Ͼ�� ���� �Ҵ�(�ʱ�ȭ)
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
	//	�ڵ带 �ۼ��ϼ���
	
	for(i = 0; i < N; i++) {
		if(max < engineer[i]) {
			max = engineer[i];	
		}
	}
	
	

	printf("%d\n",max); 	//	���� ���

	return 0;
}
