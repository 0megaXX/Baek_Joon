using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace baekjoon_with_cp4
{
    class Program
    {
        static void Main(string[] args)
        {

            HashSet<string> set= new HashSet<string>(); // 크로아티아 알파벳들
            set.Add("c=");
            set.Add("c-");
            set.Add("dz=");
            set.Add("d-");
            set.Add("lj");
            set.Add("nj");
            set.Add("s=");
            set.Add("z=");

            char start_leng = 'a';

            for (int a = 0; a < 26; a++)
            {
                set.Add(((char)(start_leng + a)).ToString());
            }

            string s = Console.ReadLine();

            int ct = 0;

            for (int a = 0; a < s.Length; a++)
            {
                if (set.Contains(s[a].ToString())) 
                {
                    string tmp = s[a].ToString();

                    while (a+1 < s.Length) // 현재 글자가 크로아티아 알파벳 리스트에 포함되어있다면
                    {
                        string cur = tmp + s[a + 1].ToString();

                        if (set.Contains(cur)) // 다음글자와 합친 글자가 크로아티아 알파벳리스트에 포함되어있다면
                        {
                            a++;
                            tmp = cur;
                        }

                        else
                        {
                            if (cur == "dz" && a+2 != s.Length) // dz는 없지만 dz=는 있기에 예외처리
                            {
                                a++;
                                tmp = cur;
                                continue;
                            }

                            if (tmp == "dz") // dz=가 아니라면 z부터 다시 시작
                                a--;

                            break;
                        }
                            
                    }

                }

                ct++;
            }


            Console.WriteLine(ct);

        }
    }

   
}
