#include <stdio.h>
#define MAX (1<<16)
#define MOD (MAX-1)
int N;//���� ��
int S;//���� ���� ��ȣ
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
	
	InputData();//	�Է� �Լ�
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
	//	�ڵ带 �ۼ��ϼ���


	return 0;
}
