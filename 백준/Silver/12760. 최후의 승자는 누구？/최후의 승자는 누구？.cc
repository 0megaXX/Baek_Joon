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

vector<vector<int>>v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    v.resize(n, vector<int>(m));
    for (int a = 0; a < n; a++)
        for (int b = 0; b < m; b++)
            cin >> v[a][b];

     for (int a = 0; a < n; a++)
          sort(v[a].rbegin(), v[a].rend());

    
    vector<int> score(n, 0);

    for (int round = 0; round < m; round++) 
    {
        int maxVal = -1;
        for (int player = 0; player < n; player++)  // 각 라운드에서 가장 큰 값 찾기
            maxVal = max(maxVal, v[player][round]);
        

        for (int player = 0; player < n; player++) 
            if (v[player][round] == maxVal) // 각 라운드에서 가장 큰 값의 플레이어의 우승수 증가
                score[player]++;
        
    }

    int maxScore = *max_element(score.begin(), score.end());

    for (int a = 0; a < n; a++) 
        if (score[a] == maxScore)
            cout << a+1 << " ";
    

    return 0;
}



