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

using namespace std;


deque<int> dq;
int N, cmd, x;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	while (N--)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cin >> x;
			dq.push_front(x);
			break;
		case 2:
			cin >> x;
			dq.push_back(x);
			break;
		case 3:
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			break;
		case 5:
			cout << dq.size() << "\n";
			break;
		case 6:
			(dq.empty()) ? cout << 1 << "\n" : cout << 0 << "\n";
			break;
		case 7:
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
			}
			break;
		case 8:
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
			}
			break;
		}
	}
}