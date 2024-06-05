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

//struct Trie
//{
//    bool finish; // 문자가 끝나면 트루로 변경
//    Trie* next[26]; // 26가지 알파벳에 대한 트라이
//    int ct;
//
//    // 생성자
//    Trie() 
//    {
//        finish = false;
//        memset(next, 0, sizeof(next));
//        ct = 1;
//    }
//
//    // 소멸자
//    ~Trie()
//    {
//        for (int i = 0; i < 26; i++)
//            if (next[i])
//                delete next[i];
//    }
//
//    // 트라이에 문자열 삽입
//    void insert(const char* key)
//    {
//
//      //  cout << *key << "호아!\n";
//        if (*key == '\0') // 문자열이 끝나는 지점일 경우
//        {
//            finish = true;
//        }
//        else
//        {
//
//            int curr = *key - 'a';
//            if (next[curr] == NULL)
//            {
//                cout << *key << endl;
//                next[curr] = new Trie();  // 탐색이 처음되는 지점일 경우 동적할당
//
//            }
//            else
//            {
//                cout << *key;
//                next[curr]->insert(key + 1); // 다음 문자 삽입
//            }
//        }
//    }
//
//    // 트라이에서 문자열 찾기
//    Trie* find(const char* key) {
//        if (*key == '\0') // 문자열이 끝나는 위치를 반환
//            return this; 
//        int curr = *key - 'a';
//        if (next[curr] == NULL) // 다음 문자가 값이 존재하지 않음
//            return NULL; 
//        return next[curr]->find(key + 1); // 다음 문자를 탐색
//    }
//};
//




int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Trie T;
    int cass;
    cin >> cass;

    for (int a = 0; a < cass; a++)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        string s1_sub = s1;
        string s2_sub = s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s2 == s1)
            cout << s1_sub << " & " << s2_sub << " are anagrams.\n";
        else
            cout << s1_sub << " & " << s2_sub << " are NOT anagrams.\n";

    }
    return 0;
}