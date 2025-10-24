// This program used an advanced ACSL clause: \max()
// Note: Some versions of 'wp' plugin may not support the \lambda clause.
//       The program may not verify in every machine.

/*@
    axiomatic max_array{
        logic integer max(int* arr, integer begin, integer end) reads arr[begin .. (end-1)];

        axiom one_element_array:
            \forall int* arr, integer b, e; b == e-1 ==> max(arr, b, e) == arr[b];

        axiom multi_element_array:
            \forall int* arr, integer b, e; b < e-1 ==> max(arr, b, e) == (arr[e-1] > max(arr, b, e-1) ? arr[e-1] : max(arr, b, e-1));
    }
*/

/*@
    requires n > 0;
    requires \valid_read(arr+(0..n-1));
    ensures \result == max(arr, 0, n);
    assigns \nothing;
*/
int array_max_advanced(int* arr, int n) {
    int max = arr[0];
    /*@
        loop invariant 1 <= i <= n;
        loop invariant max == max(arr, 0, i);
        loop assigns max;
        loop assigns i;
        loop variant n - i;
    */
    for (int i = 1; i < n;) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    return max;
}

void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int max = array_max_advanced(arr, 5);
    //@ assert \forall integer i; 0 <= i < 5 ==> max >= arr[i];
}