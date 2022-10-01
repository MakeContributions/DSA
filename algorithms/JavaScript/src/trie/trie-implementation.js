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
trie.insert('datastructures')
trie.insert('datablock')
console.log(trie.search('dsa')) //false
console.log(trie.search('datablock')) //true
console.log(trie.startsWith('data')) //true