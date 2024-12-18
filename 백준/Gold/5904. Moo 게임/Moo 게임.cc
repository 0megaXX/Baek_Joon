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

vector<long long> arr_moo; // 수열의 길이를 저장할 벡터

void fn(long long target, int n)
{
    long long cur_len;
    while (n >= 0) 
    {
        
        cur_len = arr_moo[n]; // 현재 Moo(n)의 길이
     //  cout<<"level "<<n<< " find pos "<<cur_len<<" and taerget is "<<target<<endl;
       
        if (target > cur_len) 
            n++;
        
        else {
             if (n!=0 && target <= arr_moo[n - 1]) 
             { n--; // 이전 수열로 가기
                continue;
             }
            // 현재 수열의 앞부분(Moo(n-1))을 제외한 길이를 빼주기
            if (n != 0) 
                target -= arr_moo[n - 1];
            

            // 중간의 'o' 구간이 아닌지 확인
            if (target == 1) {
                cout << 'm'; // 'm'은 항상 첫 번째
                return;
            } 
            else if (target >= 2 && target <= n + 3) {
                cout << 'o'; // 중간의 'o' 부분
                return;
            } 
            else {
             
              
                    // 'Moo(n-1)'의 뒤부분에서 찾는다면, 재귀적으로 이전 수열로 이동
                    target -= (n + 3); // 중간의 'm'과 'o'들을 제외하고
                    n--; // 이전 수열로 가기
                
            }
        }
    }

   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

      arr_moo.push_back(3);  // Moo(0)의 길이는 3 (moo)

    // 수열 길이 계산: Moo(n)의 길이 = 2 * Moo(n-1) + (n + 3)
    for (int i = 1; i <= 40; i++) {
        arr_moo.push_back(2 * arr_moo[i - 1] + (i + 3));
        //cout<<arr_moo[i]<<endl;
        if (arr_moo[i] > 1000000000) 
            break; // 필요 이상으로 커지면 종료
    }

    long long len;
    cin >> len;


    fn(len, 0);
    return 0;
}