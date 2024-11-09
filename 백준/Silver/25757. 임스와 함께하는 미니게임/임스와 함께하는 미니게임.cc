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

map<string, int>m;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char c;
    cin >> N >> c;

    for (int a = 0; a < N; a++)
    {
        string s;
        cin >> s;
        if (m.find(s) == m.end()) // 없다면
            m[s]++;
    }

    int play;
    
    if (c == 'Y')//윷놀이면
        play = 1;
    else if (c == 'F')//같음그림 찾기면
        play = 2;
    else // 원카드면
        play = 3;

    cout << m.size() / play;


}


