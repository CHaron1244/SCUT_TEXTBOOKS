// ��-�ݹ�ǰ�����������
void preOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int k = -1;
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		k++;
		// ����һ��ջ
		stack[k] = root; // �����ڵ���ջ
		while (k > -1){
			//��ջ
			node = stack[k--];
			printf(" %c - ", node->data);
 
			// �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ�
			if (node->right != NULL){
				stack[++k] = node->right;
			}
			if (node->left != NULL){
				stack[++k] = node->left;
			}
		}
	}
}//����ջ�е�Ԫ�ر�ʾ�Ѿ����ʹ�����������δ���ʹ��ڵ㡣
//�ڷ��ʸýڵ��������֮ǰ���ֽ��ýڵ���ջ��

// ��-�ݹ�ʵ���������������
//1. �Ӹ���㿪ʼ����������ͬʱѹջ��������������˵����ǰ�����Ľ��û�����ӣ�
//2. ��ջ��ȡ�������ò���������Ȼ����ʸý����Һ��ӣ����������ظ��ԵĲ�����
void inOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	// �ж����Ƿ�Ϊ��
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	node = root;
	while (node != NULL || top > 0){
 
		// �����е��������ڵ���ջ
		while (node != NULL){
			stack[++top] = node;
			node = node->left;
		}
		//  ����ҽڵ�Ϊ�յĻ���ִ���������
		node = stack[top--];
		printf(" %c - ", node->data);
 
		// ɨ���ҽڵ�
		node = node->right;
	}
 
}

//����֪�� ���������˳��Ϊ�� ��->��->��
//��ô���԰Ѻ���������->��->������ٷ�ת�������ɡ�
//����������ʹ�õ�ջ�������ȱ�����ڵ㣬 Ȼ���ȷŽ�ȥ ��ڵ㣬�ٷ� ��ȥ �ҽڵ�
void backOrderNRecSimple(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	int count = 0;
	char array[MAXSIZE]; // ʹ��һ���������������ݣ������������ķ�ת
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		top++;
		// ����һ��ջ
		stack[top] = root; // �����ڵ���ջ
		while (top > 0){
			//��ջ
			node = stack[top--];
			array[count++] = node->data; // ���䱣����һ�����鵱��
 
			// �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ�
			if (node->left != NULL){
				stack[++top] = node->left;  // ��ջ
			}
			if (node->right != NULL){
				stack[++top] = node->right;
			} 
		} 
	}
	// ��ת���飬���
	for (int i = count-1; i >= 0; i--){
		printf(" %c - ", array[i]);
	}
 
}
