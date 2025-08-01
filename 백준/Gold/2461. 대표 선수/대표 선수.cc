#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>
#include <tuple>
#include <regex>

using namespace std;
#define MAXX 2147483647

vector<int>v[1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

	cin >> N >> M;

	for (int a = 0; a < N; a++) 
		for (int b = 0; b < M; b++)
        {
            int c;
			cin >> c;
			v[a].push_back(c);
		}
    
	// 값, 반 번호, 학생 번호
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, less<>> pq; // 내림차순 pq

	int rs = MAXX;
	int minNum = MAXX;
    
	for (int a = 0; a < N; a++) 
    {
		sort(v[a].begin(), v[a].end(),greater<int>());
		minNum = min(minNum, v[a][0]); // 가장 낮은 능력치 갱신
		pq.push({ v[a][0],{a,0} }); // 우선순위큐에 각 조에서 가장 낮은 능력치의 사람들 추가
	}
	
	while (!pq.empty()) 
    {
		int curNum = pq.top().first; // 능력치
		int curIndex = pq.top().second.first; // 현재 조
		int curArrIndex = pq.top().second.second; // 현재 조의 순번

		pq.pop();

		rs = min(rs, curNum - minNum); // 최소 차이 갱신

		if (curArrIndex + 1 == M) // 조의 맨뒤면 break
			break;
		
		minNum = min(minNum, v[curIndex][curArrIndex + 1]); // 현 최소값 갱신
		pq.push({ v[curIndex][curArrIndex + 1] ,{curIndex,curArrIndex + 1} }); // 뒷사람 삽입
		

		
	}

	cout << rs ;

   
    return 0;
}

