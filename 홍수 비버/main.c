//�����͸� �޾ƾ� �ϴµ� �װ� ���ڿ� ���·� �޾Ҿ�� �ߴµ� �� ���� ���·� �޾�����.. �ǹ��̴�.
// Ǯ�̸� ������ �Ẹ�� �ϴ� ���� ����� ���ÿ� ť�� ����ִµ� ���� ��ǥ�� ���� ����־ ���� ���� �ڸ��� �����ϰ� �����.
// �׸���  check �迭���� ����� 1 ���� -1 �� �����Ͽ��� üũ�� �����Ѵ�. ���� ����� ���� ���� �� �� �����ϱ�!
// �̷� ������ BFS �� ������ ���� ������ �ȴ�. �� ���� ���� ���� ����Ⱑ �ѳ��� ������. 


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

int dx[] = {0,0,1,-1}; //�� �� �� �� ��  
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
	scanf(" %d %d",&R,&C); //��� ���� �Է�
 
    for (int i = 0; i < R; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < C; ++j) {
            if (buf[j] == '.') // ��
                continue;
            else if (buf[j] == 'D') { // �����
                dstx = i+1;
                dsty = j+1;
                map[i+1][j+1] = -3;
            }
            else if (buf[j] == 'S') { // ����ġ
                sx = i+1;
                sy = j+1;
            }
            else if (buf[j] == 'X') // ��
                map[i+1][j+1] = -2;
            else { // �� 
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
			
			if(temp2x >= 1 && temp2x <= R && temp2y >= 1 && temp2y <= C && map[tempx][tempy] != -1) { //����ġ�� ������ 
				if(map[temp2x][temp2y] == 0 || map[temp2x][temp2y] == -3)  {
					queue[rear++] = temp2x;
					queue[rear++] = temp2y;
					map[temp2x][temp2y] = map[tempx][tempy] + 1; 
				//	check[temp2x][temp2y] = 1; //���ʿ��� ��  
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
