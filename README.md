sort
====

Implementation of sorting algorithms using C

Quicksort
---------
Quicksort on average, makes O(n log n) comparisons to sort _n_ items. In the worst case, it makes O(n²) comparisons.

This implementation of Quicksort is a Cormen's approach which can be found on his book Introduction to Algorithms.

The program takes two command line arguments. The first one tells the program how many elements it should sort. The second one is optional and tells the program if it should display the ordered array or not.

This will tell the program to sort 100 elements and show the ouput:

    ./a.out 100 -p
    
This will tell the program to sort 1000000 elements and ignore the output:

    ./a.out 1000000
