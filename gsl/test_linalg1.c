// program solves the linear system A x = b. 
// and the solution is found using LU decomposition of the matrix A.
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
	double a_data[] = { 0.18, 0.60, 0.57, 0.96,
                        0.41, 0.24, 0.99, 0.58,
                        0.14, 0.30, 0.97, 0.66,
                        0.51, 0.13, 0.19, 0.85 };

	double b_data[] = { 1.0, 2.0, 3.0, 4.0 };
	
	gsl_matrix_view m = gsl_matrix_view_array(a_data, 4, 4);
	gsl_vector_view b = gsl_vector_view_array(b_data, 4);
	gsl_vector *x = gsl_vector_alloc(b.vector.size);
	// duplicate matrix m
	gsl_matrix *ma = gsl_matrix_alloc(m.matrix.size1, m.matrix.size2);
	gsl_matrix_memcpy(ma, &m.matrix);
	// store the inverse and the product
	gsl_matrix *invm = gsl_matrix_alloc(m.matrix.size1, m.matrix.size2);
	gsl_matrix *aa = gsl_matrix_alloc(m.matrix.size1, m.matrix.size2);
	int s;

	print_matrix(&m.matrix);

	gsl_permutation *p = gsl_permutation_alloc(4);
	gsl_linalg_LU_decomp(&m.matrix, p, &s);
	printf("after decomp\n");
	print_matrix(&m.matrix);

	gsl_linalg_LU_solve(&m.matrix, p, &b.vector, x);
	// compute the inverse of m
	gsl_linalg_LU_invert(&m.matrix, p, invm);
	// multiply m and its inverse
	gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, ma, invm, 0.0, aa);	

	printf("x = \n");
	gsl_vector_fprintf(stdout, x, "%g");
	printf("inverse matrix = \n");
	print_matrix(invm);
	printf("m times its inverse, should be identity\n");
	print_matrix(aa);

	gsl_permutation_free(p);
	gsl_vector_free(x);
	gsl_matrix_free(invm);
	gsl_matrix_free(aa);

	return 0;
}


