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



vector<int> v;
vector<int> summ;
vector<pair<int, int>> input;
unordered_map<int, int> m;
unordered_map<int, int> rev;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
	cin >> n;

	for (int a = 0; a < n; a++)
	{
		int s, e;
		cin >> s >> e;
		input.push_back({ s, e });
		v.push_back(s);
		v.push_back(e);
	}

	sort(v.begin(), v.end());

	int idx = 0;
    
	for (auto& i : v)
		if (m.find(i) == m.end())
		{
			m.insert({ i, idx });
			rev.insert({ idx++, i });
		}
	

	summ.resize(idx);
    
	for (auto& i : input)
	{
		summ[m[i.first]]++;
		summ[m[i.second]]--;
	}

	for (int a = 1; a < summ.size(); a++)
		summ[a] += summ[a - 1]; // 누적

	int res = 0;
    
	for (auto& i : summ)
		res = max(res, i);

	cout << res << '\n';

	int em, xm;
	bool flag = 0;
    
	for (int a = 0; a < summ.size(); a++)
	{
		if (!flag && summ[a] == res)
		{
			flag = true;
			em = rev[a];
		}
        
		if (flag && summ[a] != res)
		{
			xm = rev[a];
			break;
		}
	}

	cout << em << ' ' << xm;
    
	return 0;
   
}