#include <iostream>
#include <string>
#include <chrono>  // NOLINT [build/c++11]

using namespace std;

char* mystrtok(char* s, char d)
{
    // Stores the state of string
    static char* input = NULL;

    // Initialize the input string
    if (s != NULL)
        input = s;

    // Case for final token
    if (input == NULL)
        return NULL;

    // Stores the extracted string
    char* result = new char[strlen(input) + 1];
    int i = 0;

    // Start extracting string and
    // store it in array
    for (; input[i] != '\0'; i++) {
        // If delimiter is not reached
        // then add the current character
        // to result[i]
        if (input[i] != d)
            result[i] = input[i];

        // Else store the string formed
        else {
            result[i] = '\0';
            input = input + i + 1;	// +1 for adding the delimiter
            return result;
        }
    }

    // Case when loop ends
	// add '\0' to the last token and return.
    result[i] = '\0';
    input = NULL;

    // Return the resultant pointer
    // to the string
    return result;
}

// Driver Code
int main()
{
    // Given string str
	cout<<"Enter the string.\n";
	string inputString;
	char delimiter;
	getline(cin, inputString);
	cout<<"Enter the delimiter token character.\n";
	cin>>delimiter;
	int n=inputString.length();
	char str[n+1];
	strcpy(str, inputString.c_str());

    // Tokenize the first string
	cout<<"The tokenized string is...\n";
    char* ptr = mystrtok(str, delimiter);

    // Print current tokenized string
    cout << ptr << endl;

    // While ptr is not NULL
    while (ptr != NULL) {
        // Tokenize the string
        ptr = mystrtok(NULL, delimiter);

		if(ptr)
        	// Print the string
        	cout << ptr << endl;
    }
    return 0;
}
