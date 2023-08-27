#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int result, val;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        val = arr[i];  
        int p1 = 0;
        int p2 = n-1;
        int sum = 0;
        while(p1 < p2){
            sum = arr[p1] + arr[p2];
            if(sum == val){ 
                if(p1 != i && p2 != i){
                    result++;
                    break;
                }
                else if(p1 == i) p1++;
                else if(p2 == i) p2--;
            }
            else if(sum < val) p1++;
            else p2--;
        }
    }
    cout << result;
}