CC=gcc
CFLAGS=-Wall `gsl-config --cflags`
LIBS=`gsl-config --libs`

DEPS1=sf_bessel.c
sf_bessel: $(DEPS1)
	$(CC) -o sf_bessel $(DEPS1) $(CFLAGS) $(LIBS)

DEPS2=test_matrix1.c
test_matrix1: $(DEPS2)
	$(CC) -o test_matrix1 $(DEPS2) $(CFLAGS) $(LIBS)

DEPS3=test_matrix2.c
test_matrix2: $(DEPS3)
	$(CC) -o test_matrix2 $(DEPS3) $(CFLAGS) $(LIBS)

DEPS4=test_matrix3.c
test_matrix3: $(DEPS4)
	$(CC) -o test_matrix3 $(DEPS4) $(CFLAGS) $(LIBS)

DEPS5=test_linalg1.c
test_linalg1: $(DEPS5)
	$(CC) -o test_linalg1 $(DEPS5) $(CFLAGS) $(LIBS)

DEPS6=test_linalg2.c
test_linalg2: $(DEPS6)
	$(CC) -o test_linalg2 $(DEPS6) $(CFLAGS) $(LIBS)


