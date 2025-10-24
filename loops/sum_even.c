/*@
    requires n >= 0;
    ensures \result == (n / 2 + 1) * (n / 2);
    assigns \nothing;
*/
int func(int n) {
    int sum = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n / 2 + 1;
        loop invariant sum == i * (i - 1);
        loop assigns sum, i;
        loop variant n - i;
    */
    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
    return sum;
}

void main() {
    int t = func(10);
    //@ assert t == 30;
}