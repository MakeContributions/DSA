# バブルソート

シンキングソートとも呼ばれるバブルソートは、最もシンプルなソートアルゴリズムである。数値の順序が正しくない場合に、数値を入れ替える。最悪計算量はO(n^2)だ。

## ステップ

1. 最初の要素と次の要素を比較する。
2. 最初の要素が次の要素より大きい場合、要素を入れ替える。
3. 選択された数字が正しい位置に来るまで2.を実行し、次の要素を比較する。
4. ソートが完了するまで何度も繰り返されます。

## 例

初期配列
**5 1 4 2 8**

ソート後配列
**1 2 4 5 8**

ステップ
**1回目**

- ( **5 1** 4 2 8 ) → ( **1 5** 4 2 8 ), ここで、アルゴリズムは最初の2つの要素を比較し、5 > 1なので入れ替える。
- ( 1 **5 4** 2 8 ) → ( 1 **4 5** 2 8 ), 5 > 4なので入れ替える。
- ( 1 4 **5 2** 8 ) → ( 1 4 **2 5** 8 ), 5 > 2なので入れ替える。
- ( 1 4 2 **5 8** ) → ( 1 4 2 **5 8** ), これらの要素は順番通りのため(8 > 5)、アルゴリズムは入れ替えをしない。

**2回目**

- ( **1 4** 2 5 8 ) → ( **1 4** 2 5 8 )
- ( 1 **4 2** 5 8 ) → ( 1 **2 4** 5 8 ), 4 > 2なので入れ替える。
- ( 1 2 **4 5** 8 ) → ( 1 2 **4 5** 8 )
- ( 1 2 4 **5 8** ) → ( 1 2 4 **5 8** )

さて、配列はすでにソートされたが、アルゴリズムにはソートが完了したかわからない。アルゴリズムはソートが完了したことを知るために、入れ替えなしでさらにもう1回全体のチェックを必要とする。

**3回目**

- ( **1 2** 4 5 8 ) → ( **1 2** 4 5 8 )
- ( 1 **2 4** 5 8 ) → ( 1 **2 4** 5 8 )
- ( 1 2 **4 5** 8 ) → ( 1 2 **4 5** 8 )
- ( 1 2 4 **5 8** ) → ( 1 2 4 **5 8** )

## 実装

- [C](../../../algorithms/C/sorting/bubble-sort.c)
- [C++](../../../algorithms/CPlusPlus/Sorting/bubble-sort.cpp)
- [CSharp](../../../algorithms/CSharp/src/Sorts/bubble-sort.cs)
- [Go](../../../algorithms/Go/sorting/bubble-sort.go)
- [Java](../../../algorithms/Java/sorting/bubble-sort.java)
- [JavaScript](../../../algorithms/JavaScript/src/sorting/bubble-sort.js)
- [Python](../../../algorithms/Python/sorting/bubble_sort.py)

## 動画のURL

[Youtube Video about Bubble Sort](https://www.youtube.com/watch?v=Jdtq5uKz-w4&ab_channel=mycodeschool)

## その他

[Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)
