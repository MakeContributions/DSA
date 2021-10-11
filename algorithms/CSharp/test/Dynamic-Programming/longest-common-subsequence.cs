using NUnit.Framework;

namespace Algorithms.Tests.DynamicProgramming
{
    [TestFixture]
    public class LongestCommonSubsequence
    {
        [TestCase("AGGTA", "GXTXAY", 3)]
        [TestCase("ABCDGH", "AEDFHR", 3)]
        [TestCase("ABC", "AB", 2)]
        [TestCase("AEBEEBCCBACA", "CEACEBEBCBAA", 9)]
        public void TestLCS_ShouldGetExpectedResult(string word1, string word2, int expected)
        {
            Assert.AreEqual(expected, Algorithms.DynamicProgramming.LongestCommonSubsequence.LCS(word1, word2));
        }
    }
}
