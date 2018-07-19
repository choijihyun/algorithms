#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
#pragma warning(disable: 4996)
using namespace std;

int n;
double arr[10][10];
int dp[10];
double sum = 0;

void check() {
	int cnt = 0, min_x = 0, min_y = 0;
	for (int k = 0; k < n; k++) {
		if (dp[k] == 0)cnt++;
	}
	if (cnt == n)return;

	int i, j;
	double max = INT_MAX;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i] == 0 || dp[j] == 0)continue;
			if (i == j)break;
			if (arr[i][j] < max) {
				max = arr[i][j];
				min_x = i;
				min_y = j;
			}
		}
	}
	dp[min_x] = 0;
	dp[min_y] = 0;
	sum += max;
	check();
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(dp, 1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		check();
		printf("%.10lf\n",sum);
		sum = 0;

	}
}