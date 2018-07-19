#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

char str[10005];
int dp[10005];

/*모든 함수는 늘어난 인덱스의 길이를 반환함 근데 길이가 3보다 작으면 -1반환 */

int check_one(int index) { //모든 숫자가 같을 경우
	int i = 0;
	char value = str[index];
	if (index + 2 == strlen(str))return -1;
	for (i = index; i < index + 5; i++) {
		if (i == strlen(str))break;
		if (str[i] != value)
			break;
	}
	if (i - index < 3)return -1;
	return i - index - 1;
}

int check_two(int index) { // 단조 증가 또는 감소
	char value = str[index];
	int cnt1 = 0, cnt2 = 0;
	if (index + 2 == strlen(str))return -1;

	if (value + 1 == str[index + 1]) { //증가
		cnt1++;
		for (int i = index + 1; i < index + 4; i++) {
			if (i == strlen(str))break;
			if (str[i] + 1 == str[i + 1]) cnt1++;
			else break;
		}
		if (cnt1 < 3)return -1;
		return cnt1;
	}
	else if (value == str[index + 1] + 1) { //감소
		cnt2++;
		for (int i = index + 1; i < index + 4, i != strlen(str); i++) {
			if (i == strlen(str))break;
			if (str[i] == str[i + 1] + 1) cnt2++;
			else break;
		}
		if (cnt2 < 3)return -1;
		return cnt2;
	}
	return -1;
}

int check_three(int index) { // 번갈아 가면서 등장
	char value = str[index];
	if (index + 3 == strlen(str))return -1;
	if (value == str[index + 2]) {
		if (str[index + 1] != str[index + 3]) return 3;
		else {
			if (value == str[index + 4] && index + 4 < strlen(str))return 5;
			else return 4;
		}
	}
	return -1;
}

int check_four(int index) { // 등차수열
	int value = str[index] - str[index + 1];
	int i;
	if (index + 2 == strlen(str))return -1;
	if (str[index + 1] + value == str[index + 2]) {
		for (i = index + 2; i < index + 4, i != strlen(str); i++) {
			if (str[i] != str[i + 1])
				break;
		}
		return i - index - 1;
	}
	return -1;
}

int check(int index, int cnt) {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

	if (index >= strlen(str)) return 0;
	if (strlen(str) - index < 3) return 0;
	cnt1 = check_one(index);
	cnt2 = check_two(index);
	cnt3 = check_three(index);
	cnt4 = check_four(index);
	if (cnt1 != -1)
		return 1 + check(index + cnt1 + 1, 0);
	else if (cnt2 != -1)
		return 2 + check(index + cnt2 + 1, 0);
	else if (cnt3 != -1)
		return 4 + check(index + cnt3, 0);
	else if (cnt4 != -1)
		return 5 + check(index + cnt4 + 1, 0);
	else {
		if (cnt == 3)
			return 10 + check(index + 3, 0);
		if (cnt == 4)
			return 10 + check(index + 4, 0);
		if (cnt == 5)
			return 10 + check(index + 5, 0);
	}
}

int main() {
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%s", str);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", check(0, 0));
	}
}