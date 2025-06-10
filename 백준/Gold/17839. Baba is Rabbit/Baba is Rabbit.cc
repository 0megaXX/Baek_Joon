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

map<string, vector<string>> m;  // A -> list of B
set<string> rs;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) 
    {
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        m[s1].push_back(s3);
    }

  
    queue<string> q;
    q.push("Baba");

    while (!q.empty()) 
    {
        string cur = q.front();
        q.pop();

        for (string& parent : m[cur]) 
        {
            if (rs.count(parent)) 
                continue; // 중복 제거
            rs.insert(parent);
            q.push(parent);
        }
    }

    // Baba 자신은 포함 안 시켜야 함
    if (rs.count("Baba"))
        rs.erase("Baba");

    vector<string> output (rs.begin(), rs.end());
    sort(output.begin(), output.end());

    for (const string& s : output) 
        cout << s << '\n';
    

 
    
    return 0;
}

