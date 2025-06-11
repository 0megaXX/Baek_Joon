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

// (n-1)C(m-2)

long long fn(long long two, long long p, long long mood) 
{
	long long summ = 1;

	while (p) 
    {
		if (p % 2)
            summ = summ * two % mood;
        
		two = two * two % mood;
		p /= 2;
	}

	return summ;
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
	cin >> n;
    
	if (n == 0) 
        cout <<1;
	else 
        cout<< fn(2, n - 1, 1000000007);



   

    return 0;
}

