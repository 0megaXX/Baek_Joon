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

string s;
deque<char> DQ;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> s;
    char cur ;
    for (int a = 0; a < s.size(); a++)
    {
        // 사전순으로 제일 앞선것을 만들어야 하기에 비교
        
        cur = s[a];
        if (a==0)  // 처음엔 그냥 삽입
            DQ.push_back(cur);
            
        else if (DQ.front() >= cur) // 맨 앞과 비교
            DQ.push_front(cur);   
              
        else if (DQ.back() <= cur)  // 맨 끝과 비교
            DQ.push_back(cur);

        else // 삽입
            DQ.push_back(cur);
    
    }
     while (!DQ.empty())
    {
        cout << DQ.front();
        DQ.pop_front();
    };
    return 0;
}

