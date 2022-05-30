#ifndef ALGORITHMS_CPLUSPLUS_TREES_HUFFMANCODE_HUFFMAN_H_
#define ALGORITHMS_CPLUSPLUS_TREES_HUFFMANCODE_HUFFMAN_H_

#include <string>

using namespace std;

class Node{
public:
    Node * parent;
    Node * left;
    Node * right;
    char key;
    int freq;
    string name;
    Node(Node * p, Node * l, Node * r, int k, int f)
    {
        parent = p;
        left = l;
        right = r;
        key = k;
        freq = f;
    }
};

// reduces file size
void minifyFile(string filePath, string modifiedSourceFilePath);

// tree of ascii chars, used as the codes references
Node * buildCodeTree(string alphabetSourceFilePath);

// linesNum tells how many binary lines to be converted
int compresstoBinaryFile(string modifiedSourceFilePath, Node * alphabetRoot);

// decompresses the binary file into text file
void decompressBinaryFile(string binarySourceFilePath, string textDistnationFilePath,int linesNum, Node * alphabetRoot);

#endif // ALGORITHMS_CPLUSPLUS_TREES_HUFFMANCODE_HUFFMAN_H_
