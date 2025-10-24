#include <stdio.h>
/*@
    behavior n_l_7:
        assumes n < 7;
        ensures \result == 1;
    behavior n_ge_7:
        assumes n >= 7;
        ensures \result == (n - 1) / 3;
    assigns \nothing;
    disjoint behaviors;
    complete behaviors;
*/
int fun(int n) {
    int i = 7;
    int x = 1;
    /*@
        loop invariant 7 <= i;
        loop invariant n >= 7 ==> (i <= n + 3 && i == 4 + 3 * x && x >= 1);
        loop invariant n < 7 ==> x == 1;
        loop assigns x, i;
        loop variant n - i;
    */
    while(i <= n) {
        x += 1;
        i += 3;
    }
    return x;
}

int main() {
    int a = fun(10);
    //@ assert a == 3;

    a = fun(1);
    //@ assert a == 1;
}