// this will requrire one to change the the source directory in the build system
#include "algorithms/CPlusPlus/Trees/huffmanCode/huffman.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <bitset>
#include <utility>
#include <regex>    // NOLINT (build/c++11)

using namespace std;

map<char, int> frequency;
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

void postOrder(Node * root)
{
    if(root->left != nullptr) postOrder(root->left);
    //cout << root->key << " ";
    if(root->right != nullptr) postOrder(root->right);
    if(root->left == nullptr && root->right == nullptr) cout << root->key << " ";
}

bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second < b.second;
}

bool compare(Node * a, Node * b)
{
    return a->freq < b->freq;
}

// Function to sort the map according
// to value in a (key-value) pairs
vector<pair<char, int> > sortChars(map<char, int>& M)
{
    vector<pair<char, int> > result;
    for (auto& it : M) {
        result.push_back(it);
    }
    sort(result.begin(), result.end(), cmp);
    return result;
}

void updateMap(string textLine)
{
    for(char c : textLine)
    {
        frequency[c] +=1;
    }
}

vector<pair<char, int> > getAlphabet(string alphabetSource)
{
    string text;
    ifstream MyReadFile(alphabetSource);
    while (getline (MyReadFile, text)) {
        //frequency['\n'] +=1;
        updateMap(text);
    }
    MyReadFile.close();
    vector<pair<char, int> > results = sortChars(frequency);
    return results;
}

Node * getBinary(Node * root, char key, string & binaryCode)
{
    if(root->key==key) return root;
    else
    {
        if(root->left->name.find(key) != string::npos)
        {
            //cout << "0";
            binaryCode += "0";
            return getBinary(root->left, key, binaryCode);
        }
        else
        {
            //cout << "1";
            binaryCode += "1";
            return getBinary(root->right, key, binaryCode);
        }
    }
}

string extract(Node * root, string text)
{
    Node * head = root;
    string result = "";
    for(int i=0; i<text.size(); i++)
    {
        if(text[i]=='0') head = head->left;
        else head = head->right;

        if(head->left== nullptr && head->right== nullptr)
        {
            result.push_back(head->key);
            head = root;
        }
    }
    return result;
}

string code(Node * root, string text)
{
    string result = "";

    for(int i=0; i<text.size(); i++)
    {
        string binaryCode = "";
        getBinary(root, text[i], binaryCode);
        result += binaryCode;
    }
    return result;
}

int codedBinay(string binaryText, string binaryResultFilePath)
{
    int intNumber = 0;
    ofstream binaryResultFile(binaryResultFilePath, ios::out | ios::binary);
    ofstream integersFile("results/integers.txt"); // for debugging
    int base = 0;
    int offset = 31; // should be 31
    string target = "";

    while(base+offset<binaryText.size())
    {
        target = binaryText.substr(base, offset);
        integersFile << target << endl;
        int outInteger = stoi(target, nullptr, 2);
        integersFile << outInteger << endl;
        intNumber++;
        binaryResultFile.write( (char*)&outInteger, sizeof(int));
        base += offset;
    }

    if(base != binaryText.size()-1)
    {
        target = binaryText.substr(base, binaryText.size()-base);
        integersFile << target << endl;
        int outInteger = stoi(target, 0, 2);
        integersFile << outInteger << endl;
        intNumber++;
        binaryResultFile.write( (char*)&outInteger, sizeof(int));
    }
    binaryResultFile.close();
    return intNumber;
}

void minifyFile(string filePath, string modifiedSourceFilePath)
{
    string text = "";
    string textLine = "";
    ifstream MyReadFile(filePath);
    regex r("\\s{2,}");
    while (getline(MyReadFile, textLine)) {
        text += regex_replace(textLine, r, " ");
    }
    MyReadFile.close();

    ofstream outFile(modifiedSourceFilePath);
    outFile << text;
    outFile.close();
}

Node * buildCodeTree(string alphabetSourceFilePath)
{
    vector<pair<char, int>> results = getAlphabet(alphabetSourceFilePath);
    vector<Node *> nodes;
    for(auto result : results)
    {
        Node * node = new Node(nullptr, nullptr, nullptr, result.first, result.second);
        node->name = node->key;
        nodes.push_back(node);
    }

    while(nodes.size()>1)
    {
        Node * right = nodes[0];
        Node * left = nodes[1];
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
        Node * parent = new Node(nullptr, left, right, '\0', left->freq+right->freq);
        parent->name += left->name + right->name;
        nodes.push_back(parent);
        sort(nodes.begin(), nodes.end(), compare);
    }
    return nodes[0];
}

void writeCodedText(string modifiedSourceFilePath, string textCodeFilePath, Node * root)
{
    string sourceFileLine;
    ifstream sourceFile(modifiedSourceFilePath);
    ofstream distenationFile(textCodeFilePath);

    while (getline (sourceFile, sourceFileLine)) {
        // Output the text from the file
        string textLine = sourceFileLine ; // not adding "\n" leaves only white spaces and results in one string
        string codedText = code(root, textLine);
        distenationFile << codedText;
    }
    sourceFile.close();
    distenationFile.close();
}

void extractCodedText(string textCodeFilePath, string decodedFilePath, Node * root)
{
    string textCodeFileLine;
    ifstream textCodeFile(textCodeFilePath);
    ofstream decodedFile(decodedFilePath);

    while (getline (textCodeFile, textCodeFileLine)) {
        string decodedText = extract(root, textCodeFileLine);
        decodedFile << decodedText; // this i think mostly appends no new lines
    }
    textCodeFile.close();
    decodedFile.close();
}

int codeBinaryFromText(string textCodeFilePath, string binaryResultFilePath)
{
    string sourceTextCodedFileLine;
    ifstream sourceTextCodedFile(textCodeFilePath);
    int linesNum = 0;
    while (getline(sourceTextCodedFile, sourceTextCodedFileLine)) {
        linesNum = codedBinay(sourceTextCodedFileLine, binaryResultFilePath);
    }
    sourceTextCodedFile.close();
    return linesNum;
}

void decompressBinaryFile(string binarySourceFilePath, string textDistnationFilePath,int linesNum, Node * alphabetRoot)
{
    ifstream binaryResultFile(binarySourceFilePath, ios::out | ios::binary);
    ofstream decodedbinaryFile(textDistnationFilePath);
    int codedNumber;
    string allText = "";
    for(int i=0; i<linesNum; i++)
    {
        binaryResultFile.read((char *) &codedNumber, sizeof(int));
        string str = bitset<31>(codedNumber).to_string();
        allText += str;
    }
    string decodedText = extract(alphabetRoot, allText);
    decodedbinaryFile << decodedText; // this i think mostly appends no new lines
    binaryResultFile.close();
    decodedbinaryFile.close();
}

int compresstoBinaryFile(string modifiedSourceFilePath, Node * alphabetRoot)
{
    string textCodeFilePath = "results/textCoded.txt";
    string decodedTextFilePath = "results/decodedText.txt";
    string binaryResultFilePath = "results/BinaryCoded.dat";

    writeCodedText(modifiedSourceFilePath, textCodeFilePath, alphabetRoot);
    extractCodedText(textCodeFilePath, decodedTextFilePath, alphabetRoot);
    int linesNum = codeBinaryFromText(textCodeFilePath, binaryResultFilePath);
    return linesNum;
}
