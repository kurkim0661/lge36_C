#include <stdio.h>

#define MAX_PROJECT (15) 
typedef struct{
	int start_date; // ������ 
	int end_date; // ������
}DATA;
int cnt = 1; //���� ī��Ʈ 
int     N; // ������Ʈ ��
DATA    project_info[MAX_PROJECT]; // ������Ʈ ����
DATA temp;
void Data_Input(void){
	int i;
	scanf("%d", &N); // ������Ʈ �� �Է�

	// ������Ʈ ���� �Է�
	for (i = 0; i < N; i++){
		scanf("%d %d", &project_info[i].start_date, &project_info[i].end_date);
	}
}



int main(void){
	int i;
	int j;
	int sol=0;
	int date_temp;
	Data_Input(); // �Է��Լ� ȣ��
	
	for(i=0;i<N-1;i++){ //���������� ���ؼ� end_date�� �������� �����Ѵ�. 
		for(j=0;j<N-1;j++){
			if(project_info[j].end_date > project_info[j+1].end_date){
				temp = project_info[j];
				project_info[j] = project_info[j+1];
				project_info[j+1] = temp;
			}
		}
	}
	date_temp = project_info[0].end_date;
	
	for(i=1;i<N;i++){
		if( date_temp < project_info[i].start_date){
			cnt++;
			date_temp = project_info[i].end_date;
		}
	}
	sol = cnt; 
	printf("%d\n", sol); // ��� ���
	return 0;
}
