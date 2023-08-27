// ** 2018 note ** //

#include<iostream>
#include <vector>

using namespace std;

int n=0, sum=0, result=0;
int p1=1, p2=1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    while (p1 <= n && p2<= p1){
        if (sum < n) sum += p1++;
        else{
            if (sum == n) result++;
            sum -= p2++;
        }
    }

    cout << ++result;

}

