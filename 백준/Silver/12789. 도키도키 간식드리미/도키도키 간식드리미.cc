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

#define MAXX 1000000000
using namespace std;

stack<int> st;
int N, T, cnt = 1;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N; // 학생들의 수. 

	while (N--)
	{
		cin >> T;

		if (T == cnt) 
			cnt++; // 현재 순번과 같다면 패스

		else 
			st.push(T); // 아니면 대기. 

		while (!st.empty() && st.top() == cnt) 
		{
			st.pop();  
			cnt++;
		}
	}

	if (st.empty())
		cout << "Nice"; 

	else
		cout << "Sad";
}


