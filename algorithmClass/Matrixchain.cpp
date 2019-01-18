//2017029416_±ËªÛ»ø_12525
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** s_, int i, int j);

int main() {
	int num;
	int p_length;
	scanf("%d", &num);
	p_length = num + 1;
	int* p = (int*)malloc(sizeof(int)*p_length);

	int** m = (int**)malloc(sizeof(int*)*p_length); 
		for (int i = 0; i < p_length; ++i) {
			m[i] = (int*)malloc(sizeof(int)*p_length);
		}

	int** s = (int**)malloc(sizeof(int*)*p_length);
	for (int i = 0; i < p_length; ++i) {
		s[i] = (int*)malloc(sizeof(int)*p_length);
	}

	for (int i = 0; i < p_length; ++i) {
		for (int j = 0; j < p_length; ++j) {
			m[i][j] = 0;
			s[i][j] = 0;
		}
	}

	for (int i = 0; i < p_length; ++i) {
		scanf("%d", &p[i]);
	}

	int j;
	int q;
	for (int l = 2; l < p_length; ++l) {
		for (int i = 1; i < p_length - l + 1; ++i) {
			j = i + l - 1;
			m[i][j] = 3000000;
			for (int k = i; k < j ; ++k) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
		printf("%d\n", m[1][num]);
		print_matrix(s, 1, num);

	return 0;
}

void print_matrix(int** s_, int i_, int j_) {
	if (i_ == j_) printf("%d", i_);
	else {
		printf("(");
		print_matrix(s_, i_, s_[i_][j_]);
		print_matrix(s_, s_[i_][j_] + 1, j_);
		printf(")");
	}
}