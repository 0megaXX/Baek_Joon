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

#define MAXX 987654321
using namespace std;

vector<pair<long long, long long>>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    int cass;
    cin >> cass;
    long long sum = 0;
    for (int a = 0; a < cass; a++)
    {
        int cur, human;
        cin >> cur >> human;
        v.push_back({ cur,human });
        sum += human; // 누적합
    }
    

    sort(v.begin(), v.end());

    long long tmp = 0;
    for (int a = 0; a < cass; a++)
    {
        tmp += v[a].second;

        if (tmp >= (sum + 1) / 2) // 현재 위치까지의 사람수가 전체사람의 반보다 많다면
        {
            cout << v[a].first;
            return 0;
        }

    }
}
