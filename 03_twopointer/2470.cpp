// ** 2470 note ** //
// 두 용액(양수,음수 있음) 섞어서 0에 가깝게 만들기
// 정렬 후 맨 앞과 끝에 포인터 두고 점점 가운데로 움직이기
// 가운데로 움직이려면 => p1은 증가 , p2는 감소
// 두 포인터 sum > 0 => 0이 되려면 감소해야하니까 p2감소 선택
// 두 포인터 sum < 0 => 0이 되려면 증가해야하니까 p1증가 선택

#include<iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000

using namespace std;

int n;
vector<int> result(2);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int p1 = 0;
    int p2 = n-1;
    int min = INF;

    while(p1 < p2){
        int sum = arr[p1] + arr[p2];

        if (min > abs(sum)){
            min = abs(sum);
            result[0] = arr[p1];
            result[1] = arr[p2];

            if (sum == 0) break;
        }

        if (sum < 0) p1++;
        else p2--;

    }

    cout << result[0] << " " << result[1];

}