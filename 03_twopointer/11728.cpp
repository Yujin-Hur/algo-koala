
// ** 11728 note ** //

#include<iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int p1 = 0, p2 = 0;
	vector<int> result;

	while(result.size() != n+m){
		if (a[p1] < b[p2]){
			result.push_back(a[p1++]);
			if (p1 == n){	
				while (p2 != m) result.push_back(b[p2++]); // a 배열 끝남
			}
		}
		else if (a[p1] > b[p2]){
			result.push_back(b[p2++]);
			if (p2 == m){	
				while (p1 != n) result.push_back(a[p1++]); // b 배열 끝남
			}
		}
		else if (a[p1] == b[p2]){
			result.push_back(a[p1++]);
			if (p1 == n){	
				while (p2 != m) result.push_back(b[p2++]); // a 배열 끝남
			}
			if (p2 < m){
				result.push_back(b[p2++]);
				if (p2 == m){	
					while (p1 != n) result.push_back(a[p1++]); // b 배열 끝남
				}
			}
		}
	}

	for (int i = 0; i < n+m; i++) cout << result[i] << " ";


}