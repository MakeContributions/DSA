/*  Program to find the longest common subsequence of two strings  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* longest_common_subsequence(char *string1, char *string2);

int main() 
{
    /* Example: Finding longest common subsequnce of folowing Strings
        "Hello World! Ciao Mondo! Hei Maailma!" 
        and "Bonjour Le Monde! Hei Maailma! Ciao Mondo!" */
    
    char* first_seqence = "Hello World! Ciao Mondo! Hei Maailma!";
    char* second_sequence = "Bonjour Le Monde! Hei Maailma! Ciao Mondo!";
    char* longest_subsequence = longest_common_subsequence(first_seqence, second_sequence);
    printf("%s\n", longest_subsequence);
    free(longest_subsequence);

    /* Output: "! Hei Maailma!"*/
}

/* Function which compares two character sequences and returns a pointer
to the longest common subsequence */
char* longest_common_subsequence(char *string1, char *string2)
{
    int len_of_longest = 0; //length of the currently longest common subsequence
    int index_in_current_subsequence = 0; //index for iteration throgh a common subsequence
    char *pointer_to_longest; //pointer to the longest common subsequence inside string1
    char *original_string2 = string2; //copy of string2

    //iterating through first string
    // and evaluating the length of substring starting at the current character
    while(*string1!='\0')
    {
        //iterating through string2 to check for common substring
        while(*string2!='\0')
        {
            // iterating through the common substring, to see how long it is
            while (*(string2+index_in_current_subsequence) == 
*(string1+index_in_current_subsequence))
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
