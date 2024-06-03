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
#include <unordered_map>

using namespace std;

struct Mystruct
{
    int Customer_Number;
    int Time;
    int Counter_Number;
};

int N, k;
vector< pair<int, int>>v;

struct pq_compare  //내보내는 우선순위
{
    bool operator()(Mystruct A, Mystruct B)
    {
        if (A.Time  == B.Time)
        {
            if (A.Counter_Number > B.Counter_Number) // 시간이 같다면 카운터 번호가 높을수록 빨리 내보내야함
                return true;

            return false;
        }
        else
        {
            if (A.Time > B.Time) // 시간이 다르면 시간이 짧을수록 빨리 나감
                return true;
            return false;
        }
    }
};



bool compare(Mystruct A, Mystruct B) // 나가는 compare
{
    if(A.Time == B.Time) // 시간이 같다면 카운터 번호가 높을수록 빨리 내보내야함
    {
        if(A.Counter_Number > B.Counter_Number)
        {
            return true;
        }
        return false;
    }
    else 
    {
        if(A.Time < B.Time)
            return true; 
        return false;
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> k;

    for (int a = 0; a < N; a++)
    {
        int id, many;
        cin >> id >> many;
        v.push_back({ id,many });
    }

    priority_queue<Mystruct, vector<Mystruct>, pq_compare> pq;
    vector<Mystruct>exit_order;
    bool flag = false;

    for (int a = 0; a < k; a++)
    {
        if(a == N) // 사람의 수보다 계산대의 수가 더 크다면 더이상 작업 X 
        {
            flag = true; 
            break;
        }
        int num = v[a].first;
        int Time = v[a].second;
        pq.push({ num, Time, a + 1 });
    }

    if (flag) // 이미 다 계산을 했다면
        while (!pq.empty())
        {
            exit_order.push_back(pq.top());
            pq.pop();
        }

    else
    {
        for (int a = k; a < N; a++)
        {
            int num = v[a].first;
            int Time = v[a].second;
            pq.push({ num, Time + pq.top().Time, pq.top().Counter_Number }); 
            // 현재 사람이 사용하는 시간은 자리를 비우는 사람의 시간만큼 더해야 함.
            
            exit_order.push_back(pq.top());
            pq.pop();
        }
        while (!pq.empty())
        {
            exit_order.push_back(pq.top());
            pq.pop();
        }
    }

    sort(exit_order.begin(), exit_order.end(), compare);
    long long ans=0;
    for (int a = 0; a < exit_order.size(); a++)
    {
        int num = exit_order[a].Customer_Number;
        long long sub = (long long)(a + 1) * (long long)num;
        ans += sub;
    }
    cout << ans;
    return 0;
}