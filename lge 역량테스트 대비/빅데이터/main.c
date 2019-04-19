#include <stdio.h>
#include <string.h>

int N;							//	모델명의 개수
char str[10010][21];	//	모델명 저장
char str2[10010][21];
char check[10010][21];
int ary[10010];
int main(void){
	int i;
	int j;
	int max=0;
	int is = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%s", str[i]);
		
		for(j=0; j<max; j++){
			if(strcmp(check[j],str[i]) == 0){
				is = 1;
				ary[j]++;
				break;
			}
		}
		if(is == 0){
			check[max] = str[i];
			ary[max]++;
			max++;
		}
		
	}
		for (i=0; i<N; i++){
			for(j=0;j<;j++){
				if(strcmp(str[i],check[j]){

				}
			}
		
	}
	
	for (i=0; i<N; i++){
			
	}
	printf("%s",ptr);
	
	//	코드를 작성하세요

	
	
	
	return 0;
}
