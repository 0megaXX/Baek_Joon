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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;
    int now, same_height = 0;
    long long  rs  = 0;
    stack<pair<int, int>> st; // <높이 , 동일 키 수>


    for (int a = 0; a <cass; ++a) 
    {
        cin >> now;

        same_height = 1; // 현재 키와 같은 사람의 수 (초기는 자기 자신)

        while (!st.empty() && st.top().first < now) 
            // 현재사람보다 키가 작으면 앞의 작은 사람들은 다음사람을 못봄
        {
            rs += st.top().second; // 그 키와 같은 사람의 수
            st.pop();
        }


        if (!st.empty())
        {
            if (st.top().first == now) // 키가 같다면 서로 볼수있음
            {
                rs += st.top().second; // 같은 키 더하기
                same_height = (st.top().second + 1); // 같은 키 증가

                if (st.size() > 1)
                    ++rs;

                st.pop(); // 새로 갱신할거니 기존것은 제거
            }
            else 
                ++rs;
            
        }

        st.push(make_pair(now, same_height));
    }

    cout << rs << '\n';
    return 0;

}