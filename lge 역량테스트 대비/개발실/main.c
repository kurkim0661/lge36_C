#include <stdio.h>

int H;	// ���� ũ��
int W;	// ���� ũ��
int map[50][50];	// ����
int cnt=0;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0}; 
int stack[50*50];
int top;
int visit[50][50]; //�湮���� 
	
struct ANS{
	int count;	// room ����
	int area;		// ���� ���� room ����
};

void Input_Data(void){
	int i, j;
	scanf("%d %d", &H, &W);
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			scanf("%d", &map[i][j]);
		}
	}
}


void DFS(int x, int y,struct ANS* an){
	int k;
	visit[x][y] = cnt;
	for(k=0;k<4;k++){
		if((map[x][y] >> k & 0x1) == 0){
			if(x+dx[k] >= 0 && x+dx[k] < H && y+dy[k] >=0 && y+dy[k] < W && visit[x+dx[k]][y+dy[k]] == 0){
				an->count++;
				DFS(x+dx[k],y+dy[k],an);
			} 
		}	
	}	
}

int main(void){
	int i;
	int j;
	int k;
	
	struct ANS ans = {0, 0};
	Input_Data();		//	�Է� �Լ�
	
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(visit[i][j] != 0){
				continue;
			}
			cnt++; 
			DFS(i,j,&ans);
			if(ans.count >ans.area){
				ans.area = ans.count;
			}
			ans.count = 0;
		}
	}
	ans.count = cnt;
	printf("%d\n", ans.count);		//	���� ���
	printf("%d\n", ans.area+1);		//	���� ���
	
	return 0;
}

