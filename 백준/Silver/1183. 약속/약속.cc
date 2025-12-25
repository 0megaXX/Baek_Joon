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

vector<int> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int N;
	cin >> N;

	for (int a = 0; a < N; a++)
	{
        int b, c;
		cin >> b >> c;
		v.push_back(c-b);
	}
   
	sort(v.begin(), v.end());
	
    if (N % 2 == 0)
	{
		int mid = N / 2 - 1;
		cout << v[mid+1] - v[mid] + 1;
	}
	else
		cout << 1 ;
	
   

    return 0;
}