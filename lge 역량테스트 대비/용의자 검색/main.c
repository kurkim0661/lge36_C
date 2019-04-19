#include <stdio.h>
#include <string.h> 

#define MAX_str 50000
#define MAX_N 10000
#define MAX_NAME 1000

char str[MAX_str];
int N;
char name[MAX_N][MAX_NAME];
int check[MAX_N];
int max = -1;
int main() {
	int i;
	int j =0;
	int idx;
	char *ptr;
	
	scanf("%s",str);
	ptr = str;
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%s",name[i]);
	}
	
	for(i=0;i<N;i++){
		ptr = strstr(str,name[i]);
		if(ptr != NULL){
			check[i]++;
		}

		
		while(ptr != NULL){
			ptr = strstr(ptr+1,name[i]);
			check[i]++;
		}
		if(max<check[i]){
			max = check[i];
			idx = i;
		
		}		
	}
	
	if(max == 0){
		printf("null");
		return 0;
	}
	printf("%s",name[idx]);
	
	
	
  return 0;
}

