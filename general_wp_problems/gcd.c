/*@
    logic integer gcd_logic(integer a, integer b) = 
        (a == 0) ? b:
        (b == 0) ? a:
        (a == b) ? a:
        (a > b) ? gcd_logic(a-b, b) : gcd_logic(a, b-a);
*/

/*@
    requires a >= 0 && b >= 0;
    decreases a + b;
    assigns \nothing;
    ensures a == 0 ==> \result == b;
    ensures b == 0 ==> \result == a;
    ensures a == b ==> \result == a;
    ensures a > b ==> \result == gcd_logic(a-b, b);
    ensures a < b ==> \result == gcd_logic(a, b-a);
*/
int gcd(int a, int b) {
    if (a == 0)
       return b;

    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
    int a = 98, b = 56;
    int c = gcd(a, b);
    //@ assert c == 14;
    return 0;
}