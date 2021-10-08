/*  Program to find the longest common subsequence of two strings.
Example: longest common subsequence of "abcde" and "abzyxcde" is "cde".

Worst case time complexety: O(n*m^2), where n is the length of the first string,
                            and m is the length of the second string.
                            Example strings for worst case time: "aaaaa" and "aaaaa"
                            Explanation: for each character in the first string, you 
                            iterate through the second string. For each character of
                            the second string, you iterate through the common sequence
                            that starts at that character. In the worst case,
                            for each character in the second string, you iterate through
                            the remaining second string. That's why the algorithm is O(n*m^2) */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* longest_common_subsequence(char *string1, char *string2);

int main() 
{
    /* Example: Finding longest common subsequence of following Strings
        "Hello World! Ciao Mondo! Hei Maailma!" 
        and "Bonjour Le Monde! Hei Maailma! Ciao Mondo!" */
    
    char* first_seqence1 = "Hello World! Ciao Mondo! Hei Maailma!";
    char* second_sequence1 = "Bonjour Le Monde! Hei Maailma! Ciao Mondo!";
    char* longest_subsequence1 = longest_common_subsequence(first_seqence1, second_sequence1);
    printf("%s\n", longest_subsequence1);
    free(longest_subsequence1);

    /* Output: "! Hei Maailma!"*/

    /* Example: Finding longest common subsequence of following Strings
        "abcde"
        and "abzyxcde" */

    char* first_seqence2 = "abcde";
    char* second_sequence2 = "abzyxcde";
    char* longest_subsequence2 = longest_common_subsequence(first_seqence2, second_sequence2);
    printf("%s\n", longest_subsequence2);
    free(longest_subsequence2);

    /* Output: "cde"*/

    /* Example: Finding longest common subsequence of following Strings
        "aaaaaa"
        and "aaa" */

    char* first_seqence3 = "aaaaaa";
    char* second_sequence3 = "aaa";
    char* longest_subsequence3 = longest_common_subsequence(first_seqence3, second_sequence3);
    printf("%s\n", longest_subsequence3);
    free(longest_subsequence3);

    /* Output: "aaa"*/

}

/* Function which compares two character sequences and returns a pointer
to the longest common subsequence */
char* longest_common_subsequence(char *string1, char *string2)
{
    int len_of_longest = 0; //length of the currently longest common subsequence
    int index_in_current_subsequence = 0; //index for iteration through a common subsequence
    char *pointer_to_longest; //pointer to the longest common subsequence inside string1
    char *original_string2 = string2; //copy of string2

    //iterating through first string
    // and evaluating the length of substring starting at the current character
    while(*string1!='\0')
    {
        //iterating through string2 to check for common substring
        while(*string2!='\0')
        {
            /* iterating through the common substring, to see how long it is. 
	    Checking each character, if the subsequence doesn't match any longer,
            of if one of the strings has ended */
            while (*(string2+index_in_current_subsequence) == 
*(string1+index_in_current_subsequence) && *(string2+index_in_current_subsequence) != '\0' &&
*(string2+index_in_current_subsequence) != '\0')
            {
                index_in_current_subsequence++;
            }

            //saving the substring, if it's longer the the previously longest substring
            if (index_in_current_subsequence>len_of_longest) 
            {
                len_of_longest=index_in_current_subsequence;
                pointer_to_longest=string1;
            }
            index_in_current_subsequence = 0;
            string2++;
        }
        string2 = original_string2; //returning to the begin of string2
        string1++;
    }

    //copying the subsequence from string2 into memory (heap)
    char *subsequence = (char*) malloc((len_of_longest+1)*sizeof(char));
    strncpy(subsequence, pointer_to_longest, len_of_longest);
    
    //Setting the terminating character at the end
    *(subsequence+len_of_longest)='\0';
    return subsequence;
}
