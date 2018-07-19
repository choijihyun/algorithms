#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int dp[101];

int count(int n) {
	if (dp[n] != -1)return dp[n];

	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	return dp[n] = (count(n - 1) + count(n - 2)) % 1000000007;

}

int main() {
	int c, n;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", count(n) % 1000000007);
	}
}