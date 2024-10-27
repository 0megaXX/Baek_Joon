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

#define MAXX 1000000005
using namespace std;

map<string, vector<string>>G;
map<string, string>M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int group, Q;
    cin >> group >> Q;

    for (int a = 0; a < group; a++)
    {

        string group_name;
        cin >> group_name;
        int group_mem;
        cin >> group_mem;
        for (int b = 0; b < group_mem; b++)
        {
            string name;
            cin >> name;
            G[group_name].push_back(name);
            M[name] = group_name;

        }

    }


    for (auto itr = G.begin(); itr != G.end(); itr++) // 사전순 정렬을 위한 로직
    {
        string grp = itr->first; // 그룹이름 
        sort(G[grp].begin(), G[grp].end());
    }


    for (int a = 0; a < Q; a++)
    {
        string name;
        cin >> name;
        int t;
        cin >> t;
        
        if (t == 0) // 팀이름
            for (auto a = G[name].begin(); a != G[name].end(); a++)
                cout << *a << '\n';

        else // 맴버이름
            cout << M[name] << '\n';


    }

    return 0;
}