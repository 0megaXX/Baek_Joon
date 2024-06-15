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
#include <unordered_map>


using namespace std;

long long dp[101][101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string S;
	vector<string>V;
	cin >> S;

	string tmp = "";
	for (int a = S.length()-1; a>=0; a--)
	{
		char cur = S[a];
		tmp = cur + tmp;
		V.push_back(tmp);
	}

	sort(V.begin(), V.end());
	for (int a = 0; a < V.size(); a++)
		cout << V[a] << '\n';

	return 0;
}