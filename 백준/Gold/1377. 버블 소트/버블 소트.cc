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

vector<pair<int,int>>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    v.resize(N+1);
    for (int a = 1; a <= N; a++)
    {
        int b;
        cin >> b;
        v[a] = { b,a }; // 값과 초기 위치
    }

    sort(v.begin(), v.end());
    int rs = 0;
    for (int a = 1; a <= N; a++)
        rs = max(rs, v[a].second - a+1);

    cout << rs;
}