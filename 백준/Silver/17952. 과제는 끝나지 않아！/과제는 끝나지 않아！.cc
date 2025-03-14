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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int, int>> st;
	int n, total_score = 0;
	int x, score, seconds;
	cin >> n;
    
	for (int a = 0; a < n; a++) 
    {
		cin >> x;

		if (x == 1) 
        {
			cin >> score >> seconds;
			st.push({seconds, score});
		}
        
		if (!st.empty())
        {
			st.top().first--;
			if (st.top().first == 0)
            {
				total_score += st.top().second;
				st.pop();
			}
		}
	}

	cout << total_score;
}