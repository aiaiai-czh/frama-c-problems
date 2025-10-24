/*@
    ensures \result == x + y + 5;
    assigns \nothing;
*/
int function(int x, int y) {
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    return res ;
}

void main() {
    int t = function(-5, 5);
    //@ assert t == 5;
}