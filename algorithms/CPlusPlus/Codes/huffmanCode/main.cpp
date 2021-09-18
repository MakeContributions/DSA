#include "./huffman.h"


int main() {

    // example
    string sourceFilePath = "results/data-sample.txt";

    string modifiedSourceFilePath = "results/modifiedSource.txt";

    string binaryResultFilePath = "results/BinaryCoded.dat"; // the compressed file
    string binaryDecodedFilePath = "results/decodedBinary.txt"; // after decompression

    // reduces file size
    minifyFile(sourceFilePath, modifiedSourceFilePath);

    // tree of ascii chars, used as the codes references
    Node * alphabetRoot = buildCodeTree(modifiedSourceFilePath);

    // linesNum tells how many binary lines to be converted
    int linesNum = compresstoBinaryFile(modifiedSourceFilePath, alphabetRoot);

    // decompresses the binary file into text file
    decompressBinaryFile(binaryResultFilePath, binaryDecodedFilePath, linesNum, alphabetRoot);

    return 0;
}
