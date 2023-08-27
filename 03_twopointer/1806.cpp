// ** 1806 note ** //

#include<iostream>
#include <vector>

using namespace std;

int n, s, sum;
int p1=0, p2=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n >> s;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    int len = n + 1;
    sum = arr[0];

    while (p1 < n && p2<= p1){
        if (sum < s) {
            sum += arr[++p1];
        }
        else{
            len = min(len, p1-p2+1);
            sum -= arr[p2++];
        }
    }
    if (len == n+1) len = 0;
    cout << len;

}

// 10 15
// 5 1 3 5 10 7 4 9 2 8

