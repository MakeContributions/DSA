# Linear Search

**linear search**, also known as **Sequential search** is a method for finding an element within a list. A linear search sequentially checks each element of the list until it finds an element that matches the target value. If the algorithm reaches the end of the list, the search terminates unsuccessfully.
1. Time Complexity: O(n)
2. Space Complexity: O(1)
3. Applications: practical when the list has only a few elements when performing a single search in an unordered list.
4. Founder's Name: Anatole Beck and Donald J. Newman (1970)
Linear search is usually very **simple to implement**.

## Steps/Algorithm: 
**Linear Search( Array A, Value x)**

Step 1: Set i to 1  

Step 2: if i > n then go to step 7  

Step 3: if A[i] = x then go to step 6  

Step 4: Set i to i + 1  

Step 5: Go to Step 2  

Step 6: Print Element x Found at index i and go to step 8  

Step 7: Print element not found  

Step 8: Exit

## Pseudocode

**procedure linear_search (list, value)**
```
start procedure
   for each item in the list
      if match item == value
         return the item's location
      end if
   end for
end procedure
```

## Example
Input A[]: **10,20,30,40,50,60,70,80**

Element to search: **50**

Procedure:
Step 1: i = 0
Step 2: Comparing A[i] and Element to search, if equal numbers return i, else i = i + 1.
        **comparing 10 and 50 ->False**, i = i + 1
Step 3: **comparing 20 and 50 ->False**, i = i + 1
Step 4: **comparing 30 and 50 ->False**, i = i + 1
Step 5: **comparing 40 and 50 ->False**, i = i + 1
Step 6: **comparing 50 and 50 ->True -> Element Found**

Output: i

## Implementation

- [C](https://github.com/MakeContributions/DSA/blob/main/algorithms/C/searching/linearsearch.c)
- [C++](https://github.com/MakeContributions/DSA/blob/main/algorithms/CPlusPlus/Searching/linear-search.cpp)
- [CSharp](https://github.com/MakeContributions/DSA/blob/main/algorithms/CSharp/src/Search/linear-search.cs)
- [Go](https://github.com/MakeContributions/DSA/blob/main/algorithms/Go/searching/linear-search.go)
- [Java](https://github.com/MakeContributions/DSA/blob/main/algorithms/Java/searching/linear-search.java)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/linear-search.js)
- [Python](https://github.com/MakeContributions/DSA/blob/main/algorithms/Python/searching/linear_search.py)

## Video URL

[Watch Linear Search Implementation](https://www.youtube.com/watch?v=4GPdGsB3OSc)

