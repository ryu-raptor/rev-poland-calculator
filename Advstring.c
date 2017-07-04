#include <string.h>
#include <stdlib.h>

static void shiftLeft(char*, int, int);
static void shiftRight(char*, int, int);

void replacestr(char* src, int from, int to, char* str)
{
	/*ãlÇﬂÇÈÇ©çLÇ∞ÇÈÇ©åàÇﬂÇƒé¿ç€Ç…Ç∑ÇÈ*/
	if (to - from + 1 >= strlen(str)) {
		/*ãlÇﬂÇÈ*/
		shiftLeft(src, to, to - from + 1 - strlen(str));
	}
	else {
		/*çLÇ∞ÇÈ*/
		shiftRight(src, to, strlen(str) - (to - from + 1));
	}
	
	/*ë}ì¸Ç∑ÇÈ*/
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
	
	/*åÖêîämîF*/
	int digit;
	int tmp = n;
	for (digit = 0; tmp > 0; digit++) {
		tmp /= 10;
	}
	
	/*ämï€*/
	char* rv = (char*)calloc(digit + (signflag ? 1 : 0) + 1, sizeof(char));
	/*ïœä∑*/
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
	/*\0ÇÕä‹Ç‹Ç»Ç¢ÇÃÇ≈-1ÇµÇ»Ç¢*/
	for (int i = strlen(src); ; i--) {
		src[i + amount] = src[i];
		if (i == index) break;
	}
}
