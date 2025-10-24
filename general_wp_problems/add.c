#include <limits.h>
/*@
    requires x+y <= INT_MAX;
    requires x >= INT_MIN &&  y >= INT_MIN;
    ensures \result == x+y;
    assigns \nothing;
*/
int add(int x, int y) {
    return x+y;
}

void foo() {
    int a = add(1, 43);
    //@ assert a == 44;
}