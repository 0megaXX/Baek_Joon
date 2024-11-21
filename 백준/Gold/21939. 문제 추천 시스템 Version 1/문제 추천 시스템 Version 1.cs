using System;
using System.Data;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
					
public class Program
{
	public static void Main()
	{


            Dictionary<int, int> dic = new Dictionary<int, int>(); // 문제 번호와 난이도
            SortedList<int, SortedSet<int>> list = new SortedList<int, SortedSet<int>>(Comparer<int>.Create((x, y) => y.CompareTo(x)));  // 난이도 내림차순으로 정렬되는 SortedList

            int N = int.Parse(Console.ReadLine());

            // 문제 입력 받기
            for (int a = 0; a < N; a++)
            {
                String[] s = Console.ReadLine().Split(); // P, L
                int problemNum = int.Parse(s[0]);
                int difficulty = int.Parse(s[1]);

                dic.Add(problemNum, difficulty);

                // 난이도 별로 문제 번호를 기록
                if (!list.ContainsKey(difficulty))
                {
                    list[difficulty] = new SortedSet<int>();
                }
                list[difficulty].Add(problemNum);
            }

            
            int M = int.Parse(Console.ReadLine());

            for (int a = 0; a < M; a++)
            {
                string[] commend = Console.ReadLine().Split();

                switch (commend[0])
                {
                    case "add":
                        int addP = int.Parse(commend[1]);  // 문제 번호
                        int addL = int.Parse(commend[2]);  // 난이도

                        if (dic.ContainsKey(addP))
                        {
                            int oldDifficulty = dic[addP];
                            list[oldDifficulty].Remove(addP);  // 기존 난이도의 문제 번호 제거

                            if (list[oldDifficulty].Count == 0)
                            {
                                list.Remove(oldDifficulty);  // 난이도가 더 이상 없으면 해당 난이도를 삭제
                            }
                        }

                        // 새로운 난이도에 맞게 추가
                        dic[addP] = addL;
                        if (!list.ContainsKey(addL))
                        {
                            list[addL] = new SortedSet<int>();
                        }
                        list[addL].Add(addP);
                        break;

                    case "recommend":
                        int cass = int.Parse(commend[1]); 

                        if (cass == 1) // 가장 난이도가 높은 문제번호 출력
                        {
                            Console.WriteLine(list.First().Value.Max);  // 가장 난이도가 높은 문제 번호
                        }
                        else // 가장 난이도가 낮은 문제번호 출력
                        {
                            Console.WriteLine(list.Last().Value.Min);  // 가장 난이도가 낮은 문제 번호
                        }

                        break;

                    case "solved":
                        int rm = int.Parse(commend[1]);  // 해결된 문제 번호

                        if (dic.ContainsKey(rm))
                        {
                            int rmDifficulty = dic[rm];
                            list[rmDifficulty].Remove(rm);  // 세트에서 제거

                            if (list[rmDifficulty].Count == 0)
                            {
                                list.Remove(rmDifficulty);  // 난이도가 더 이상 없으면 해당 난이도를 삭제
                            }

                            dic.Remove(rm);  // 딕셔너리에서 제거
                        }
                        break;
                }
            }
        
    
}

	
}