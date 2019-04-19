#include <stdio.h>

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보
int visit[20][20];
int a[] = {0,12,3,10,6,5,9,11,14,7,13,15};
int dx[] ={-1,1,0,0};
int dy[] ={0,0,-1,1};
int queue[100000];
int front;
int rear;
int cnt;
int zeros;
void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			scanf("%1x", &map[i][j]);
			if(map[i][j] == 0){
				zeros++;
			}
		}
	}
}

int main(void){
	int ans = -1;
	int temp_x;
	int temp_y;
	int nextx;
	int nexty;
	int i;
	int j;
	Input_Data();		//	입력 함수
	queue[rear++] = Y;
	queue[rear++] = X;
	visit[Y][X] = 1;
	cnt++;
	// if(map[X][Y] == 0){
	// 	printf("%d",N*N-zeros);
	// 	return 0;
	// }
	while(front != rear){
		temp_x = queue[front++];
		temp_y = queue[front++];
		for(i=0;i<4;i++){
			nextx = temp_x+dx[i];
			nexty = temp_y+dy[i];
			if(nextx >=0 && nextx < N && nexty >= 0 && nexty < N && visit[nextx][nexty] == 0){
				if(((a[map[temp_x][temp_y]] >> i) & 0x1) == 1){
					if(i%2 == 1){
						j=i-1;
					}
					else{
						j=i+1;
					}

					if(((a[map[nextx][nexty]] >> j) & 0x1) == 1){
						visit[nextx][nexty] = 1;
						cnt++;
						queue[rear++] = nextx;
						queue[rear++] = nexty;
					}
				} 
			} 
		}	
	}	
	ans = N*N-cnt -zeros;
	printf("%d\n", ans);		//	정답 출력
	return 0;
}



