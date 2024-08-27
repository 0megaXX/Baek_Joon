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

#define MAXX 9987654321
using namespace std;


vector<int>v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N;
    cin >> N;
    v.resize(N);
    int left, right, sumA, sumB, rs;
    int ans = MAXX;
    for (int a = 0; a < N; a++) 
        cin >> v[a];
    

    sort(v.begin(), v.end());

    for (int a = 0; a < N - 3; a++) // a는 범위의 시작이자 가장 작은값
        for (int b = a + 3; b < N; b++) // b는 범위의 끝이자 가장 큰 값
        {

           // cout << "현재 좌항은 " << a << " 우항은 " << b << endl;
            left = a + 1; // 범위보다 작아야함
            right = b - 1; // 범위보다 작아야함

            sumA = v[a] + v[b]; // 현 범위의 최대값 +  최소값
            while (left < right) // 안겹친다면
            {
                sumB = v[left] + v[right]; 
                rs = abs(sumA - sumB); // 차이
                ans = min(ans, rs); // 차이 갱신

                if (ans == 0) // 차이가 없다면 더 이상 갱신할 필요가 없음.
                {
                    cout << ans; 
                    return 0;
                }

                if (sumA > sumB)  // 현재 최대값 + 최소값보다 합이 작다면 값을 증가
                    left++;

                else // 아니라면 값을 감소
                    right--;
            }
        }
    

    cout << ans;


}