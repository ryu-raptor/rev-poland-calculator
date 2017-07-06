#include "rpnStack.h"
#include "Stack.h"
#include "TokenType.h"

void initrpnStack(rpnstack* st)
{
    init(&(st->data));
    init(&(st->type));
}

void rpnpush(int data, etype e, rpnstack* st)
{
    push(data, &(st->data));
    push((int)e, &(st->type));
}

rpndata rpnpop(rpnstack* st)
{
    rpndata rv;
    rv.data = pop(&(st->data));
    rv.type = (etype)pop(&(st->type));

    return rv;
}
