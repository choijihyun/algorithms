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

/*처음에 메인에서 0,0을 호출하여서 도달하느지는 pos_j,pos_k로 확인*/
int move(position p) { //만약 끝에 도달하면 1반환 도달 하지 못하면 0반환
	position pp;
	int a, b;
	if (p.x >= n || p.y >= n) return False; // 칸 넘어가면 끝
	if (p.x == n - 1 && p.y == n - 1)return True;

	pp.x = p.x;
	pp.y = p.y + arr[p.x][p.y];
	a = move(pp);	//오른쪽으로 가는 재귀 j늘려주기

	pp.x = p.x + arr[p.x][p.y];
	pp.y = p.y;
	b = move(pp);	//아래으로 가는 재귀 k늘려주기

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