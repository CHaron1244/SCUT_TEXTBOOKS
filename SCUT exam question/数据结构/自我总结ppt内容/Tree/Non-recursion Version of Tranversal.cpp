// 非-递归前序遍历二叉树
void preOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int k = -1;
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		k++;
		// 仿照一个栈
		stack[k] = root; // 将根节点入栈
		while (k > -1){
			//出栈
			node = stack[k--];
			printf(" %c - ", node->data);
 
			// 先把右子树放进去，栈是先进去后出，所以下面的左子树先出
			if (node->right != NULL){
				stack[++k] = node->right;
			}
			if (node->left != NULL){
				stack[++k] = node->left;
			}
		}
	}
}//放在栈中的元素表示已经访问过且右子树尚未访问过节点。
//在访问该节点的左子树之前，现将该节点入栈。

// 非-递归实现中序遍历二叉树
//1. 从根结点开始，遍历左孩子同时压栈，当遍历结束，说明当前遍历的结点没有左孩子，
//2. 从栈中取出来调用操作函数，然后访问该结点的右孩子，继续以上重复性的操作。
void inOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	// 判断树是否为空
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	node = root;
	while (node != NULL || top > 0){
 
		// 将所有的左子树节点入栈
		while (node != NULL){
			stack[++top] = node;
			node = node->left;
		}
		//  如果右节点为空的话，执行下列语句
		node = stack[top--];
		printf(" %c - ", node->data);
 
		// 扫描右节点
		node = node->right;
	}
 
}

//我们知道 后序遍历的顺序为： 左->右->根
//那么可以把后序当作：根->右->左，最后再反转回来即可。
//由于我们是使用的栈，所以先保存根节点， 然后先放进去 左节点，再放 进去 右节点
void backOrderNRecSimple(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	int count = 0;
	char array[MAXSIZE]; // 使用一个数组来保存数据，方便最后数组的反转
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		top++;
		// 仿照一个栈
		stack[top] = root; // 将根节点入栈
		while (top > 0){
			//出栈
			node = stack[top--];
			array[count++] = node->data; // 将其保存在一个数组当中
 
			// 先把右子树放进去，栈是先进去后出，所以下面的左子树先出
			if (node->left != NULL){
				stack[++top] = node->left;  // 入栈
			}
			if (node->right != NULL){
				stack[++top] = node->right;
			} 
		} 
	}
	// 反转数组，输出
	for (int i = count-1; i >= 0; i--){
		printf(" %c - ", array[i]);
	}
 
}
