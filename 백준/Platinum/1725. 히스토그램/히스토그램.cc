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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);




        int n;
        cin >> n;



        vector<long long> heights(n);
        for (int i = 0; i < n; i++)
            cin >> heights[i];


        stack<int> st;
        //스택은 로직상 less형태이기에 스택의 top의 높이보다 뒤의 멤버들은 더 낮거나 같은 높이이기에

      //       /|
      //      / |
      //     /  | 
      //    /   |
      //   /    |
      //  /     |
      // /      |     -> 이런 느낌으로 만들어짐


        long long max_area = 0;

        for (int a = 0; a < n; a++) {
            while (!st.empty() && heights[st.top()] > heights[a])
                // 스택에 이미 값이 있고 현재위치보다 높다면
            {
                int h = heights[st.top()]; // 제일 높은 위치
                st.pop(); // 젤높은위치 pop
                int width = st.empty() ? a : a - st.top() - 1;
                // 스택이 오름차순이고 heights[a] < h 이기에 t.top() 뒤의 빌딩들은 heights[a] 의 높이 이상임
                max_area = max(max_area, h * (long long)width);
            }
            st.push(a);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            max_area = max(max_area, h * (long long)width);
        }

        cout << max_area << '\n';
    



    return 0;
}