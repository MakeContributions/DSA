# Linear Search

**linear search**, also known as **Sequential search** is a method for finding an element within a list. A linear search sequentially checks each element of the list until it finds an element that matches the target value. If the algorithm reaches the end of the list, the search terminates unsuccessfully.
1. Time Complexity: O(n)
2. Space Complexity: O(1)
3. Applications: practical when the list has only a few elements when performing a single search in an unordered list.
4. Founder's Name: Anatole Beck and Donald J. Newman (1970)
Linear search is usually very **simple to implement**.

## चरण/एल्गोरिदम:
**रैखिक खोज (सरणी ए, मान x)**

चरण 1: मुझे 1 पर सेट करना है

चरण 2: यदि मैं > एन है तो चरण 7 पर ध्यान दें

चरण 3: यदि A[i] = x है तो चरण 6 पर

चरण 4: i को i + 1 पर सेट करें

चरण 5: चरण 2 पर

चरण 6: एलेमेंट एक्स फ़ाउंडेशन प्रिंट करें और चरण 8 पर जाएं

चरण 7: प्रिंट तत्व नहीं मिला

चरण 8: बाहर निकलें

## स्यूडोकोड

**प्रक्रिया रैखिक_खोज (सूची, मान)**
```
प्रारंभ प्रक्रिया
    सूची में प्रत्येक आइटम के लिए
       यदि आइटम से मेल खाता है == मान
          आइटम का स्थान लौटाएँ
       अगर अंत
    के लिए समाप्त
अंतिम प्रक्रिया
```

## उदाहरण
इनपुट ए[]: **10,20,30,40,50,60,70,80**

खोजने के लिए तत्व: **50**

प्रक्रिया:
चरण 1: मैं = 0
चरण 2: खोजने के लिए A[i] और तत्व की तुलना करें, यदि समान संख्याएँ i लौटाती हैं, अन्यथा i = i + 1।
         **10 और 50 की तुलना ->गलत**, i = i + 1
चरण 3: **20 और 50 की तुलना ->गलत**, i = i + 1
चरण 4: **30 और 50 की तुलना ->गलत**, i = i + 1
चरण 5: **40 और 50 की तुलना ->गलत**, i = i + 1
चरण 6: **50 और 50 की तुलना ->सही ->तत्व मिला**

आउटपुट: मैं

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

