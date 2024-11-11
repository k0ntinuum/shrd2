
int h_value(int X[S][S], int k) {
    int r = h_row[k];
    int c = h_col[k];
    return 8*X[r][c] + 4*X[r][c+1] + 2*X[r][c+2] + X[r][c+3];
}

int v_value(int X[S][S], int k) {
    int r = v_row[k];
    int c = v_col[k];
    return 8*X[r][c] + 4*X[r+1][c] + 2*X[r+2][c] + X[r+3][c];
}

void v_store(int X[S][S], int k , int j )  {
    int r = v_row[k];
    int c = v_col[k];
	X[r][c] = j/8;
	j -= 8*X[r][c];

	X[r+1][c] = j/4;
	j -= 4*X[r+1][c];

	X[r+2][c] = j/2;
	j -= 2*X[r+2][c];

	X[r+3][c] = j;
}
void h_store(int X[S][S], int k , int j )  {
    int r = h_row[k];
    int c = h_col[k];

	X[r][c] = j/8;
	j -= 8*X[r][c];

	X[r][c+1] = j/4;
	j -= 4*X[r][c+1];

	X[r][c+2] = j/2;
	j -= 2*X[r][c+2];

	X[r][c+3] = j;
}

void permute(int X[S][S], int f[P]) {
    int r0, r1, c0, c1, N[S][S];
    for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) N[i][j] = X[i][j];
    for (int i = 0; i < S*S ; i++) {
		r0 = i/S;
		c0 = i%S;
		r1 = f[i]/S;
		c1 = f[i]%S;
		X[r1][c1] = N[r0][c0]; 
	}
}

void copy_matrix_src_tar(int src[S][S],int tar[S][S]) {
	for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) tar[i][j] = src[i][j];
}



void h_forward(int X[S][S], int g[G]) {
    for (int k = 0 ; k < 16 ; k++) h_store(X,  k, g[h_value(X, k)]);
}
void v_forward(int X[S][S], int g[G]) {
    for (int k = 0 ; k < 16 ; k++) v_store(X,  k, g[v_value(X, k)]);
}



