#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 105
#define LL long long
#define INF 1e9

using namespace std;
int V, M, J, S;
int dist[MAX][MAX];
int two_cost =  INF; // 지헌이와 상현이의 cost 합의 최소
int j_cost = INF; // 지헌이 최소 cost
vector<int> result;
int answer = -1;


int Search() {

	// 서로 최단거리인지
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) { 
			continue; 
		}
		if (two_cost > dist[J][i] + dist[S][i]) {
			two_cost = dist[J][i] + dist[S][i]; 
		}
	}

	// 지헌이가 상헌이 보다 작은지
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) { 
			continue;
		}
		if ((two_cost == dist[J][i] + dist[S][i]) && (dist[J][i] <= dist[S][i]) && (j_cost > dist[J][i])) {
			j_cost = dist[J][i];
		}
	}

	// 조건 만족하는 장소가 여러개면 가장 번호가 작은 거
	for (int i = 1; i <= V; i++) {
		if ((i == J) || (i == S)) {
			continue;
		}
		if ((two_cost == dist[J][i] + dist[S][i])  && (j_cost == dist[J][i])) {
			result.push_back(i);
		}
	}
	if (!result.empty()) {
		sort(result.begin(), result.end());
		return (result[0]);
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(NULL);

	// dist 초기화
	cin >> V >> M;  // V: 노드갯수 M: 간선갯수
	for (int i = 0; i < V+1; i++) {
		for (int j = 0; j < V+1; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}


	cin >> J >> S; // 현재 지헌(J), 성하(S) 위치
	// 플로이드-워셜 알고리즘 - k: 중간노드, i: 시작노드, j: 도착노드
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	Search(); // dist를 보고 조건에 맞는 node 
	cout << answer << "\n";

	return 0;
}

