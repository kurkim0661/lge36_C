#include <stdio.h>

#define MAX_PROJECT (15) 
typedef struct{
	int start_date; // 시작일 
	int end_date; // 종료일
}DATA;
int cnt = 1; //갯수 카운트 
int     N; // 프로젝트 수
DATA    project_info[MAX_PROJECT]; // 프로젝트 정보
DATA temp;
void Data_Input(void){
	int i;
	scanf("%d", &N); // 프로젝트 수 입력

	// 프로젝트 정보 입력
	for (i = 0; i < N; i++){
		scanf("%d %d", &project_info[i].start_date, &project_info[i].end_date);
	}
}



int main(void){
	int i;
	int j;
	int sol=0;
	int date_temp;
	Data_Input(); // 입력함수 호출
	
	for(i=0;i<N-1;i++){ //선택정렬을 통해서 end_date를 오름차순 정리한다. 
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
	printf("%d\n", sol); // 결과 출력
	return 0;
}
