/*@
ensures \result == 30;
assigns \nothing;
*/
int sum(){
    int i=0;
    /*@
        loop invariant 0 <= i <= 30;
        loop assigns i;
        loop variant 30 - i;
    */
    while (i<30){
        ++i;
    }
    //@assert i == 30;
    return i;
}

int main(){
    int res = sum();
    //@ assert res == 30;
}