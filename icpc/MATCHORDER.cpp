#include <stdio.h>
#include <string.h>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

int n;
int team1[101];
int team2[101];
int rrank[101];
int win = 0;

void check() {
	int idx2 = 0;
	for (int i = 0; i < n; i++) { // team2
		for (int j = idx2; j < n; j++) {
			sort(team1, team1 + n);
			if (team2[i] >= team1[j]) {
				idx2 = i;
				if (team1[j] != -1) win++;
				team1[j] = -1;
			}
		}
	}
}

int main() {
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d", &n);
		memset(team1, 0, n);
		memset(team2, 0, n);
		memset(rrank, 0, n);
		for (int j = 0; j < n; j++) {
			scanf("%d", team1 + j);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", team2 + j);
		}
		sort(team1, team1 + n);
		sort(team2, team2 + n); //둘다 오름차순 정렬
		check();
		printf("%d\n", win);
		win = 0;
	}
}