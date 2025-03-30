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

using namespace std;
#define MAXX 2147483647

long long arr[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    for (int a = 1; a < 1000001; a++) 
    {
        for (int b = a; b < 1000001; b += a) 
            arr[b] += a;
        
        arr[a] += arr[a - 1];
    }

    int t;
    cin >> t;
    for (int a = 0; a < t; a++) 
    {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
    return 0; 
}

