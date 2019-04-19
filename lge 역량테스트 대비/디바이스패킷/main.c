#include <stdio.h>
#include <string.h>

// 패킷 타입을 위한 정의
#define TYPE_START 0
#define TYPE_DATA 1
#define TYPE_END 2

int N; // 문자열의 개수
int M; // 데이터의 최대 길이
unsigned char str[10 + 10][64 + 10]; // 문자열들을 저장할 배열
unsigned char pkt[4 + 64 + 10]; // 패킷 배열
int sol; // 전송된 모든 패킷들을 바이트 단위로 더한 값

// 패킷을 전송하는 함수
// 실제 전송은 이루어지지 않고 대신 패킷의 각 바이트를 더한 값을 계산 후 리턴함
// len은 전송할 패킷의 길이
int send_pkt(int len)
{
	int i;
	int sum = 0;

	for (i = 0; i < len; i++) {
		sum += pkt[i];
	}

	return sum;
}

// 패킷을 만드는 함수
// type은 패킷 타입
// num은 문자열의 번호
int make_pkt(int type, int num)
{
	int i;
	int idx = 0; // 패킷 배열의 요소 번호
	int len; // 원래 문자열의 길이
	int len2; // 4의 배수로 조정한 문자열의 길이
	int rem = 0;
	int lenlen =4;
	static int seq; // 패킷 번호

	pkt[1] = type; // 패킷 타입
	pkt[3] = 0; // RSV


	switch (type) {
	case TYPE_START:
		seq = 0; // 패킷 번호 초기화
		pkt[2] = 0; // 데이터 길이: 무조건 0
		
		break;

	case TYPE_DATA:
		seq++; // 패킷 번호 증가
		pkt[0] = seq;
		
		len = strlen(str[num]); // 데이터 길이 = 문자열의 길이
		if(len>8){
			len2 = 8;	
		}
		if(len<4){
			rem=len%4;
			len2 = 4;
		}
		if(len ==4){
			len2 =4;	
		}
		else if(len>4 && len<8){
			rem = len %4;
			len2 = 8;
		}
		for(i=0;i<len;i++){
			pkt[i+4] = str[num][i];
			// printf("%x ",pkt[i+4]);
		}
		
		if(len2 != len){
			for(i=len;i<len2;i++){
			pkt[i+4] = 0xff;	
			}
		}
		pkt[2] = len2;
			
		return len2+4;
		break;

	case TYPE_END:
		seq++; // 패킷 번호 증가
		pkt[2] = 0; // 데이터 길이: 무조건 0
		break;

	default:
		break;
	pkt[0] = seq; // 패킷 번호

	return idx; // 패킷 길이 리턴		
	}
		

}




// 패킷을 만들고 전송하는 함수
int handle_pkt(void)
{
	int i;
	int len;
	int sum;

	// START 패킷
	len = make_pkt(TYPE_START, 0);
	sum = send_pkt(len);

	// DATA 패킷
	for (i = 0; i < N; i++) {
		len = make_pkt(TYPE_DATA, i);
		// printf("%d \n",len);
		sum += send_pkt(len);
	}

	// END 패킷
	len = make_pkt(TYPE_END, 0);
	sum += send_pkt(len);

	return sum;
}

int main(void)
{
	int i;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%s", &str[i][0]);
	}

	sol = handle_pkt();

	printf("0x%x", sol+1);

	return 0;
}

