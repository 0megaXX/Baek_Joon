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


int n, m;
string arr[502];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

   int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < 3; j++) {
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());
 
        cout << "Scenario #" << i + 1 << ":\n";
        
      
        if (pow(v[0], 2) + pow(v[1], 2) == pow(v[2], 2)) 
            cout << "yes\n\n";
        
        else 
            cout << "no\n\n";
        
    }
 
    return 0;
}

