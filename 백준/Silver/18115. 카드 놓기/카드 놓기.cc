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
#define MAXX 987654321
using namespace std;

deque<int>dq;

vector<int>rs(1000001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int cass;
	cin >> cass;
	vector<int>commend(cass);
	for (int a = 0; a < cass; a++)
		cin >>commend[a];

	int card = 1;
	for (int a = cass - 1; a >= 0; a--) {

		if (commend[a] == 1) 
			dq.push_back(card);
		
		else if (commend[a] == 2) 
		{
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(tmp);
		}
		else  
			dq.push_front(card);
		

		card++;
	}

	for (int a = cass - 1; a >= 0; a--) 
		cout << dq[a] << ' ';
	
}