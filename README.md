# COMP319 / 알고리즘 / 2020 / 1학기 / 장길진

---

### HW # 1

[min_max_avg.c](min_max_avg.c)

숫자들로 이루어진 입력 파일을 읽어서 숫자를 저장하고

최대값, 최소값, 평균을 출력하는 프로그램을 작성한다.

---

### HW # 2

정수입력 및 문자열에 대한 정렬 알고리즘 구현하기


>   [template_sort_chararray.c](template_sort_chararray_simple.c)
[template_sort_int_simple.c](template_sort_int_simple.c)
[template_sort_string_simple.c](template_sort_string_simple.c)

---

### HW # 3


>   Heap sort using MaxHeapify - array 를 max heap 구조로 바꾸는 함수를 구현한다.
>   [hw3_1.c](hw3_1.c)


>    Heap sort using MinHeapify (min heap 을 이용하여 오름차순 정렬을 구현한다.)
   [hw3_2.c](hw3_2.c)

>   Heap for finding median and sort (Median 을 찾기 위한 Heap 구현 및 이를 이용한 sort)
Median value 를 쉽게 찾기 위해서 다음과 같은 heap 구조를 구현하고 이를 이용하여 오름차순
정렬을 하는 코드를 작성한다.
   [hw3_3.c](hw3_3.c)

---

### HW # 4

>목적: 단어의 출현회수 세기. 공백으로 분할된 단어(word)들이 전체 파일에서 몇 번 있는지 수를 세고, 
출현회수의 내림차순으로(큰 것에서 작은 것으로) 단어-출현회수를 저장한다. 
입력: 텍스트 파일 
출력: 텍스트 파일, 단어와 출현회수만 출력 

[count_words.c](countwords.c)

---

### HW # 5

>제한된 경로의 길이로 최대한 많은 점 방문하기(forward travelling salesperson)
비행기를 타고 도시를 방문하는 판매원이 있다. 연료의 양에 제한이 있고 시작점과 끝점이 주어졌을 때, 
가장 많은 수의 도시를 방문하는 경로는? 단, 2 차원 평면에서 x 축으로는 전진만이 가능하다
[fts.c](fts.c)

>Longest common subsequence (LCS)
text 입력에 대하여 LCS 를 구하는 C 프로그램을 작성한다. 찾은 LCS 와 dynamic programming table 이
채워지는 과정을 보인다
[lcs.c](lcs.c)

>Shortest water slit path
A box is partitioned by plates with slits (very thin gaps), and they are equally distant from each other vertically. Suppose water is poured from the center of the top, and the water will flow down through  the slits, to the base. Design an algorithm that finds the minimum distance that water travels, and the slit numbers on the minimum path. See the following figure for details.
[sws.c](sws.c)