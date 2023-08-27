// ** 2980 note ** //

#include<iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int t, n, k;
vector<int> result(2);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> t;
    int result[t];
    for (int i = 0; i < t; i++){
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        int p1 = 0;
        int p2 = n-1;
        int min = INF;
        int cnt = 0;
        while(p1 < p2){
            int sum = arr[p1] + arr[p2];

            if (sum == k){
                p1++; p2--;
            }
            else if (sum > k){
                p2--;
            } else p1++;

            if (min > abs(k-sum)){
                min = abs(k-sum);
                cnt = 1;
            } else if (min == abs(k-sum)) cnt++;
        }
        result[i] = cnt;
    }
    for (int i = 0; i < t; i++) cout << result[i] << endl;
}