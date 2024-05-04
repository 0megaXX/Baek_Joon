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


 int K, N;

    int bfs(string str)
    {
        queue<pair<string, int>> q;
        q.push({ str, 0 });
        unordered_map<string, bool> visited;
        string target = str;
        sort(target.begin(), target.end());

        while (!q.empty())
        {
            string curent = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (curent == target)
                return cnt;
            
            if (!visited.count(curent)) //현재 글자를 만들어 본 적이 없다면
            {
                visited[curent] = true;
                for (int a = 0; a <= N - K; a++)
                {
                    string temp = curent.substr(a, K);
                    reverse(temp.begin(), temp.end());
                    q.push({ curent.substr(0, a) + temp + curent.substr(a + K, curent.size()), cnt + 1 });
                    //0 부터 a까지의 문자열 + a부터 K간격의 문자열 + 나머지 문자열
                }
            }
        }
        return -1;
    }
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    cin >> N >> K;

    cin.ignore();
    string str;
    getline(cin, str);

    while (str.find(' ') != str.npos) // 공백을 찾았다면 지워 하나의 문자열로 만듬.
    {
        str.erase(str.find(' '), 1);
    }
    cout << bfs(str);

}