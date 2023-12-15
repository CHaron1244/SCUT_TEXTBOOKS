void insert(const Key& k,const E& e) {
    root = inserthelp(root, k,e);
    nodecount++;
  }
	
//return the root of the updated BST after insertion 
template <typename Key, typename E>
BSTNode<Key,E>* BST<Key, E>::inserthelp(BSTNode<Key,E>* root, const Key& k, const E& it) {
 if (root == NULL) // Empty: create node
   return new BSTNode<Key,E>(k,it,NULL,NULL);
 if (k < root->key()))
   root->setLeft(inserthelp(root->left(),k,it));
 else root->setRight(inserthelp(root->right(), k,it));
 // Return subtree with node inserted
 return root;
}
//P43


//return the root of the updated tree after removal
//t point to the removed node
BSTNode<Key,E>* BST<Key, E>::
removehelp(BSTNode<Key,E>* rt, const Key& k) {
  if (rt == NULL) return NULL;
  else if (k < rt->key())
    rt->setLeft(removehelp(rt->left(), k));
  else if (k > rt->key())
    rt->setRight(
        removehelp(subroot->right(), k));
 else {             // Found it: remove it
    BSTNode<Key,E>* temp;
    temp = rt;
    if (rt->left() == NULL){
      rt = rt->right();delete temp; }
    else if (rt->right() == NULL){
      rt = rt->left();delete temp;  } 
    else {  // Both children are non-empty
      BSTNode<Key,E>* temp;
      temp=getmin(rt->right());
      rt->setElement(temp->element());
      rt->setKey(temp->key());
      rt->setRight(
          deletemin(subroot->right()));
      delete temp;
    } }
  return rt;
}


//return the root of the tree after remove the node with the minimum value
BSTNode<Key,E>* BST<Key, E>::
 deletemin(BSTNode<Key,E>* rt) {
  if (rt->left() == NULL) {
    return rt->right();
  }
  else { // Continue left
    rt->setLeft(deletemin(rt->left()));
    return rt;
  }
}
