## top k words
Hashing is used in this solution. The words are readed from a file and the hash table is constructed at same time. The complexity of this part is O(M), where M is words' quantity. The complexity of sort part to find the top-k is O(nlog(k)). The total is (M+nlog(k)).

## sparse matrix multiplication
The multiplication of two n×n matrices is one of the most basic algebraic problems and considerable effort was devoted to obtaining efficient algorithms for the task. The naive matrix multiplication algorithm performs O(n^3) operations. Strassen was the first to show that the naive algorithm is not optimal, giving an O(n^2.81) algorithm for the problem. Many improvements then followed. The currently fastest matrix multiplication algorithm, with a complexity of O(n^2.38 ), was obtained by Coppersmith and Winograd.

Considering that there are 5% elements are nonzero, so the algorithmic complexity of sparse matrix multiplication is O(max(m,n,k) + 0.05 * max(m*n,n*k) ).

After reading the question, it is obvious the data in matrix is float point, so I use float as the data precision, it is easy to change the data precision to double type.


the running times of the two schemes (my code and the traditional one) when m = n = k = 1000 for the same generated matrices A and B is
traditional matrix multiplication scheme use time 5.476 s
sparse matrix multiplication scheme use time      1.701 s
