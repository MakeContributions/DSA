
def edit_distance(w1, w2):
    """
    Find edit distance (minimum number of changes) required to convert string w1 to string w2. 
    """

    m = [[0 if x != 0 else y if y != 0 else x for x in range(len(w2) + 1)] for y in range(len(w1) + 1)]

    for i in range(1,len(w1) + 1):
        m[i][0] = i 
    for j in range(1, len(w2) + 1):
        m[0][j] = j 
    
    for i in range(1, len(w1) + 1):
        for j in range(1, len(w2) + 1):
            m[i][j] = min(
                m[i-1][j-1] + int(w1[i-1] != w2[j-1]),
                m[i-1][j] + 1,
                m[i][j-1] + 1
            )
    
    return m


if __name__ == "__main__":
    print(edit_distance("sitting", "kitten"))

