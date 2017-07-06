#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(), isspace(), etc */
#include "Stack.h"
#include "Function.h"
#include "TokenType.h"
#include "rpnStack.h"
#include "Advstring.h"

void rpn(const char *);
stack* process(const char *, rpnstack*);
static int readNumber(const char **);
static char* readToken(const char **);
int getFunctionHash(char);

Function* Functionlist[52] = {NULL};

int main(void)
{
  char buffer[1024];
  for (;;) {
    printf("> ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
      break;
    rpn(buffer);
  }
  return 0;
}

/* 逆ポーランド記法で書かれた数式（文字列）を引数にとり、
   その値を表示する関数 */
void rpn(const char *p)
{
    rpnstack st;
    initrpnStack(&st);

    process(p, &st);
    
	if (!isEmptyStack(&st.data)) {
		printf("%d\n", rpnpop(&st).data);
	}
}

stack* process(const char* p, rpnstack* stk)
{
    bool functionDefFlag = false;
    char* functionExpr;
    
    while (*p != '\0') {
        char* token = readToken(&p);
        
		if (isdigit(*token)) {
			int n = atoi(token);
            rpnpush(n, Number, stk);
		}
        else if (isalpha(*token)) {
            rpnpush(token[0], Symbol, stk);
            
            /*function difinition*/
            /*改行記号付きのため1と2*/
            if (rightcharof(p, 1) == '=' && rightcharof(p, 2) != '=') {
                functionDefFlag = true;
                Functionlist[getFunctionHash(token[0])] = newFunction();
                functionExpr = (char*) calloc(1024, sizeof(char));
            }
        }

        if (!functionDefFlag) {
            if (eqstr(token, "+")) {
                rpndata lop = rpnpop(stk);
                rpndata rop = rpnpop(stk);
                rpnpush(lop.data + rop.data, Number, stk);
            }
            else if (eqstr(token, "*")) {
                rpnpush(rpnpop(stk).data * rpnpop(stk).data, Number, stk);
            }
            else if (eqstr(token, "-")) {
                int rop = rpnpop(stk).data;
                
                rpnpush(rpnpop(stk).data - rop, Number, stk);
            }
            else if (eqstr(token, "/")) {
                int rop = rpnpop(stk).data;
                
                rpnpush(rpnpop(stk).data / rop, Number, stk);
            }
            else if (eqstr(token, ">")) {
            }
            else if (eqstr(token, "==")) {
            }
            else if (eqstr(token, "<")) {
            }
            else if (eqstr(token, "?")) {
            }
        }
        else {
            if (eqstr(token, ":")) {
                rpndata arg = rpnpop(stk);
                rpndata symbol = rpnpop(stk);
                if (symbol.type == Symbol) {
                    Function* f = Functionlist[getFunctionHash(symbol.data)];
                    if (f == NULL) {
                        f = newFunction();
                    }
                    appendArg(f, (char)arg.data);
                    rpnpush(symbol.data, symbol.type, stk);
                }
            }
            else if (eqstr(token, "=")) {
                /*関数代入*/
                rpndata symbol = rpnpop(stk);
                Function* fc = Functionlist[getFunctionHash(symbol.data)];
                bondExpr(fc, functionExpr);
            }
            else if (eqstr(token, "\'")) {
                /*シンボルか？*/
                rpndata symbol = rpnpop(stk);
                if (symbol.type == Symbol) {
                    /*関数適用*/
                    Function* fc = Functionlist[getFunctionHash(symbol.data)];
                    if (fc == NULL) {
                        printf("Error: Function is not defined.\n");
                        exit(1);
                    }
                    /*引数取得*/
                    rpnstack args;
                    initrpnStack(&args);
                    int argc = getFunctionArgs(fc, stk, &args);

                    /*適用*/
                    for (; argc > 0; argc--) {
                        fc = apply(fc, rpnpop(&args));
                    }

                    /*評価*/
                    process(fc->expr, stk);
                }
            }
        }

		p++;
		for ( ; *p != '\0'; p++) {
			if (! isspace(*p))
				break;
		}

        free(token);
	}
}

int getFunctionHash(char c)
{
    /*ASCIIと仮定*/
    /*小文字*/
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    /*大文字*/
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    else {
        return 0;
    }
}

static char* readToken(const char ** psrc)
{
    char* token = (char*)calloc(64, sizeof(char));
    int i = 0;
    
    while ((**psrc) != '\0' && !isspace(**psrc)) {
        token[i] = **psrc;
        i++;
        (*psrc)++;
    }
    token[i] = '\0';

    return token;
}

static int readNumber(const char* * psrc)
{
	const char* p = *psrc;
	int tmp = 0, num = 0;
	int digit = 1;

	while (isdigit(*p)) {
		tmp += (*p - '0') * digit;
		digit *= 10;
	}

	for (digit /= 10; tmp > 0; digit /= 10) {
		num += (tmp % 10) * digit;
		if (digit == 1) break;
	}

	return num;
}
