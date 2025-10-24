/*@
requires y > 0;
requires x >= 0;
requires \valid(r);
behavior x_l_y:
    assumes x < y;
    ensures \result == 0;
    ensures *r == x;
behavior x_ge_y:
    assumes x >= y;
    ensures \result == x / y;
    ensures *r == x % y;
assigns *r;
*/
int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;
    /*@
    loop invariant d >= 0;
    loop invariant *r >= 0;
    loop invariant x == *r + d * y;
    loop assigns d;
    loop assigns *r;
    loop variant *r;
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}

int main() {
    int a = 3;
    int num = fun(1, 2, &a);
    //@ assert a == 1;
    //@ assert num == 0;

    a = 3;
    num = fun(2, 1, &a);
    //@ assert a == 0;
    //@ assert num == 2;
    return 0;
}