#include <string.h>
#include <stdlib.h>

static void shiftLeft(char*, int, int);
static void shiftRight(char*, int, int);

void replacestr(char* src, int from, int to, char* str)
{
	/*�l�߂邩�L���邩���߂Ď��ۂɂ���*/
	if (to - from + 1 >= strlen(str)) {
		/*�l�߂�*/
		shiftLeft(src, to, to - from + 1 - strlen(str));
	}
	else {
		/*�L����*/
		shiftRight(src, to, strlen(str) - (to - from + 1));
	}
	
	/*�}������*/
	strncpy(str, src + from, strlen(str));
}

char* itoas(int n)
{
	if (n == 0) {
		char* rv = (char*)calloc(1 + 1, sizeof(char));
		rv[0] = '0';
		return rv;
	}
	
	int signflag = 0;
	if (n < 0) {
		signflag = 1;
		n = -n;
	}
	
	/*�����m�F*/
	int digit;
	int tmp = n;
	for (digit = 0; tmp > 0; digit++) {
		tmp /= 10;
	}
	
	/*�m��*/
	char* rv = (char*)calloc(digit + (signflag ? 1 : 0) + 1, sizeof(char));
	/*�ϊ�*/
	for (int i = digit - 1 + signflag ? 1 : 0; n > 0 ; i--) {
		rv[i] = '0' + (n % 10);
		n /= 10;
	}
	if (signflag) {
		rv[0] = '-';
	}
	
	return rv;
}

static void shiftLeft(char* src, int index, int amount)
{
	if (amount == 0) return;
	for (int i = 0; ; i++) {
		src[i - amount] = src[i];
		if (src[i] == '\0') break;
	}
}

static void shiftRight(char* src, int index, int amount)
{
	if (amount == 0) return;
	/*\0�͊܂܂Ȃ��̂�-1���Ȃ�*/
	for (int i = strlen(src); ; i--) {
		src[i + amount] = src[i];
		if (i == index) break;
	}
}
