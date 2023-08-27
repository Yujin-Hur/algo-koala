// ** N note ** //

#include<iostream>
#include <vector>

using namespace std;

// input, output
int n, m;
vector<int> result;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n+m; i++) cout << result[i] << " ";
}



#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
long long arr[5000];
long long result[3];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    long long min = 3000000001;

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);

    for(int k=0;k<n-2;k++){
        int p1 = k+1;
        int p2 = n-1;
        while(p1 < p2){
            long long val = arr[k]+arr[p1]+arr[p2];
            if(abs(val) < min){
                min = abs(val);
                result[0] = arr[k];
                result[1] = arr[p1];
                result[2] = arr[p2];
            }
            if(val < 0) p1++;
            else p2--;
        }
    }
    for(int i=0; i<3; i++) cout << result[i]<<" ";
    return 0;
}