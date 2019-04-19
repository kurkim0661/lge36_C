#include <stdio.h>
#define MAX 10000

int N;//직원 수
int S;//시작 직원 번호
int M;
int check[MAX+1];
int ary[MAX+1];

void InputData(){
	scanf("%d %d %d", &N, &S, &M);
}
int main(){
	int i;
	int j=0;
	int next;
	int cnt;
	int Cntt =0;
	
	InputData();//	입력 함수
	next = S;
	Cntt = N;
	for(i=1; i<=N; i++){
		check[i] = 0;	
	}
	for(i=1; i<=N; i++){
		cnt = 0;
		while(1){
			
			// printf("%d ",next);
			if(check[next] == 0){
				if(Cntt == 1){
				check[next] = 1;	
					break;
			}
				cnt++;
				// printf("%d ",cnt);
				if(cnt >= M){
					// next++;
					// if(next > N){
					// 	next =1;	
					// }
					check[next] = 1;
					Cntt--;
					break;
				}
			}
			next++;
			if(next > N){
				next =1;	
			}
		}
		printf("%d ",next);
		}
	return 0;
}
