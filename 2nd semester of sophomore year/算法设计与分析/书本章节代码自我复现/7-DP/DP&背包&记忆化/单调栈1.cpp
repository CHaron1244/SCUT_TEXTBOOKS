/*
������n����վ�ӣ����е���ȫ�����ҿ������ӸߵĿ��Կ������ӵ͵ķ���
����ÿ���˵���ߣ����������ܿ��������˷����ܺ��Ƕ��١�
���룺4 3 7 1
�����2
*/
int FieldSum(vector<int>& v)
{
	v.push_back(INT_MAX);//����������Ϊ��Ҫһ�����޸ߵ��˵�סջ�е��ˣ���Ȼջ��Ԫ������޷���ȫ��ջ
	stack<int> st;
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (st.empty() || v[st.top()] > v[i])//С��ջ��Ԫ����ջ
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && v[st.top()] <= v[i])
			{
				int top = st.top();//ȡ��ջ��Ԫ��
				st.pop();
				sum += (i - top - 1);//������Ҫ���һ��1
			}
			st.push(i);
		}
	}
	return sum;
}

