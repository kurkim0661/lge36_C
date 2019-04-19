#include <stdio.h>
#include <string.h>

// ��Ŷ Ÿ���� ���� ����
#define TYPE_START 0
#define TYPE_DATA 1
#define TYPE_END 2

int N; // ���ڿ��� ����
int M; // �������� �ִ� ����
unsigned char str[10 + 10][64 + 10]; // ���ڿ����� ������ �迭
unsigned char pkt[4 + 64 + 10]; // ��Ŷ �迭
int sol; // ���۵� ��� ��Ŷ���� ����Ʈ ������ ���� ��

// ��Ŷ�� �����ϴ� �Լ�
// ���� ������ �̷������ �ʰ� ��� ��Ŷ�� �� ����Ʈ�� ���� ���� ��� �� ������
// len�� ������ ��Ŷ�� ����
int send_pkt(int len)
{
	int i;
	int sum = 0;

	for (i = 0; i < len; i++) {
		sum += pkt[i];
	}

	return sum;
}

// ��Ŷ�� ����� �Լ�
// type�� ��Ŷ Ÿ��
// num�� ���ڿ��� ��ȣ
int make_pkt(int type, int num)
{
	int i;
	int idx = 0; // ��Ŷ �迭�� ��� ��ȣ
	int len; // ���� ���ڿ��� ����
	int len2; // 4�� ����� ������ ���ڿ��� ����
	int rem = 0;
	int lenlen =4;
	static int seq; // ��Ŷ ��ȣ

	pkt[1] = type; // ��Ŷ Ÿ��
	pkt[3] = 0; // RSV


	switch (type) {
	case TYPE_START:
		seq = 0; // ��Ŷ ��ȣ �ʱ�ȭ
		pkt[2] = 0; // ������ ����: ������ 0
		
		break;

	case TYPE_DATA:
		seq++; // ��Ŷ ��ȣ ����
		pkt[0] = seq;
		
		len = strlen(str[num]); // ������ ���� = ���ڿ��� ����
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
		seq++; // ��Ŷ ��ȣ ����
		pkt[2] = 0; // ������ ����: ������ 0
		break;

	default:
		break;
	pkt[0] = seq; // ��Ŷ ��ȣ

	return idx; // ��Ŷ ���� ����		
	}
		

}




// ��Ŷ�� ����� �����ϴ� �Լ�
int handle_pkt(void)
{
	int i;
	int len;
	int sum;

	// START ��Ŷ
	len = make_pkt(TYPE_START, 0);
	sum = send_pkt(len);

	// DATA ��Ŷ
	for (i = 0; i < N; i++) {
		len = make_pkt(TYPE_DATA, i);
		// printf("%d \n",len);
		sum += send_pkt(len);
	}

	// END ��Ŷ
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

