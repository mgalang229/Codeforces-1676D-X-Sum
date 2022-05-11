#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		long long mx = LLONG_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				long long sum = a[i][j];
				int row = i - 1;
				int col = j - 1;
				while (row >= 0 && col >= 0) {
					sum += a[row][col];
					row--;
					col--;
				}
				row = i - 1;
				col = j + 1;
				while (row >= 0 && col < m) {
					sum += a[row][col];
					row--;
					col++;
				}
				row = i + 1;
				col = j - 1;
				while (row < n && col >= 0) {
					sum += a[row][col];
					row++;
					col--;
				}
				row = i + 1;
				col = j + 1;
				while (row < n && col < m) {
					sum += a[row][col];
					row++;
					col++;
				}
				mx = max(mx, sum);
			}
		}
		cout << mx << '\n';
	}
	return 0;
}
