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

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int ct, sizz, tmp;
    cin >> ct;

    while (ct--) {
        cin >> sizz;
        int answer = 0;
        vector<int> student;

        cin >> tmp;
        student.push_back(tmp);

        for (int a = 1; a < 20; a++) 
        {
            cin >> tmp;
            bool check = true;
            int min_tmp = -1;

            for (int b = student.size() - 1; b >= 0; b--) 
                if (student[b] > tmp) 
                    min_tmp = b;
                
            if (min_tmp == -1)
                student.push_back(tmp); 
            else 
            {
                answer += student.size() - min_tmp;
                student.insert(student.begin() + min_tmp, tmp);
            }
        }

        cout << sizz << " " << answer << '\n';
    }
}