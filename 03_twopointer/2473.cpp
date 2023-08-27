#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define INF 3000000001
using namespace std;

int n;
long long result[3];

int main() {

    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-2; i++){
        int p1 = i+1;
        int p2 = n-1;
        int min = INF;

        while(p1 < p2){
            long long val = arr[i]+arr[p1]+arr[p2];
            if(abs(val) < min){
                min = abs(val);
                result[0] = arr[i];
                result[1] = arr[p1];
                result[2] = arr[p2];
            }
            if(val < 0) p1++;
            else p2--;
        }
    }
    for(int i=0; i<3; i++) cout << result[i]<<" ";
}