#include <stdio.h>

int N;//�ǹ� ��
int H[80010];//�ǹ� ����
int curvh[80010];
int pos[80010];
int top;
int a[80010];
 
void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%d", &H[i]);
	}
}

int main(void){
	long long ans = 0;
	int i;
	int j;
	int max;
	Input_Data();		//	�Է� �Լ�
	a[N-1] = 0; //�ʱⰪ�� �� �� �ִ°� 0 
	max = H[N-1]; //�ʱⰪ�� MAX�� �����Ѵ�. 
	for(i=0;i<N-1;i++){
		if(H[N-1-i]<H[N-1-(i+1)]){ // ���� ���� �� ũ�ٸ�? 
			if(H[N-1-(i+1)] > max){
				max = H[N-1-(i+1)];
				a[N-1-(i+1)] = i+1;  
			}
			else{
				for(j = top-1; j>=0 ;j--){
					if(H[N-1-(i+1)] <= H[pos[j]]){
					break;
					}
				}
				a[N-1-(i+1)] = pos[j] - (N-1-(i+1))-1;
			}
			
		}
		else{
			a[N-1-(i+1)] = 0;
			pos[top++] = N-1-i;
		}
		ans += a[N-1-(i+1)];
	}
	
	
	
	
	printf("%lld\n", ans);		//	���� ���
	return 0;
}

