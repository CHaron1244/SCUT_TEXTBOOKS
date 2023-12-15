bool insert(const Elem& val) {
  if (n >= size) return false; // Heap is full
  int curr = n++;
  Heap[curr] = val;            // Start at end of heap
  // Now sift up until curr's parent > curr
  while ((curr!=0) &&
         (Heap[curr] >Heap[parent(curr)])) {
    swap(Heap, curr, parent(curr));  //swap curr and its parent
    curr = parent(curr);
  }
  return true;
}


void siftdown(int pos) {
  while (!isLeaf(pos)) {
    int j = leftchild(pos);
    int rc = rightchild(pos);
    if ((rc<n) && Heap[j]< Heap[rc])
      j = rc;  // j -> the bigger child
    if (Heap[pos] >= Heap[j]) return; 
    swap(Heap, pos, j);
    pos = j;
}}
void void buildHeap() 
{ for (int i=n/2-1;  i>=0;  i--)   siftdown(i); }

Bool removemax(Elem& it) {
  if (n == 0) return false; // Heap is empty
  swap(Heap, 0, --n);      // Swap max with end
  if (n != 0) siftdown(0);
  it = Heap[n];            // Return max value
  return true;
}

bool remove(int pos, Elem& it) {
  if ((pos < 0) || (pos >= n)) return false; 
  swap(Heap, pos, --n);
  while ((pos != 0) && (Heap[pos]>  Heap[parent(pos)])){ 
  	  swap(Heap, pos, parent(pos));
      pos = parent(pos);    
   }
  siftdown(pos);
  it = Heap[n]; //£¿£¿£¿£¿ 
  return true;
}
