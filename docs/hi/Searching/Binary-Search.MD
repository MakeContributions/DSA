# Binary Search

**Binary search**, also known as half-interval **search**, logarithmic **search**, or **binary** chop, is a **search** algorithm that finds the position of a target value within a sorted array. **Binary search** compares the target value to the middle element of the array.

1. Time Complexity: O(log n) 
2. Space Complexity: O(1)
3. Applications: Best when data is sorted and large
4. Founder's Name: P.F. Windley, A.D. Booth, A.J.T. Colin, and T.N. Hibbard
5. It is one of the popular and daily using Searching Algorithm

## Steps

1. सरणी का मध्य तत्व ढूंढें
2. जांचें कि क्या कुंजी मध्य तत्व के बराबर है यदि हां तो इंडेक्स वापस करें और प्रोग्राम से बाहर निकलें
3. यदि चरण 2 नहीं चलता है, तो परीक्षण करें कि क्या तत्व मध्य तत्व से कम है, यदि हां, तो प्रारंभ से मध्य-1 सूचकांक के बीच चरण 1 चलाएँ।
4. यदि तीसरा चरण नहीं चलता है, तो परीक्षण करें कि क्या तत्व मध्य तत्व से अधिक है, यदि हां, तो मध्य + 1 से अंतिम सूचकांक के बीच चरण 1 चलाएं।
5. लूप को तब तक चलाएँ जब तक आरंभिक इंडेक्स अंतिम इंडेक्स से कम न हो जाए
6. यदि लूप खत्म हो गया है और डेटा नहीं मिला है तो -1 लौटाएं, इसका मतलब है कि डेटा मौजूद नहीं है
> **ध्यान दें:** सरणी को आरोही से अवरोही क्रम में क्रमबद्ध किया जाना चाहिए

## Example

इनपुट: **10,20,30,40,50**

खोजने के लिए तत्व: **20**

प्रक्रिया:

मध्य तत्व:**30** और तत्व 30 से कम है इसलिए प्रारंभ से मध्य -1 सूचकांक के बीच खोजें

मध्य तत्व: **20** और हाँ मध्य तत्व खोजने की कुंजी है इसलिए सूचकांक =**1** लौटाएँ

आउटपुट: **1**

## Implementation

- [C](https://github.com/MakeContributions/DSA/blob/main/algorithms/C/searching/Binary-search.c)
- [C++](https://github.com/MakeContributions/DSA/blob/main/algorithms/CPlusPlus/Searching/binary-search.cpp)
- [CSharp](https://github.com/MakeContributions/DSA/blob/main/algorithms/CSharp/src/Search/binary-search.cs)
- [Go](https://github.com/MakeContributions/DSA/blob/main/algorithms/Go/searching/binary-search.go)
- [Java](https://github.com/MakeContributions/DSA/blob/main/algorithms/Java/searching/binary-search.java)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search.js)
- [JavaScript](https://github.com/MakeContributions/DSA/blob/main/algorithms/JavaScript/src/searching/binary-search-recursive.js)
- [Python](https://github.com/MakeContributions/DSA/blob/main/algorithms/Python/searching/binary_search.py)

## Video URL

[Watch Binary Search Implementation](https://youtu.be/P3YID7liBug)

## Others

Solve Problem Related to Binary Search 

[Click Me](https://leetcode.com/tag/binary-search/)
