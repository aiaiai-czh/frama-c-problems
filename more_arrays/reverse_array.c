/*@
    requires n > 0;
    requires \valid_read(a + (0..n-1));
    ensures \forall integer k; 0 <= k < n ==> a[k] == \old(a[n-k-1]);
    assigns a[0..n-1];
*/
void reverse(int *a, int n) {
    int i = 0;
    int j = n-1;
    /*@
        loop invariant 0 <= i <= n/2;
        loop invariant n-1 >= j >= n/2 - 1;
        loop invariant i + j == n - 1;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[n - 1 - k], Pre);
        loop invariant \forall integer k; 0 <= k < i ==> a[n - 1 -k] == \at(a[k], Pre);
        loop invariant \forall integer k; i <= k <= n - 1 - i ==> a[k] == \at(a[k], Pre);
        loop assigns a[0..n-1], i, j;
        loop variant n/2 - i;
    */
    while (i < n/2) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    //@ assert arr[0] == 5;
    //@ assert arr[1] == 4;
    //@ assert arr[2] == 3;
    //@ assert arr[3] == 2;
    //@ assert arr[4] == 1;
}