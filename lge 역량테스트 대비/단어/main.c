#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 30
char word1[1000000];
char word2[1000000];
int length;
static int cmp(const void *p1, const void *p2){
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int getInput(char*** words) {
    int count;
    int i;
    char buffer[MAX_WORD_LEN+1];

    scanf("%d", &count);

    *words = malloc(count * sizeof(char*));
    for (i = 0; i < count; i++) {
        (*words)[i] = malloc((MAX_WORD_LEN + 1) * sizeof(char));
        scanf("%s", buffer);
        strcpy((*words)[i], buffer);
    }
    return count;
}

void solve() {
    int count;
    int i;
    char ** words;
    int st;
    int end;
    int temp = 0;
    int temp2;
    count = getInput(&words);
	end = count/2;
    qsort(words, count, sizeof(char *), cmp);
	
	for(i=0;i<count;i++){
		length += strlen(words[i]);		
	}
	
	length = length/3;
	if(count == 1){
		printf("%c",words[0][length]);
		return ;
	}
	if(count %2 == 0){
		st = count-2;
	}
	else{
		st = count-1;
	}
	
	for(i=st;i>0;i=i-2){
		temp += strlen(words[i]);
		
		if(temp > length){
			temp -= strlen(words[i]);
			temp = length - temp;
			temp2 = i;
			printf("%c",words[temp2][temp]);
			return ;
		}
	}
	
	for(i=0;i<=end;i++){
		temp += strlen(words[i]);
		
		if(temp >= length){
			temp -= strlen(words[i]);
			temp = length - temp;
			temp2 = i;
			printf("%c",words[temp2][temp-1]);
			return ;
		}
	}	
    
}

void main() {
   

	solve();
   	
    return;
}

