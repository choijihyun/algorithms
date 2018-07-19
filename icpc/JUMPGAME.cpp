#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
#define False 0
#define True 1
typedef struct position {
	int x, y;
}position;

int n;
int arr[100][100];
int pos_k, pos_j;

/*ó���� ���ο��� 0,0�� ȣ���Ͽ��� �����ϴ����� pos_j,pos_k�� Ȯ��*/
int move(position p) { //���� ���� �����ϸ� 1��ȯ ���� ���� ���ϸ� 0��ȯ
	position pp;
	int a, b;
	if (p.x >= n || p.y >= n) return False; // ĭ �Ѿ�� ��
	if (p.x == n - 1 && p.y == n - 1)return True;

	pp.x = p.x;
	pp.y = p.y + arr[p.x][p.y];
	a = move(pp);	//���������� ���� ��� j�÷��ֱ�

	pp.x = p.x + arr[p.x][p.y];
	pp.y = p.y;
	b = move(pp);	//�Ʒ����� ���� ��� k�÷��ֱ�

	if (a || b) return True;
	else return False;
}

int main() {
	int c;
	position p;
	p.x = 0; p.y = 0;

	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &arr[j][k]);
			}
		}
		if (move(p)) printf("YES\n");
		else printf("NO\n");
	}
}