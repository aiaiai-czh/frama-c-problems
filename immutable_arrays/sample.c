/*@
requires y > 0;
requires x >= 0;
ensures \result == x / y;
assigns \nothing;
*/
int fun(int x, int y) {
    int r = x;
    int d = 0;
    /*@
        loop invariant r + d * y == x;
        loop invariant d >= 0;
        loop invariant r >= 0;
        loop assigns d, r;
        loop variant r;
    */
    while (r >= y) {
        // Beginning
        r = r - y;
        d = d + 1;
        // ENd
        //@ assert r + d * y == x;
    }
    return d;
}

int main() {
    int d = fun(10, 2);
    //@ assert d == 5;
}