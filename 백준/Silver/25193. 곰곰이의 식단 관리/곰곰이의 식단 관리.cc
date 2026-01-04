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


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int N;
	cin >> N;

	string s;
	cin >> s;

    int rs = 0;
    int nop = 0;
   
	for (int i = 0; i < s.size(); i++)
    {
		if (s[i] == 'C')
            rs++;
		else
            nop++;
	}
   
	if (rs % (nop+1) != 0)
        cout << rs / (nop+1) + 1;
       
	else
        cout << rs / (nop + 1);
   

    return 0;
}