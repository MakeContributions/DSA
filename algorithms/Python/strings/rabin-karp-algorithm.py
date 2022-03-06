'''
String pattern matching algorithm which performs efficiently for large text and patterns

Algorithm: 
Rabin Karp works on the concept of hashing. If the substring of the given text 
is same as the pattern then the corresponding hash value should also be same. Exploiting this idea 
and designing a hash function which can be computed in O(m) time for both pattern and initial window 
of text. The subsequent  window each will require only O(1) time. And we slide the window n-m times 
after the initial window. Therefore the overall complexity of calculating hash function for text is O(n-m+1)
Once the hash value matches, the underlying string is again checked with pattern for matching


Complexity:
    Best case:  O(n-m+1)
    Worst case: O(nm)


'''

def rabin_karp(T: str, P: str, q: int ,d: int = 256) -> None :
    '''
    Parameters:
    
            T: string
               The string where the pattern needs to be searched

            P: string 
               The pattern to be searched

            q: int
               An appropriately chosen prime number based on length of input strings
               The higher the prime number, the lower the collisions and spurious hits
               
            d: int, default value 256
               Denotes the no of unique character that is used for encoding
    
    

    
    
    
    Example:
    
    >>> pos = rabin_karp("AAEXCRTDDEAAFT","AA",101)
    Pattern found at pos: 0
    Pattern found at pos: 10
    
    '''
    
    n = len(T)   # length of text
    m = len(P)   # length of pattern
    p=0          # Hash value of pattern
    t=0          # Hash value of text
    
    #Computing h: (h=d^m-1 mod q)
    h=1
    for i in range(1,m):
        h = (h*d)%q
    
    #Computing hash value of pattern and initial window (of size m) of text
    for j in range(m):
        p = (d*p + ord(P[j])) % q
        t = (d*t + ord(T[j])) % q
    
    
    found = False
    pos=[] # To store positions
    
    #Sliding window and matching
    for s in range(n-m+1):
        if p==t: # if hash value matches
            if P == T[s:s+m]: # check for string match
                pos.append(s)
                if not found:
                    found = True
    
        if s<n-m:
            t = (d*(t-ord(T[s])*h) + ord(T[s+m])) % q # updating hash value of t for next window
            if t<0:
                t = t+q # To make sure t is positive integer
    
    if not found: # If pattern not found in text
        pos.append(-1)
        
    #Printing results
    if pos[0]==-1:
        print("Pattern not found")
    else:
        for i in pos:
            print(f"Pattern found at pos: {i}")



if __name__ == "__main__":
    T = "AAEXCRTDDEAAFT"
    P = "AA"

    rabin_karp(T,P,101)
