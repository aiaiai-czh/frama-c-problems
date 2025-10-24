/*@
    requires n > 0;
    requires \valid_read(a+(0..n-1));
    requires \forall integer k, l; 0 <= k <= l < n ==> a[k] <= a[l];

    ensures \result >= -1 && \result < n;

    behavior present:
        assumes \exists integer k ; 0 <= k < n && a[k] == x ;
        ensures a[\result] == x ;

    behavior not_present:
        assumes \forall integer k ; 0 <= k < n ==> a[k] != x ;
        ensures \result == -1;

    disjoint behaviors;
    complete behaviors;

*/
int binarysearch(int* a, int x, int n) {

    int low = -1;
    int high = n;
    int p;

    /*@
        loop invariant -1 <= low <= n;
        loop invariant 0 <= high <= n;
        loop invariant \forall integer k; 0 <= k <= low ==> a[k] < x;
        loop invariant \forall integer k; high <= k < n ==> a[k] > x;
        loop assigns low, high;
        loop assigns p;
        loop variant high - low;
    */
    while (low+1 < high) {
        p = (low + high) / 2;
        if (a[p] == x) 
            return p;
        else 
            if (a[p] < x)
                low = p;
            else high = p;
    }
    return -1;
}

void main() {
    int arr[5] = {1, 2, 3, 4, 5}; 
    int sum = binarysearch(arr, 3, 5);
    //@ assert arr[sum] == 3;
}