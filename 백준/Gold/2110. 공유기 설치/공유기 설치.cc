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

    int N, C;
    cin >> N >> C;


    vector<int>v(N);
    for (int a = 0; a < N; a++)
        cin >> v[a];

    sort(v.begin(), v.end());   

    int rs;
    int L = 1; // 최소 간격
    int R = v[N - 1] - v[0]; // 최대 간격

    while (L<=R)
    {
        int install = 1; //  첫지점에 공유기는 기본 설치
        int start = v[0]; // 처음위치를 시작으로 잡기
        int mid = (L + R)/2; // 기준 간격

        for (int a = 1; a < N; a++)
        {
            int next = v[a]; // 다음 공유기 위치

            // 두 공유기의 간격이 기준 간격을 넘었다면 
            if (next - start >= mid)
            {
                install++;
                start = next; // 다음 위치를 시작으로
            }


        }

        // 설치한 공유기 개수가 C개 이상이라면,
        if (install >= C)
        {
            rs = mid; // 갱신
            L = mid + 1; // 이분법을 사용한 간격 갱신 시, 이전보다 넓은 간격을 사용하기 위해, L 수정
        }

        // 설치한 공유기 개수가 C개 미만이라면,
        else 
            R = mid - 1; // 이전보다 좁은 간격을 사용하기 위해, R 수정
    }

    cout << rs;

    return 0;
}