#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef struct student {
	int a, b;
	int flag;
}student;

int main() {
	int c, n, m, i, j, k, cnt = 0;
	int a, b;
	student * p;
	int * arr;
	scanf("%d", &c);
	for (i = 0; i < c; i++) {
		cnt = 0;
		scanf("%d %d", &n, &m);
		p = (student *)malloc(sizeof(student)*m);
		arr = (int *)malloc(sizeof(int)*n);
		for (j = 0; j < m; j++) {
			scanf("%d %d", &a, &b);
			(p + j)->a = a;
			(p + j)->b = b;
			(p + j)->flag = 0; //Â¦¤·
			arr[i] = 0;
		}
		for (j = 0; j < m; j++) {
			for (k = j + 1; k < m; k++) {
				if (arr[(p + j)->a] == 0 && arr[(p + j)->b] == 0) {

				}
			}
		}
		printf("%d\n", cnt);
	}
}