using System;

namespace Algorithms.DynamicProgramming
{
    public class LongestCommonSubsequence
    {
        public static int LCS(string word1, string word2)
        {
            int len1 = word1.Length, len2 = word2.Length;
            int[,] dp = new int[2, len2 + 1];

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j <= len2; j++)
                {
                    dp[i, j] = 0;
                }
            }

            int currentRow = 1;
            for (int i = 1; i <= len1; i++)
            {
                for (int j = 1; j <= len2; j++)
                {
                    if (word1[i - 1] == word2[j - 1])
                    {
                        dp[currentRow, j] = 1 + dp[1 - currentRow, j - 1];
                    }
                    else
                    {
                        dp[currentRow, j] = Math.Max(dp[1 - currentRow, j], dp[currentRow, j - 1]);
                    }
                }

                currentRow = 1 - currentRow;
            }

            return dp[1 - currentRow, len2];
        }

        public static void Main()
        {
            Console.WriteLine(LCS("AGGTA", "GXTXAY"));
        }
    }
}

/*
 * Time complexity: O(nm)
 * Space complexity: O(m)
 */