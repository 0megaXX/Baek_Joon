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


int parent[4000001];
vector<int> v;

int find_parent(int a) 
{
	if (parent[a] == a)
        return a;    
	else
        return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
    b = find_parent(b);
    
	if (a == b) // 이미 연결됐다면 의미X
        return;
    
	parent[a] = b;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    v.resize(m);
	for (int a = 0; a < m; a++) 
    {
		int b;
		cin >> b;
		v[a] = b;
		parent[a] = a;
	}
    
	sort(v.begin(), v.end());
    
	for (int a = 0; a < k; a++) 
    {
		int b;
		cin >> b;
        
        // 민수보다 큰 카드중 가장 작은 카드의 위치
		int cur = find_parent(upper_bound(v.begin(), v.end(), b) - v.begin()); 

		cout << v[cur] << '\n';
		union_parent(cur, cur + 1); // 한번 나온 값을 두번은 사용못하기에 1높은 값과 union
	}
   
    return 0;
}
