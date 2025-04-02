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

using namespace std;
#define MAXX 2147483647

struct lec
{
	int num, start, end;
};

struct cmp 
{
	bool operator()(lec a, lec b) 
    {
		return a.end > b.end; // 작은 값 우선
	}
};

bool cmp2(lec a, lec b)
{
	return a.start < b.start; // 작은 값 우선
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
	cin >> n;

	vector<lec> v(n, { 0,0,0 });
	vector<int> room(n, 0);
	priority_queue<lec, vector<lec>, cmp> q;

	for (int a = 0; a< n; a++)	
        cin >> v[a].num >> v[a].start >> v[a].end;
    
	sort(v.begin(), v.end(), cmp2);  

    int rs = 0;
	for (int a = 0; a < n; a++)
    {
		if (!q.empty() && (q.top().end <= v[a].start))  // 끝나는 시간에 들어갈 수 있다면
        {
			room[v[a].num-1] = room[q.top().num - 1]; // 방 이동
			q.pop();
		}
		else  // 없다면 다른 강의실
        {
			rs++;
			room[v[a].num-1] = rs;
		}
		q.push(v[a]);
	}

	cout << rs << '\n';
    
	for (int a = 0; a < n; a++) 
        cout << room[a] << '\n';
}

