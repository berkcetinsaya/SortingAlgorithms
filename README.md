# Sorting Algorithms

<div style="text-align: justify"> 

&nbsp;&nbsp;&nbsp;&nbsp;
Analysis of Algorithms is the area of computer science that provides tools to analyze the efficiency of different methods of solutions.

&nbsp;&nbsp;&nbsp;&nbsp;
It recognizes limitations of various algorithms for solving a problem, to understand relationship between problem size and running time, to learn how to analyze an algorithm's running time without coding it, to learn techniques for writing more efficient code and to recognize bottlenecks in code as well as which parts of code are easiest to optimize.

&nbsp;&nbsp;&nbsp;&nbsp;
This README file divided into three part. In the first part, I am going to explain all codes and complexities of the sorting algorithms such as the best, worst and average cases. Secondly, I will show you a table which contains the average execution times with maximum and minimum times. In the last part, I will leave some comments about efficiency of the sorting algorithms.

> #### The algorithms used in this project:
>
> - Bubble sort
> - Selection sort
> - Insertion sort
> - Quick sort ̰
> - Heap sort
> - Merge sort

### **Bubble sort**

&nbsp;&nbsp;&nbsp;&nbsp;
First of all, I would like to start with the bubble sort and explain my code. For example, we have an array that includes five numbers “4 2 5 8 6“. Now, there are two for loops and one if statement. If statement checks that an index of the array is greater than the following index. If it is, they swap their positions and continue to next.


```cpp
void bubble(){
    for (int x = 0; x < n; x++){
        for (int y = 0; y<n - 1; y++){
            if (B[y]>B[y + 1]){
                tempBforBub = B[y + 1];
                B[y + 1] = B[y];
                B[y] = tempBforBub;
            }
        }
    }
}
```

( **4** **2** 5 8 6 ) → ( **2** **4** 5 8 6 ) Swap since 4 > 2.
<br>( 2 **4** **5** 8 6 ) → ( 2 **4** **5** 8 6 ) They are same there is no swap.
<br>( 2 4 **5** **8** 6 ) → ( 2 4 **5** **8** 6 ) They are same there is no swap.
<br>( 2 4 5 **8** **6** ) → ( 2 4 5 **6** **8** ) Swap since 8 > 6.

It is sorted now, but the algorithm does not know; therefore, the code runs until it finishes.

### **Selection sort**

The other sorting algorithm is selection sort. For instance, we have an array which has 5 numbers and they are “7 5 9 3 6”. Now, we assume that our first element is the minimum element of that array. Then, we start to check if it is really the minimum element? ( **7** 5 9 3 6 ) → 7 is the minimum for the first run. When it runs, check the 7 and 5. Now, program understand 7 is not the minimum element. It should be 5. Then, it assigns 5 as the minimum element. After checking all array elements, it decides 3 is the minimum and put 3 to the beginning of the array and 7 goes to 3's old place. All processes are working like that;

```cpp
void selection(){
    for (int x = 0; x < n; x++){
        int index_of_min = x;
        for (int y = x; y<n; y++){
            if (S[index_of_min]>S[y]){
                index_of_min = y;
            }
        }
        tempBforSel = S[x];
        S[x] = S[index_of_min];
        S[index_of_min] = tempBforSel;
    }
}
```

( **7** 5 9 **3** 6 ) swap 7 - 3 
<br>( 3 ***5*** 9 7 6 ) no swap
<br>( 3 5 **9** 7 **6** ) swap 9 - 6 
<br>( 3 5 6 ***7*** 9 ) no swap
<br>( 3 5 6 7 ***9*** ) no swap

### **Insertion sort**

Another sorting algorithm is insertion sort. Insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain. If an example should be given, we have an array with 8 elements.

```cpp
void insertion(){
    int j;
    for (int i = 0; i < n; i++){
        j = i;
        while (j > 0 && I[j] < I[j - 1]){
            tempBforIns = I[j];
            I[j] = I[j - 1];
            I[j - 1] = tempBforIns;
            j--;
        }
    }
}
```

<u>2</u> 6 3 8 4 1 5 0
<br>**2** <u>6</u> 3 8 4 1 5 0 
<br>2 **6** <u>3</u> 8 4 1 5 0 
<br>2 3 **6** <u>8</u> 4 1 5 0 
<br>2 3 6 **8** <u>4</u> 1 5 0
<br>2 3 **4** 6 8 <u>1</u> 5 0
<br>**1** 2 3 4 6 8 <u>5</u> 0
<br>1 2 3 4 **5** 6 8 <u>0</u>
<br>**0** 1 2 3 4 5 6 8








</div>




there is a command line video [link][1].

[1]: https://asciinema.org/a/87259 "Terminal Video"
[bubble_sort]: img/bubble_sort.png "Bubble sort"

## Usage

~~~~~ 
$ g++ source.cpp -o sorting.out
~~~~~ 

~~~~~ 
$ ./sorting.out
~~~~~
