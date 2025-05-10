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

    stack<double> st;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int N;          // 피연산자 개수
    string pos; // 후위 표기식

    vector<int> operand(26); // 입력한 피연산자

    cin >> N >> pos;

    for (int a = 0; a < N; a++)
        cin >> operand[a];
    

    // 후위표기식의 길이 만큼 반복
    for (int a = 0; a < pos.length(); a++)
    {
        // 피연산자인 경우
        if (pos[a] >= 'A' && pos[a] <= 'Z')
        {
            st.push(operand[pos[a] - 'A']);
        }
        else // 연산자인 경우
        {
            if (!st.empty())
            {
                double tmp = st.top();
                st.pop();
                switch (pos[a])
                {
                case '+':
                    tmp = st.top() + tmp;
                    break;
                case '-':
                    tmp = st.top() - tmp;
                    break;
                case '*':
                    tmp = st.top() * tmp;
                    break;
                case '/':
                    tmp = st.top() / tmp;
                    break;
                }
                st.pop();
                st.push(tmp); 
            }
        }
    }
    // 소수점 둘째 자리까지 출력
    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';

}

 