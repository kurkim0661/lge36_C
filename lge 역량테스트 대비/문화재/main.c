#include <stdio.h>
#define MAX 1050

int N;						//	문화재의 개수
int area;					//	면적
int H[MAX];
int P[MAX];
int stx = 1001;
int endx = 0;
int maxh;
int maxx;

int main(){
	int i;
	int j;
	int x;
	int y;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&x,&y);
		H[x] = y;
		if(x<stx){
			stx = x;
		}
		if(y>maxh){
			maxh = y;
			H[x]=maxh;
			maxx = x;
		}
		if(endx < x){
			endx = x;
		}
	}
	for(i=stx+1;i<maxx;i++){
		if(H[i-1] > H[i]){
			H[i] = H[i-1];
		}
	}
	for(i=endx;i>maxx;i--){
		if(H[i-1] < H[i]){
			H[i-1] = H[i];
		}
	}
	
	for(i=stx;i<=endx;i++){
		area += H[i];
	}
	printf("%d",area);
}
