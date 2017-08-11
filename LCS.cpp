#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int d[2][101][101], ans;

int main() {
	ios_base::sync_with_stdio(false);
	string a, b, c;
	cin >> a >> b >> c;
	int alen = a.length();
	int blen = b.length();
	int clen = c.length();
	for (int i = 1; i <= alen; i++) {
		int p = (i - 1) & 1;
		int q = i & 1;
		for (int j = 1; j <= blen; j++) {
			for (int k = 1; k <= clen; k++) {
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) d[q][j][k] = d[p][j - 1][k - 1] + 1;
				else d[q][j][k] = max({ d[p][j][k], d[q][j - 1][k], d[q][j][k - 1] });
			}
		}
	}
	cout << d[alen & 1][blen][clen];
}
