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


vector<int> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<stack<int>> sv(4);
    
    int n;
    cin >> n;
    v.resize(n);
    
    for (int a = 0; a < n; a++)
        cin >> v[a];
    
    bool possible = true;

    int num ;
    int min_maxNum ;
    int idx ;
    
    for (int i = 0; i < n; i++)
    {
        num = v[i];
        min_maxNum = -1;
        idx = -1;
        
        for (int b = 0; b < 4; b++)
        {
            if (sv[b].empty())
            {
                if (min_maxNum < 0) // 아직 num을 넣지 않았다면
                {
                    min_maxNum = 0;
                    idx = b;
                }
            }
                
            else 
            {
                if (sv[b].top() < num) // 거꾸로 뺄 때 오름차순으로 만들 수 있다면 (스택을 내림차순으로 만들 수 있다면)
                    if (min_maxNum < sv[b].top()) // 네개의 스택들 중 넣을 수보다 작은 수 중 제일 큰 수 선별
                    {
                        min_maxNum = sv[b].top(); // 제일 큰 수 
                        idx = b;
                    }
                
            }
            
        }
        
        if (idx == -1) // 삽입 못하는 경우 
        {
            cout << "NO";
            return 0;
        }
        
        sv[idx].push(num);
        
    }
    
    cout << "YES";
   

    return 0;
}

