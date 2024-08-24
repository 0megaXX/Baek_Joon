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

vector<int>arr;

int cass;
long long rs = 0;

void fn()
{

    sort(arr.begin(), arr.end()); // 정려


    for (int a = 0; a < cass; a++) // a는 세명중 한명의 위치
    {
        int L_idx = a+1; // 
        int R_idx = arr.size()-1;

        while (L_idx < R_idx) // 겹치거나 넘으면 종료
        {
            
            if (arr[a]+arr[L_idx] + arr[R_idx] == 0)//세 합이 0이라면
            {


                if (arr[L_idx] == arr[R_idx]) // 같은경우 예외처리
                {
                    long long tmp = 0;
                    
                    int limit = R_idx - L_idx;

                    for (int a = 1; a <= limit; a++)
                        tmp += a;
                    rs += tmp;
                    break;

                }


                int ori = L_idx;
                int cur_L_val = 0, cur_R_val = 0;

                while (arr[a] + arr[L_idx] + arr[R_idx] == 0 && L_idx < R_idx) 
                    // 세합이 0이면서 서로 다른 사람이라면
                {

                    if (L_idx >= arr.size()) // 아웃오브레인지 방지
                        break;
                   
                    cur_L_val++;
                    L_idx++;
                   
                }

                while (arr[a] + arr[ori] + arr[R_idx] == 0 && ori < R_idx)
                    // 세합이 0이면서 서로 다른 사람이라면
                {

                    if (R_idx < 0) // 아웃오브레인지 방지
                        break;

                    
                    cur_R_val++;
                    R_idx--;

                }

              
                rs = rs + (cur_L_val * cur_R_val);


            }
            else if (arr[a] + arr[L_idx] + arr[R_idx] > 0) // 합이 0보다 크다면 값을 낮춰야함
                R_idx--;
            else // 합이 0 보다 작다면 값을 올려야함
                L_idx++;



        }

       
    }
     cout << rs;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    cin >> cass;

    for (int a = 0; a < cass; a++)
    {
        int b;
        cin >> b;
        arr.push_back(b);   
    }

    fn();
}
