// Test LU decomposition
//
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_blas.h>

void print_matrix(const gsl_matrix *m) {
	int i, j;
	for (i = 0; i < m->size1; i++) {
		for (j = 0; j < m->size2; j++) {
			printf("%8.3f", gsl_matrix_get(m, i, j));
		}
		printf("\n");
	}	
}

int main() {
	double a_data[] = { 1, -2, 1,
						2, 3, -1,
						3, 1, -2 };
	
	gsl_matrix_view m = gsl_matrix_view_array(a_data, 3, 3);
	gsl_permutation *p = gsl_permutation_alloc(m.matrix.size1);
	int s;
	
	printf("matrix \n");
	print_matrix(&m.matrix);
	// LU decomposition
	gsl_linalg_LU_decomp(&m.matrix, p, &s);
	printf("LU decomposition\n");
	print_matrix(&m.matrix);
	// data array
	printf("data array after decomp\n");
	for (int i = 0; i < 9; i++)
		printf("%8.3f", a_data[i]);
	printf("\n");
	printf("permutation\n");
	for (int i = 0; i < p->size; i++)
		printf("%4u", gsl_permutation_get(p, i));
	printf("\n");
	printf("sign = %d\n", s);

	gsl_permutation_free(p);

	return 0;
}

