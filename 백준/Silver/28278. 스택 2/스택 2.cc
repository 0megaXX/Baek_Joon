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




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, m, num;
	stack<int> stack;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		switch (m) {
		case 1:
			cin >> num;
			stack.push(num);
			break;
		case 2:
			if (!stack.empty())
			{
				cout << stack.top() << "\n";
				stack.pop();
			}
			else
				cout << "-1 \n";
			break;
		case 3:
			cout << stack.size() << "\n";
			break;
		case 4:
			if (stack.empty())
				cout << "1\n";
			else 
				cout << "0\n";
			break;
		case 5:
			if (!stack.empty()) 
				cout << stack.top() << "\n";
			else 
				cout << "-1\n";
			break;
		}
	}


}