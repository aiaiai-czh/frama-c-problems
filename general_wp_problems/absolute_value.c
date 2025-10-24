#include <limits.h>
/*@
    requires val > INT_MIN;
    ensures positive_value: \result >= 0;
    ensures (val >= 0 ==> \result == val) && 
            (val < 0 ==> \result == -val);
    assigns \nothing;
*/
int abs(int val) {
    if(val < 0) return -val;
    return val;
}

/*@
    requires a > INT_MIN;
    assigns \nothing;
*/
void foo(int a) {
    int b = abs(-42);
    //@ assert b == 42;
    int c = abs(42);
    //@ assert c == 42;
    int d = abs(a);
    //@ assert d >= 0;
}