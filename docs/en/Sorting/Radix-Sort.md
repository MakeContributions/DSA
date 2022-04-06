# Radix Sort

Radix sort is a sorting algorithm that sorts the elements by first grouping the individual digits of the same place value. Then, sort the elements according to their increasing/decreasing order.

Radix Sort's time complexity is O(nd), where n is the size of the array and d is the number of digits in the largest number.

## Steps

1. Finds the largest element in the array and calculates the number of digits in it. Number of digits in the largest element are calculated as it is required to go through all the significant places of all elements.

2. Goes through each significant place one by one. 

3. Uses Counting Sort to sort the digits at each significant place. 
 
4. Repeats "Step-3" until it sorts the elements based on the digits at last place.

## Example

Given array is
```
[ 121, 432, 564, 23, 1, 45, 788 ]
```

Sorted array is
```
[ 1, 23, 45, 121, 432, 564, 788 ]
```


**FIRST PASS**

- Sorts the elements based on the unit place digits.

![image](https://user-images.githubusercontent.com/93431609/161891635-8edf89ec-2ca7-43b5-95ca-23b75f5846bb.png)

After first pass array looks like..
```
[ 121, 1, 432, 23, 564, 45, 788 ]
```

**SECOND PASS**

- Sorts the elements based on digits at tens place.

![image](https://user-images.githubusercontent.com/93431609/161892564-64b20349-4064-4125-836d-adbdfb517bbd.png)

After second pass array looks like..
```
[ 1, 121, 23, 432, 45, 564, 788 ]
```

**THIRD PASS**

- Finally, sorts the elements based on the digits at hundreds place.

![image](https://user-images.githubusercontent.com/93431609/161893373-3915ae95-28e9-4b02-bc35-5921b5280f84.png)

After third pass array looks like..
```
[ 1, 23, 45, 121, 432, 564, 788 ]
```

## Implementation

- [C](https://gist.github.com/lettergram/39da091bfe634af655d8)
- [C++](https://gist.github.com/kbendick/223ac295f6a4a9691579)
- [Java](https://gist.github.com/rishi93/287d4808820f8f8263522ebaa79b0440)
- [Python](https://gist.github.com/derka6391/d7f1bab7b3745eadb4a8ce7317a98e80)

## Video URL

[Youtube Video about Radix Sort](https://www.youtube.com/watch?v=XiuSW_mEn7g)

## Others

[Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
