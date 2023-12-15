/*
描叙：有n个人站队，所有的人全部向右看，个子高的可以看到个子低的发型
给出每个人的身高，问所有人能看到其他人发现总和是多少。
输入：4 3 7 1
输出：2
*/
int FieldSum(vector<int>& v)
{
	v.push_back(INT_MAX);//这里可以理解为需要一个无限高的人挡住栈中的人，不然栈中元素最后无法完全出栈
	stack<int> st;
	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (st.empty() || v[st.top()] > v[i])//小于栈顶元素入栈
		{
			st.push(i);
		}
		else
		{
			while (!st.empty() && v[st.top()] <= v[i])
			{
				int top = st.top();//取出栈顶元素
				st.pop();
				sum += (i - top - 1);//这里需要多减一个1
			}
			st.push(i);
		}
	}
	return sum;
}

