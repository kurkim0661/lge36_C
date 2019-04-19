#include <stdio.h>
#define MAX (1<<16)
#define MOD (MAX-1)
int N;//직원 수
int S;//시작 직원 번호
int M;
int queue[MAX];
int front;
int rear;



void InputData(){
	scanf("%d %d %d", &N, &S, &M);
}

void enqueue(int data){
		queue[rear] = data;
		rear = (rear + 1) % MOD;
}

int dequeue(){
	int temp;
	temp = queue[front]; 
	front = (front + 1) % MOD;
	
	return temp;
}

int detect(){
	return queue[front];	
}


int main(){
	int i = 0;
	int j = 0;
	int temp;
	int start;
	
	InputData();//	입력 함수
	j=S;
	for ( i = 1; i <= N; i++) { 
		enqueue(j);
		if(++j > N)j = 1;
		
	}
	
	for( i = 1; i <= N; i++ ) { 
		for (j = 1; j < M; j++) { 
			enqueue(detect());
			dequeue();
		}
		printf("%d ",dequeue());
	}
	//	코드를 작성하세요


	return 0;
}
