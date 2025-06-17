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


int arr1[200001];
int arr2[200001];
priority_queue<pair<int, int>> pq;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
	N *= 24;

	for (int a = 0; a < M; a++)
        cin >> arr1[a];
    
	for (int a = 0; a < M; a++)
        cin >> arr2[a];

	for (int a = 0; a < M; a++) 
		if (arr1[a] < 100) 
            pq.push(make_pair(min(arr2[a], 100 - arr1[a]), a));
	

	while (N && !pq.empty()) 
    {
		int f = pq.top().second;
        int s = pq.top().first;
		arr1[f] += s;
		pq.pop();
		if (arr1[f] < 100)
            pq.push(make_pair(min(arr2[f], 100 - arr1[f]), f));
        N--;
	}

	int ans = 0;
    
	for (int a = 0; a < M; a++) 
        ans += arr1[a];

    cout << ans;
    
    return 0;
}

