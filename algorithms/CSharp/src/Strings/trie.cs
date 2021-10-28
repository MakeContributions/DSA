using System;
using System.Collections.Generic;

namespace Algorithms.Strings
{
    public class Trie
    {
        const int ASCII_QUANTITY = 256;

        private class TrieNode
        {
            public bool end;
            public TrieNode[] next;

            public TrieNode()
            {
                end = false;
                next = new TrieNode[ASCII_QUANTITY];
            }
        }

        private TrieNode _root;

        public Trie()
        {
            _root = new TrieNode();
        }

        public void InsertWord(string word)
        {
            TrieNode current = _root;
            for(int i = 0; i < word.Length; i++)
            {
                int id = word[i];
                if(current.next[id] == null)
                {
                    current.next[id] = new TrieNode();
                }

                current = current.next[id];
            }

            current.end = true;
        }

        public bool SearchWord(string word)
        {
            TrieNode current = _root;
            for(int i = 0; i < word.Length; i++)
            {
                int id = word[i];
                if(current.next[id] == null)
                {
                    return false;
                }

                current = current.next[id];
            }

            return current.end;
        }
    }

    public class TrieTester
    { 
        public static List<bool> TestTrie(List<Tuple<string, string>> operations)
        {
            List<bool> answer = new List<bool>();
            Trie dictionary = new Trie();

            foreach(var op in operations)
            {
                if(op.Item1 == "insert")
                {
                    dictionary.InsertWord(op.Item2);
                }
                else if(op.Item1 == "search")
                {
                    answer.Add(dictionary.SearchWord(op.Item2));
                }
            }

            return answer;
        }

        public static void Main()
        {
            List<Tuple<string, string>> operations = new List<Tuple<string, string>>()
            {
                new Tuple<string, string>("insert", "allure"),
                new Tuple<string, string>("search", "allure"),
                new Tuple<string, string>("search", "cow"),
                new Tuple<string, string>("search", "all"),
                new Tuple<string, string>("insert", "all"),
                new Tuple<string, string>("search", "all")
            };

            List<bool> results = TestTrie(operations);
            Console.WriteLine(string.Join(", ", results));
        }
    }

}

/*
 * Trie is an efficient data-structure to store words. This can be used for solving multiple problems, even in number
 * theory!!
 * Here's how it works,
 * We keep a root node. Each path from root to a leaf is a word. Even a word can end in the middle of the path.
 * For example, "allure" and "all". "all" is in "allure", so we will not need to insert it.
 * The path defines a letter in the node from one node to another. In that case we can consider the root to be empty string.
 * Each node in this implementation contains an array of size 256, for the ASCII codes and a boolean to mark end.
 * From the root, it checks whether the current letter exists.
 * If yes then it will just move to that path. Else it will create a new node and move.
 * When inserting the first word, let "allure", new nodes will be created. the node for the last letter will be marked as end.
 * When inserting "all", "all" already exists as prefix of "allure", so we will just mark the end variable of second 'l' as true.
 * Search is like this too. We start from the root and the first character of the word. If a character is found, we move forward else return false.
 * Time complexity of Search is O(length). The insert operation takes O(length) time.
 */