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

#define MAXX 987654321

using namespace std;
int len;

bool perfect(string str)
{
    int sum = 0; // 최종값
    int tmp = 0; // 수식의 진행을 저장
    char sign = '+';
    int len = str.length();

    for (int a = 0; a < len; a++)
    {

        if (str[a] >= '0' && str[a] <= '9') // 숫자라면
        {
         
            tmp = tmp * 10 + (str[a] - '0'); // tmp를 한칸 밀고 값 삽입 ( 숫자가 연속인 경우의 처리 )

            if(a==len-1) // 문자의 끝이라면 tmp의 값을 최종값에 넣어야함.
            {

                if (sign == '+') // 최종 넣을곳에 음수로 넣을지 양수로 넣을지 결정
                    sum += tmp;
                else
                    sum -= tmp;

            }


        }

        else if (str[a] == '-' || str[a] == '+') // 부호라면
        {
            if (sign == '+') // 부호를 적용전에 기존 걸 처리 
                sum += tmp;
            else
                sum -= tmp;

            tmp = 0; // tmp의 내용을 최종값에 적용했으니 초기화

            sign = str[a];


        }

    }
   

    if (sum == 0) // 0으로 끝나면
        return true;
    else
        return false;




}



void DFS(int cur, string str)
{
    if (cur == len) // 현재수식의 진행이 최대 수식의 진행 길이라면
    {
        if (perfect(str))
            cout << str << '\n';

    }
    else // 아직 더 수식을 만들어야 한다면 
    {
        DFS(cur + 1, str + " " + to_string(cur + 1)); // 숫자를 이어 붙이는 경우
        DFS(cur + 1, str + "+" + to_string(cur + 1)); // 덧셈을 이어 붙이는 경우
        DFS(cur + 1, str + "-" + to_string(cur + 1)); // 뺄셈을 이어 붙이는 경우

    }


}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;
    while (cass--) 
    {
        cin >> len;
        string s ="1"; // 시작은 1부터

        DFS(1, s);
       
        cout << '\n';
    }
}
