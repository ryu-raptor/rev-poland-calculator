# rev-poland-calculator
rev-poland programmable calculator

## Spec
Operators

a b +

a b -

a b *

a b /

a b %


(expr) b c ?

if c == true -> b, else -> (expr) '


a b !

a <- b


a b :

a : b -> a. Function argument bond operator


a (expr) =

defun a = (expr). Function bond operator


(args) f '

f (args). Function invoke operator

## Example
\> 1 1 +

2

\> 11 -11 +

0

\> f s : u : s u 1 - f 1 u 1 == ? s * =

f

\> 2 3 f '

8
