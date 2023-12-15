//Implementation of 2-3 Tree 
template<class Key,class Elem>
bool TTTree<Key,Elem>::inserthelp(TTNode<Elem>*& subroot,  
			const Elem& e,Elem& retval,  TTNode<Elem>*& retptr) {
//e-->待插入元素 ; retval-->返回给上一级的值 ; retptr-->返回给上一级的指针
 	Elem myretv;     
	TTNode<Elem>* myretp = NULL;
    if (subroot = = NULL) {// Empty tree: make new node            
		subroot = new TTNode<Elem>( );      
		subroot->lkey = e;
	}else if(subroot->isLeaf()) {
		// At leaf node: insert here
		if(subroot->rkey == EMPTY) { 
		// Easy case: not full
			if (subroot->lkey < e) 
                subroot->rkey = e;
            else{
				subroot->rkey = subroot->lkey;  
                subroot->lkey = e; 
			}
		}
		else //此节点已经满了 
			splitnode(subroot, e, NULL, retval, retptr);
	}
	else if(e<subroot->lkey) //Insert in child 
		inserthelp(subroot->left, e, myretv, myretp);
	else if((subroot->rkey = = EMPTY) ||(e < subroot->rkey ))
        inserthelp(subroot->center, e, myretv, myretp);
	else 
		inserthelp(subroot->right, e, myretv, myretp);
	//If myretp is not NULL，insert myretv into subroot
	if(myretp!=NULL) //Child split:receive promoted value
		if(subroot->rkey!=EMPTY) //Full:split node
			split(subroot,myretv,myretp,retval,retptr);
		else{ //Not full:add to this node
			if(myretv<subroot->lkey) {
				subroot->rkey=subroot->lkey;
				subroot->lkey=myretv;
				subroot->right=subroot->center;
				subroot->center=myretp;
			}
			else{
				subroot->rkey=myretv;
				subroot->right=myretp;
			}				 
		}
	return true;
}
	
//Splitnode
template<class Key,class Elem>
bool TTTree<Key,Elem>::splitnode(TTNode<Elem>*subroot,const Elem&inval,TTNode<Elem>*inptr,Elem&retval,TTNode<Elem>*&retptr) {
	retptr = new TTNode<Elem>();
	if(inval < subroot->lkey) { //Add at left
		retval = subroot->lkey;
		subroot->lkey = inval;
		retptr->lkey=subroot->rkey;
		retptr->left = subroot->center;
		retptr->center=subroot->right;
		subroot->center = inptr; 
	} 
	else if(inval < subroot->rkey) { //center 
		retval = inval;
		retptr->lkey = subroot->rkey;
		retptr->left=inptr;
		retptr->center=subroot->right;
	}
	else { //Add at right
		retval = subroot->rkey;                
		retptr->lkey = inval;
        retptr->left = subroot->right;     
		retptr->center = inptr;  
	}
}
