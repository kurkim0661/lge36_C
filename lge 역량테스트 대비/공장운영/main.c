#include <stdio.h>

int N; //��
int S; //�������
int C[50010]; //����
int Y[50010]; //�뷮
int save; //���尳�� 
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
	
	Input_Data();		// �Է� �Լ�
	
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
	
	printf("%lld\n", ans);		// ���� ���
	return 0;
}

