/*
A trie (pronounced as "try") or prefix tree is a tree data structure
used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure,
such as autocomplete and spellchecker.

Insertion:
Average Case: O(N)
Worst Case: O(N)
Best Case: O(N)

Deletion:
Average Case: O(N)
Worst Case: O(N)
Best Case: O(N)

Searching:
Average Case: O(N)
Worst Case: O(N)
Best Case: O(1)

Space complexity: O(alphabet_size * average key length * N)
*/

/*
Create a node that will have two properties —
one is the hash map for storing children.
the other one is for keeping track of the end of the word.
*/

class Node {
  constructor() {
    this.children = {};
    this.isEndWord = false;
  }
}

class Trie {
  constructor() {
    this.root = new Node();
  }
  insert(word) {
    let node = this.root;
    for (const char of word) {
      if (!node.children[char]) {
        node.children[char] = new Node();
      }
      node = node.children[char];
    }
    node.isEndWord = true;
  }
  search(word) {
    let node = this.root;
    for (const char of word) {
      if (!node.children[char]) {
        return false;
      }
      node = node.children[char];
    }
    return node.isEndWord ? true : false;
  }
  startsWith(prefix) {
    let node = this.root;
    for (const char of prefix) {
      if (!node.children[char]) {
        return false;
      }
      node = node.children[char];
    }
    return true;
  }
}

const trie = new Trie();
trie.insert('datastructures');
trie.insert('datablock');
console.log(trie.search('dsa')); // false
console.log(trie.search('datablock')); // true
console.log(trie.startsWith('data')); // true
