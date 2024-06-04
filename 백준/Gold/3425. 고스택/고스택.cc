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
#define max_value 1000000000
#define min_value -1000000000


using namespace std;
stack<long long> st;

void num(int x) {
    st.push(x);
}

int pop() {
    if (st.empty()) {
        return -1;
    }
    else {
        st.pop();
        return 1;
    }
}

int inv() {
    if (st.empty()) {
        return -1;
    }
    else {
        long long temp = st.top() * -1;
        st.pop();
        st.push(temp);
        return 1;
    }
}

int dup() {
    if (st.empty()) {
        return -1;
    }
    else {
        st.push(st.top());
        return 1;
    }
}

int swp() {
    if (st.size() < 2) {
        return -1;
    }
    else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        st.push(first);
        st.push(second);
        return 1;
    }
}

int add() {
    if (st.size() < 2) {
        return -1;
    }
    else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        long long temp = first + second;
        if (temp < min_value || temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int sub() {
    if (st.size() < 2) {
        return -1;
    }
    else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        long long temp = second - first;
        if (temp < min_value || temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int mul() {
    if (st.size() < 2) {
        return -1;
    }
    else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        long long temp = first * second;
        if (temp < min_value || temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int div() {
    if (st.size() < 2) {
        return -1;
    }
    else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        if (first == 0) {
            return -1;
        }
        long long temp = second / first;
        if (temp < min_value || temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int mod() {
    if (st.size() < 2) {
        return -1;
    }
    else {
        long long first = st.top();
        st.pop();
        long long second = st.top();
        st.pop();
        if (first == 0) {
            return -1;
        }
        long long temp = second % first;
        if (temp < min_value || temp > max_value) {
            return -1;
        }
        st.push(temp);
        return 1;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while (1) {
        vector<string> v;
        string str;

        while (true) //명령 삽입
        {
            cin >> str;

            if (str == "END") 
                break;
            
            else if (str == "QUIT") 
                return 0;
            
            v.push_back(str);
        }

        int cass;
        cin >> cass;
        while (cass--)
        {
            long long Num;
            cin >> Num;
            int Error = 0;
            st.push(Num);
            for (int i = 0; i < v.size(); i++) 
            {
                if (v[i] == "NUM")
                {
                    num(stoi(v[i + 1]));
                    i += 1; //NUM은 뒤에 숫자가 붙기에 한칸 추가로 전진
                }
                else if (v[i] == "POP") 
                    Error = pop();
                
                else if (v[i] == "INV") 
                    Error = inv();
                
                else if (v[i] == "DUP") 
                    Error = dup();
                
                else if (v[i] == "SWP") 
                    Error = swp();
                
                else if (v[i] == "ADD") 
                    Error = add();
                
                else if (v[i] == "SUB") 
                    Error = sub();
                
                else if (v[i] == "MUL") 
                    Error = mul();
                
                else if (v[i] == "DIV") 
                    Error = div();
                
                else if (v[i] == "MOD") 
                    Error = mod();
                

                if (Error == -1) //만약 에러가 발생했으면
                {
                    cout << "ERROR" << '\n';
                    while (!st.empty())  //다음에 스택을 쓰기위해 비워줌.
                        st.pop();
                    
                    break;
                }
            }

            if (Error == -1)  
                continue;
            

            if (st.size() != 1) // 스택에 한개만 남지 않았다면 뭔가 오류임
            {
                cout << "ERROR\n";
                while (!st.empty())  //다음에 스택을 쓰기위해 비워줌.
                    st.pop();
                
            }
            else 
            {
                cout << st.top() << '\n';
                st.pop();
            }

        }
        cout << '\n';
    }

    return 0;
}