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


vector<string> v;
map<string, int> Map;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int n, m, k;
	cin >> n >> m;

	for (int a = 0; a < n; a++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	cin >> k; 
	for (auto& it : v)
	{
		int z = 0;
		for (auto& j : it)
			if (j == '0') // 행에 꺼져있는 램프의 갯수
				z++;

        // 켜야하는 램프가 키는 횟수보다 작거나 켜야하는 램프와 키는횟수의 홀짝이 다르다면 패스 
        // 켜야하는 램프가 키는 횟수보다 작다면 어짜피 조건을 불충족
        // 홀짝이 같다면 껏다 키는게 가능하지만 다르다면 멀쩡한걸 꺼서 조건을 불충족
		if (z > k || (z % 2 != k % 2))  
			continue;
        
        // 조건 만족시 해당 램프들의 패턴과 횟수 저장
		if (Map.find(it) == Map.end()) 
			Map.insert({ it, 1 });
		else
			Map[it]++;
	}

	int rs = 0;
	for (auto& it : Map)
		rs = max(rs, it.second);
	cout << rs;
	return 0;
}