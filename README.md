
This is for Q1

| Data Structure | Search | Ins | Del | Min | Max | Pred | Succ |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Unsorted Array** | `O(n)` | `O(1)` | `O(1)` | `O(n)` | `O(n)` | `O(n)` | `O(n)` |
| **Sorted Array** | `O(log n)` | `O(n)` | `O(n)` | `O(1)` | `O(1)` | `O(1)` | `O(1)` |
| **Singly Unsorted** | `O(n)` | `O(1)` | `O(n)` | `O(n)` | `O(n)` | `O(n)` | `O(n)` |
| **Singly Sorted** | `O(n)` | `O(n)` | `O(n)` | `O(1)` | `O(1)` | `O(n)` | `O(1)` |
| **Doubly Unsorted** | `O(n)` | `O(1)` | `O(1)` | `O(n)` | `O(n)` | `O(n)` | `O(n)` |
| **Doubly Sorted** | `O(n)` | `O(n)` | `O(1)` | `O(1)` | `O(1)` | `O(1)` | `O(1)` |





This is for Q2

The standard 2-way merge sort divides the array into two halves, yielding the recurrence relation T(n) = 2T(n/2) + O(n).

For the modified 3-way merge sort, the array is divided into three equal (or nearly equal) parts.

Divide Step: Finding the two midpoints to split the array into three thirds takes constant time, O(1).

Conquer Step: The algorithm recursively calls itself 3 times on subarrays of size n/3, which takes 3T(n/3) time.

Merge Step: To merge 3 sorted arrays of size n/3, we compare the elements at the top of the three subarrays. Finding the minimum among 3 elements takes at most 2 comparisons. Since we must do this for all n elements to assemble the final array, the merge step takes at most 2n comparisons, bounding it to O(n) time.

This gives us the recurrence relation for the modified merge sort:T(n) = 3T\left(\frac{n}{3}\right) + O(n)

We can solve this using the Master Theorem:Given T(n) = aT(n/b) + f(n), we identify a = 3, b = 3, and f(n) = O(n).

Calculate n^{\log_b a}:n^{\log_3 3} = n^1 = n.

Compare f(n) with n^{\log_b a}: Since f(n) = O(n), it perfectly matches O(n^{\log_b a}).

This falls directly under Case 2 of the Master Theorem.Therefore, the worst-case running time is:

                              T(n) = O(n^{\log_3 3} \log n) = O(n \log_3 n)

Because logarithmic bases are constant factors of one another (i.e., \log_3 n = \frac{\log_2 n}{\log_2 3}), we drop the base in asymptotic notation. 

The final worst-case running time of the modified merge sort is O(nlog n).
