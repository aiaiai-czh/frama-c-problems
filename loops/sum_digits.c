/*@
    logic integer sum_of_digits(integer x) = 
        x < 10 ? x : (x % 10) + sum_of_digits(x / 10);
*/

/*@
    requires num > 0;
    ensures \result == sum_of_digits(num);
    assigns \nothing;
*/
int func(int num) {
    int i = 0;
    int sum = 0;
    /*@
        loop invariant 0 <= i <= 9;
        loop invariant num >= 0;
        loop invariant sum >= 0;
        loop invariant sum == sum_of_digits(\at(num, Pre)) - sum_of_digits(num);
        loop assigns num, i, sum;
        loop variant num;
    */
    while(num > 0) {
        i = num % 10;
        sum += i;
        num /= 10;
    }
    return sum;
}

void main() {
    int t = func(123);
    //@ assert t == 6;
}