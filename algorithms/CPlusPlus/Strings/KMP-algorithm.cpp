/*
* the Knuth–Morris–Pratt string-searching algorithm (or KMP algorithm) searches for 
* occurrences of a "word" W within a main "text string" S by employing the observation
* that when a mismatch occurs, the word itself embodies sufficient information to 
* determine where the next match could begin, thus bypassing re-examination of previously 
* matched characters.(https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)
* Complexity of KMP algorithm
* Time complexity - O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(string &pat, int M, vector<int> &lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	// lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0) 
				len = lps[len - 1];
				// Note that we do not increment i here
			
			else { // if (len == 0)
				lps[i] = 0;
				i++;
			}
		}
	}
}


// Prints occurrences of txt[] in pat[]
void KMPSearch(string &pat, string &txt)
{
	int M = pat.length();
	int N = txt.length();

	// create lps[] that will hold the longest prefix suffix values for pattern
	vector<int> lps(M, 0);

	// Preprocess the pattern (calculate lps array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt
	int j = 0; // index for pat
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout<<"Found pattern at index "<<i - j<<" ";
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters, they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
	}
}

int main() {
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";

	KMPSearch(pat, txt);
	return 0;
}
