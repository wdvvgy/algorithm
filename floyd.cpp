#include <iostream>
#include <vector>
using namespace std;
int d[100][100];
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> d[i][j];
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (d[i][k] == 1 && d[k][j] == 1) {
                    d[i][j] = 1;
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
