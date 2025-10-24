#include<limits.h>
/*@ 
    requires n >= 0;
    requires p >= 0;
    requires r >= 0;
    ensures \result == p * n * r / 100;
    assigns \nothing;
*/
int simple(int p, int n, int r)
{
    int si;
    si = p*n*r/100;
    return si;
}
 
int main()
{
    int s = simple(10000, 3,10);
    //@ assert s == 10000 * 3 * 10 / 100;
    return 0;
}