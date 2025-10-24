/*@
    ensures \result == 1 <==> (a + b > c && a + c > b && b + c > a);
    ensures \result == 0 <==> !(a + b > c && a + c > b && b + c > a);
    assigns \nothing;
*/

int validts(int a, int b, int c) {
    int valid = 0;
    if ((a+b>c) && (a+c>b) && (b+c>a) && 1) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}

void test() {
    int valid = validts(2, 3, 4);
    //@ assert valid == 1;

    int unvalid = validts(1, 2, 3);
    //@ assert unvalid == 0;
}