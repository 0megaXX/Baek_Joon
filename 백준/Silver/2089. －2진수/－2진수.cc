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


bool arr[1000001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    string s;
   
	int n;
	cin >> n;
	
	if(!n)
        s = "0";
       
	else
    {
		while(n)
        {
			if(!(n % -2))
            {
				s += "0";
				n /= -2;
			}
			else
            {
				s += "1";
				n = (n - 1) / -2;
			}
		}
	}
	
	reverse(s.begin(), s.end());
	cout << s ;

    return 0;
}