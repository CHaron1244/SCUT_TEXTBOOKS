//Insertion Sort （Stable） 
template <class Elem>
void inssort(Elem A[], int n) {
  for (int i=1; i<n; i++)
    for (int j=i; (j>0) &&
         (A[j]< A[j-1])); j--)
      swap(A, j, j-1);
}
//Best Case:       0 swaps, n - 1 comparisons           Q(n)
//Worst Case:    n(n-1)/2 swaps and comparisons  Q(n2)
//Average Case: n (n-1)/4 swaps and comparisons  Q(n2)

//Bubble Sort （Stable） 
template <class Elem>
void bubsort(Elem A[], int n) {
  for (int i=0; i<n-1; i++)
    for (int j=n-1; j>i; j--)
      if (A[j]< A[j-1])
        swap(A, j, j-1);
}
//Best Case:     0 swaps, n(n-1)/2 comparisons          Q(n2)
//Worst Case:   n(n-1)/2 swaps and comparisons       Q(n2)
//Average Case: n(n-1) /4 swaps and n(n-1) /2 comparisons. Q(n2)

//Selection Sort （not stable） 
template <class Elem>
void selsort(Elem A[], int n) {
  for (int i=0; i<n-1; i++) { 
 // select the minial values in [i,n-1]
    int lowindex = i; // Remember its index
    for (int j=n-1; j>i; j--) // Find least
      if (A[j]< A[lowindex])
        lowindex = j; // Put it in place
    swap(A, i, lowindex);
  }
}
//Best Case: 0 swaps , n(n-1)/2 comparisons.                        ?(n2) 
//Worst Case:     n - 1 swaps and n(n-1)/2 comparisons        ?(n2) 
//Average Case: (n-1)/2 swaps and n(n-1)/2 comparisons     ?(n2) 

// Shellsort（not stable） 
template <class Elem>
void inssort2(Elem A[], int n, int from, int incr) 
{
  for (int i= from + incr; i<n; i+=incr)
    for (int j=i; (j> from &&
         		A[j]< A[j-incr]); j-=incr)
      	swap(A, j, j-incr);
}

template <class Elem>
void shellsort(Elem A[], int n) { // Shellsort
  for (int i=n/2; i>=1; i/=2)  // For each incr
    for (int j=0; j<i; j++)   // Sort sublists
      inssort2<Elem>(A, n, j, i);   
}
//当增量序列为      ?[k] = 2^(t-k+1)  - 1时，算法复杂度为O(n3/2)。 
//其中t是排序的趟数，1<=k<=t。例如（15，7，3，1）

//Quicksort algorithm
template <class Elem, class Comp>
void qsort(Elem A[], int i, int j) {
  if (j <= i) return;     // List too small
  int pivotindex = findpivot(A, i, j); //eg:(i+j)/2;

  swap(A, pivotindex, j);  // Put pivot at end
  // k will be first position on right side
  int k = partition<Elem,Comp>(A, i, j, A[j]);
  swap(A, k, j);         // Put pivot in place
  qsort<Elem,Comp>(A, i, k-1);
  qsort<Elem,Comp>(A, k+1, j);
}
template <class Elem>
int partition(Elem A[], int l, int r,Elem& pivot) {
  do {  
    while (A[l] < pivot) l++;
    while ((r > l) && A[r] >=pivot)
       r--;

    swap(A, l, r); // Swap out-of-place values
  } while (l < r); // Stop when they cross
  return l;       // Return first pos on right
}
//Best:nlogn
//worst：n^2 
//Average:nlogn

//Mergesort Cost
List mergesort(List inlist) {
  if (inlist.length() <= 1)return inlist;
  List l1 = half of the items from inlist;
  List l2 = other half of items from inlist;
  return merge(mergesort(l1), 
               mergesort(l2));
}
template <class Elem>
void mergesort(Elem A[], Elem temp[],
               int left, int right) {
  int mid = (left+right)/2;
  if (left == right) return; 

  mergesort<Elem>(A, temp, left, mid);
  mergesort<Elem>(A, temp, mid+1, right);
 for (int i=left; i<=right; i++) // Copy
    temp[i] = A[i];
  int i1 = left; int i2 = mid + 1;
  for (int curr=left; curr<=right; curr++) {
    if (i1 == mid+1)      // Left exhausted
      A[curr] = temp[i2++];
    else if (i2 > right)  // Right exhausted
      A[curr] = temp[i1++];
    else if (temp[i1] < temp[i2])
      A[curr] = temp[i1++];
    else A[curr] = temp[i2++];
}}
//Optimized Mergesort (两头向中间移进)
template <class Elem>
void mergesort(Elem A[], Elem temp[],
               int left, int right) {
  int mid = (left+right)/2;
  if (left == right) return; 

  mergesort<Elem>(A, temp, left, mid);
  mergesort<Elem>(A, temp, mid+1, right);

 for (int i=left; i<=right; i++) // Copy
    temp[i] = A[i];
  int i1 = left; int i2 = mid + 1;
  for (int curr=left; curr<=right; curr++) {
    if (i1 == mid+1)      // Left exhausted
      A[curr] = temp[i2++];
    else if (i2 > right)  // Right exhausted
      A[curr] = temp[i1++];
    else if (temp[i1] < temp[i2])
      A[curr] = temp[i1++];
    else A[curr] = temp[i2++];
}}
  for (i=mid; i>=left; i--) temp[i] = A[i];
  for (j=1; j<=right-mid; j++)
    temp[right-j+1] = A[j+mid];
  
  for (i=left,j=right,k=left; k<=right; k++)
    if (temp[i] < temp[j]) A[k] = temp[i++];
    else A[k] = temp[j--];
}
//Time:n log n in the best, average, and worst cases (每一层都是 n ,共有logn层)
//Space:2n
  
// Heapsort
Bool removemax(Elem& it) {
  if (n == 0) return false; // Heap is empty
  swap(Heap, 0, --n);      // Swap max with end
  if (n != 0) siftdown(0);
  it = Heap[n];            // Return max value
  return true;
}
template <class Elem>
void heapsort(Elem A[], int n) { //Heapsort
  Elem mval;
  maxheap<Elem> H(A, n, n);
  for (int i=0; i<n; i++)  // Now sort
    H.removemax(mval);     
}

// Binsort
for (i=0; i<n; i++) //A simple, efficient sort: 
	B[A[i]] = A[i];

