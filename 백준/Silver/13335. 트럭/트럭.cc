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

int n, w, L, ans;
vector<int>truck(1001);
queue<int> q;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w >> L; // 트럭수, 다리 길이, 최대하중
    for (int a = 0; a < n; a++) 
        cin >> truck[a];

    int weightSum = 0; // 다리 위의 트럭 무게의 합
    for (int a = 0; a < n; a++)
    {
        while (1) {
            if (q.size() == w)
            {
                weightSum -= q.front(); // 맨 앞의 트럭 제거
                q.pop();
            }

            if (truck[a] + weightSum <= L) // 현재 트럭이 올라가도 괜찮다면
                break;
            
            q.push(0); // 무게가 L을 넘는 경우
            ans++;
        }
        q.push(truck[a]);
        weightSum += truck[a];
        ans++;
    }

    cout << ans + w; // 마지막 트럭이 건너는 시간(W) 추가

}