#include <string.h>
#include <stdlib.h>

static void shiftLeft(char*, int, int);
static void shiftRight(char*, int, int);

void replacestr(char* src, int from, int to, char* str)
{
	/*詰めるか広げるか決めて実際にする*/
	if (to - from + 1 >= strlen(str)) {
		/*詰める*/
		shiftLeft(src, to, to - from + 1 - strlen(str));
	}
	else {
		/*広げる*/
		shiftRight(src, to, strlen(str) - (to - from + 1));
	}
	
	/*挿入する*/
	strncpy(str, src + from, strlen(str));
}

char* itoas(int n)
{
	int signflag = 0;
	if (n < 0) {
		signflag = 1;
		n = -n;
	}
	
	/*桁数確認*/
	int digit;
	int tmp = n;
	for (digit = 1; ; digit++) {
		tmp /= 10;
		if (tmp == 0) break;
	}
	
	/*確保*/
	char* rv = (char*)calloc(digit + (signflag ? 1 : 0) + 1, sizeof(char));
	/*変換*/
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
	/*\0は含まないので-1しない*/
	for (int i = strlen(src); ; i--) {
		src[i + amount] = src[i];
		if (i == index) break;
	}
}
