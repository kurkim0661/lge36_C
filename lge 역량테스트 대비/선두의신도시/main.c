#include <stdio.h>

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보
int Queue[10000]; // queue 
int visit[20][20];// count array 


int rear = 0;
int front = 0;
/* 상하좌우 */

int pipe[][4] = {	{0,0,0,0},//0
				{0,0,1,1},//1
				{1,1,0,0},//2
				{0,1,0,1},//3
				{0,1,1,0},//4
				{1,0,1,0},//5
				{1,0,0,1},//6
				{1,1,0,1},//7
				{0,1,1,1},//8
				{1,1,1,0},//9
				{1,0,1,1},//10
				{1,1,1,1}};//11


// 상 -> 하 , 하 -> 상, 좌 -> 우 , 우 -> 좌
int pipe_dir[4] = { 1, 0, 3, 2 };

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			scanf("%1x", &map[i][j]);
			visit[i][j] = 0;
		}
	}
}

int main(void){
	int ans = -1;
	int i,j;
	int cnt = 0;
	
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	
	Queue[rear] = X;
	rear = (rear + 1) % 10000;
	Queue[rear] = Y;
	rear = (rear + 1) % 10000;
	cnt ++;
	
	while (rear != front) {
	

		int idx_i = Queue[front];
		front = (front + 1) % 10000; 
		int idx_j = Queue[front];
		front = (front + 1) % 10000;
		
			
	
		for (i = 0; i < 4; i++) {
			
			//if (pipe[map[idx_i][idx_j]][i] != 1) continue;
			
			int tmp_i = idx_i + dr[i];
			int tmp_j = idx_j + dc[i];
			
			if (tmp_i >= 0 && tmp_j >= 0 && tmp_i < N && tmp_j < N) {
			
				for (j = 0; j < 4; j++) {
					
					//if (map[tmp_i][tmp_j] == 0) continue;


					if (pipe[map[idx_i][idx_j]][j] == 1 && pipe[map[tmp_i][tmp_j]][pipe_dir[j]] == 1 && visit[idx_i][idx_j] == 0) {
							printf("%d \n",map[idx_i][idx_j]);
					 	  visit[idx_i][idx_j] = 1;
							Queue[rear] = tmp_i;
							rear = (rear + 1) % 10000;
							Queue[rear] = tmp_j;
							rear = (rear + 1) % 10000;
						
							cnt++;
					} 

				}
			}
			
		}		
	
	}
	
	printf("%d\n", cnt);		//	정답 출력
	return 0;
}

