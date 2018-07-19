#include <stdio.h>
#include <iostream>
#include <memory.h>
#pragma warning(disable: 4996)
using namespace std;

unsigned long long arr[101];

int main() {
	int c;
	cin >> c;
	memset(arr, 0, sizeof(arr));
	while (c--) {
		int n, i;
		cin >> n;
		for (i = 1; i < 4; i++)arr[i] = 1;
		for (i = 4; i < 6; i++)arr[i] = 2;
		if (n < 6)cout << arr[n] << endl;
		else {
			i = 5;
			while (i <= n) {
				arr[i] = arr[i - 1] + arr[i - 5];
				i++;
			}
			cout << arr[n] << endl;
		}
	}
}