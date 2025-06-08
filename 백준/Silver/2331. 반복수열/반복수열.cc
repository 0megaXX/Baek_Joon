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
    #include <regex>

    using namespace std;
    #define MAXX 2147483647

    vector<int> visit(999999);

    void bfs(string s, int p)
    {
        string num = s;

        vector<string> vec;
        vec.push_back(num);

        queue<string> q;
        q.push(num);
        visit[stoi(num)]++;

        while (!q.empty())
        {
            string x = q.front();
            q.pop();

            if (visit[stoi(x)] == 2)
                for (int a = 0; a < vec.size(); a++)
                    if (vec[a] == x)
                    {
                        cout << a;
                        return;
                    }
                
            

            int len = x.length();
            int temp = 0;
            for (int a = 0; a < len; a++)
                temp += pow(stoi(x.substr(a, 1)), p);
            
            q.push(to_string(temp));
            vec.push_back(to_string(temp));
            visit[temp]++;
        }

    }

    int main() {

	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
       
        string a;
        int p;
        cin >> a >> p;

        bfs(a, p);


        return 0;
    }

  