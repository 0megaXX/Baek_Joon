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



bool prime[10000001];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    int t;
    cin >> t;

    int k = 1;
    int ans = 2 ;
   
	while (k < t)
	{
		if (prime[ans])
            continue;

		int n = 1;
       
		while (ans * n <= 10000000)
		{
			prime[ans * n] = true;
			n++;
		}
		
		ans++;
       
		while (prime[ans])
            ans++;
       
		k++;
	}
   
	cout << ans;

    return 0;
}