#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "shuffle.c"
#include "compute.c"
#include "text.c"
#include "print.c"

// #include <stdbool.h>
// #include <inttypes.h>
int main() {
    int f[P], f_inv[P], h[G], h_inv[G], v[G], v_inv[G], a[G], M[S][S], test[S][S];
    randomize(M);permutize(f,P);permutize(h,G);permutize(v,G);copy_matrix_src_tar(M,test);
    invert(h,h_inv,G);invert(v,v_inv,G);invert(f,f_inv,P);
    print_perm(f,P);
    print_perm(h,G);
    print_perm(h_inv,G);
    print_perm(f_inv,P);
    hide_cursor();
    int delay = 200000;
    int T = 1000000;
    cls();
    cursor_to(0,0);
    print_matrix(M);

    for (int i = 0; i < T ; i++) { 
        h_forward(M, h);
        v_forward(M, v);
        permute(M, f);
        cursor_to(0,0);
        print_matrix(M);
        usleep(delay);
    }
    for (int i = 0; i < T ; i++) { 
        permute(M, f_inv);
        v_forward(M, v_inv);
        h_forward(M, h_inv);
        cursor_to(0,0);
        print_matrix(M);
        usleep(delay);
    }
    printf("\n%d errors ", h_dist(M,test));
}
      