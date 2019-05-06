//데이터를 받아야 하는데 그걸 문자열 형태로 받았어야 했는데 왜 문자 형태로 받았을까.. 의문이다.
// 풀이를 간단히 써보면 일단 물과 비버를 동시에 큐에 집어넣는데 물의 좌표를 먼저 집어넣어서 물이 먼저 자리를 차지하게 만든다.
// 그리고  check 배열에서 비버는 1 물은 -1 로 실행하여서 체크를 진행한다. 물은 비버가 갔던 길을 갈 수 있으니까!
// 이런 식으로 BFS 를 돌리면 답이 나오게 된다. 는 것이 나의 가설 만들기가 넘나리 귀찮다. 


#include <stdio.h>
#include <stdlib.h>
#define MAX 1<<10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int R;
int C;
int map[MAX][MAX];
int check[MAX][MAX];
int length[MAX][MAX];
int front;
int rear;
int queue[MAX];

int dx[] = {0,0,1,-1}; //동 서 남 북 순  
int dy[] = {1,-1,0,0};

void printmap(void);

int main(int argc, char *argv[]) {
	int i;
	int j;
	int tempx;
	int tempy;
	char buf[51];
	int temp2x;
	int temp2y;
	int min = MAX;
	
	int sx;
	int sy;
	int wx;
	int wy;
	int dstx;
	int dsty;
	scanf(" %d %d",&R,&C); //행과 열을 입력
 
    for (int i = 0; i < R; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < C; ++j) {
            if (buf[j] == '.') // 길
                continue;
            else if (buf[j] == 'D') { // 비버굴
                dstx = i+1;
                dsty = j+1;
                map[i+1][j+1] = -3;
            }
            else if (buf[j] == 'S') { // 고슴도치
                sx = i+1;
                sy = j+1;
            }
            else if (buf[j] == 'X') // 돌
                map[i+1][j+1] = -2;
            else { // 물 
                wx = i+1;
                wy = j+1;
                map[i+1][j+1] = -1;
            }
        }
    }
 
	
	queue[rear++] = wx;
	queue[rear++] = wy;
	queue[rear++] = sx;
	queue[rear++] =	sy;
	
	while(rear != front) {
		
		
		
		tempx = queue[front++];
		tempy = queue[front++];
		
		if(tempx == dstx && tempy == dsty) {
			printf("%d",map[tempx][tempy]);
		}
		
		for(i = 0;i < 4; i++) {
			temp2x = tempx + dx[i];
			temp2y = tempy + dy[i];
			
			if(temp2x >= 1 && temp2x <= R && temp2y >= 1 && temp2y <= C && map[tempx][tempy] != -1) { //고슴도치의 움직임 
				if(map[temp2x][temp2y] == 0 || map[temp2x][temp2y] == -3)  {
					queue[rear++] = temp2x;
					queue[rear++] = temp2y;
					map[temp2x][temp2y] = map[tempx][tempy] + 1; 
				//	check[temp2x][temp2y] = 1; //불필요할 듯  
				}
			}
			else if(temp2x >= 1 && temp2x <= R && temp2y >= 1 && temp2y <= C && map[tempx][tempy] == -1 && check[temp2x][temp2y] == 0) {
				if(map[temp2x][temp2y] != -2 && map[temp2x][temp2y] != -3) {
					map[temp2x][temp2y] = map[tempx][tempy];
					queue[rear++] = temp2x;
					queue[rear++] = temp2y;
					check[temp2x][temp2y] = 1;
				}
				
			}
			
		}
	} 
	
	return 0;
}

void printmap(void) {
	int i;
	int j;
		
	for(i = 1; i <= R; i++ ) {
			for(j = 1; j <= C; j++) {
				printf("%2c", map[i][j]);
				
			}
		}
		
	return ;
}
