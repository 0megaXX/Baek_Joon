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

#define MAXX 1000000000
using namespace std;

set<pair<int, int>>Set;
map<int, int> Map;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int in;

    priority_queue<int> pq;
    while (n--) {
        cin >> in;
        if (in == 0)
        {
            if (pq.empty())
            {
                cout << -1 << "\n"; 
                continue; }
            int t = pq.top(); pq.pop();
            cout << t << "\n";
        }
        else 
        {

            while (in--) {
                int t;
                cin >> t;
                pq.push(t);
            }
        }
    }
}


