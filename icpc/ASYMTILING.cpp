#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

long long int dp[101];

long long int count(long long int n) {
	if (dp[n] != -1)return dp[n];

	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	return dp[n] = (count(n - 1) + count(n - 2)) % 1000000007;

}

int main() {
	long long int c, n, cnt, a, b;
	scanf("%lld", &c);
	for (int i = 0; i < c; i++) {
		scanf("%lld", &n);
		memset(dp, -1, sizeof(dp));
		cnt = count(n) % 1000000007;
		memset(dp, -1, sizeof(dp));
		if (n % 2 == 0) {
			if (n == 2) a = 2;
			else {
				a = (count(n / 2 - 1) + 1000000007) % 1000000007; // 경계 포함
				memset(dp, -1, sizeof(dp));
				b = (count(n / 2) + 1000000007) % 1000000007;
				a += b;
			}
		}
		else {
			a = (count((n - 1) / 2) + 1000000007) % 1000000007;
		}
		a %= 1000000007;

		printf("%lld\n", (cnt - a + 1000000007) % 1000000007);
	}
}