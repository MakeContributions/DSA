using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace Algorithms.Tests.Strings
{
    public class Trie
    {
        static object[] TestCasesForTrie =
{
            new object[] 
            {
                new List<Tuple<string, string>>()
                {
                    new Tuple<string, string>("insert", "allure"),
                    new Tuple<string, string>("search", "allure"),
                    new Tuple<string, string>("search", "cow"),
                    new Tuple<string, string>("search", "all"),
                    new Tuple<string, string>("insert", "all"),
                    new Tuple<string, string>("search", "all")
                },
                new List<bool>() { true, false, false, true}
            },
        };

        [TestCaseSource(nameof(TestCasesForTrie))]
        public void TestTrie_ShouldGetExpectedResult(List<Tuple<string, string>> operations, List<bool> expected)
        {
            List<bool> result = Algorithms.Strings.TrieTester.TestTrie(operations);
            Assert.AreEqual(expected, result);
        }
    }
}
