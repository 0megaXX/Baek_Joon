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

    int N;
    cin >> N ;

    for (int a = 0; a < N; a++)
    {
        int p, l;
        cin >> p >> l;
        Set.insert({ l,p });
        Map[p] = l;
    }

    int M;
    cin >> M;

    while (M--) {
        string commend;
        cin >> commend;

        if (commend == "recommend")
        {
            int order;
            cin >> order;
            if (order == 1)
             {
                auto it = Set.rbegin(); // set 맨 뒤에 있는 문제
                cout << it->second << "\n";
            }
            else 
            {
                auto it = Set.begin(); // 가장 앞에 있는 문제
                cout << it->second << "\n";
            }
        }
        else if (commend == "add")
        {
            int problem, level;
            cin >> problem >> level;
            Set.insert({ level,problem });
            Map[problem] = level;
        }
        else {
            int problem;
            cin >> problem;

            // 문제 번호를 키로 값인 난이도 확인
            Set.erase({ Map[problem],problem });
        }
    }
}


