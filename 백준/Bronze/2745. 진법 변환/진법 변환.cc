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

using namespace std;
#define MAXX 2147483647



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string s;
	int b, sum = 0;
	cin >> s >> b;
	for (int a = 0; a < s.size(); a++)
	{	// 문자열 크기만큼 반복
		if (s[a] >= '0' && s[a] <= '9') 
				// 수가 문자가 아닌 경우
			sum = sum * b + (s[a] - 48);		// 문자 0 의 아스키코드 : 48
		
		else
			sum = sum * b + (s[a] - 65 + 10);		// 문자 A 의 아스키코드 : 65
	}
	cout << sum;
	return 0;

}