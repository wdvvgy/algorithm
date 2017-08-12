#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int N, M, a[2001], x, y, d[2001][2001];

int f(int i, int j) {
	int& ret = d[i][j];
	if (i == j) return ret = 1;
	else if (i + 1 == j) return ret = a[i] == a[j];
	if (ret >= 0) return ret;
	if (a[i] != a[j]) return ret = 0;
	return ret = f(i + 1, j - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	memset(d, -1, sizeof(d));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(d[i][j] == -1) f(i, j);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		cout << d[--x][--y] << '\n';
	}
	return 0;
}
