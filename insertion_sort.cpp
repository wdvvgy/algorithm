#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int a[5] = { 3, 5, 1, 4, 2 };
	int N = 5;
	for (int i = 0; i < N; i++) {
		int j = i;
		while (j > 0 && a[j] < a[j - 1]) {
			int t = a[j];
			a[j] = a[j - 1];
			a[j - 1] = t;
			j--;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << endl;
	}
	return 0;
}