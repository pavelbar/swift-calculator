// Example program
#include <iostream>
#include <string>
using namespace std;

const int MaxSize = 100;
template <class T>
class TStack
{
protected:
	T *pMem;
	int size;
	int count;
public:
	TStack(int = 10);
	~TStack();
	bool IsEmpty();
	bool IsFull();
	void Push(const T &val);//add
	T Pop();//�������� � �������
	T Top();//view
};
//-----------------------------------
template <class T>
TStack<T>::TStack(int len) {
	if ((len<1) || (len>MaxSize)) throw (len);
	size = len;
	count = 0;
	pMem = new T[size];// pMem[0] and pMem[1]
}



template <class T>
TStack<T>::~TStack() {
	delete[]pMem;
	pMem = NULL;
}

template <class T>
bool TStack<T>::IsEmpty() {
	return(count == 0);
}

template <class T>
bool TStack<T>::IsFull() {
	return (count == size);
}

template <class T>
void TStack<T>::Push(const T &val) {
	if (IsFull())  throw (count);
	pMem[count] = val;
	count++;
}

template <class T>
T TStack<T>::Pop() {
	if (IsEmpty()) throw (count);
	count--;
	return pMem[count];
}

template <class T>
T TStack<T>::Top() {
	if (IsEmpty()) throw (count);
	return pMem[count - 1];
}





class TPostfix
{
	string infix;
	string postfix;
public:
	TPostfix(string val)
	{
		infix = val;
	}

	int Priority(char val)
	{
		if ((val == '*') || (val == '/')) return 2;
		if ((val == '+') || (val == '-')) return 1;
		return -7;
	}
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	
	string ToPostfix()
	{
	    	char result[MaxSize];
	int result_pos = 0;
	TStack<char> stack_op(MaxSize);
	/*http://natalia.appmat.ru/c&c++/postfisso.html
	�������� �������� ��������� � ����������� ������ ���������:
	(1) ��������� � ���������� �������� � ����������� ������ � ������� �� ��������� � �������� �������.
	��� ��������� �������� � �������� �������:
	(a) ���� � ����� ��� �������� ��� ������� ��������� ����� �������� ����������� ������, �������� ������� � ����;
	(b) ���� ����� �������� ����� �������* ���������, ��� ������� �������� � �����, �� ����� �������� ������� � ����;
	(c) ���� ����� �������� ����� ������� ��� ������ ���������, ��� ������� �������� � �����, ��
	��������, ����������� � �����, �� ��������� ����������� ������ ��� �� �������� � ����������� �������, ��� � ����� ��������,
	��������������� � ����������� ������, � ����� �������� ������� � ����.
	(2)����������� ������ ������� � ����.
	(3)����������� ������ ����������� �� ����� � ����������� ������ ��� �������� �� ��������� ����������� ������, ����������� ������
	��������� �� �����.
	(4)����� ����, ��� �� ��������� �� ����� ��������� ���������, ��������, ���������� � �����, ��������������� � ����������� ���������.
	*/
	for (unsigned int i = 0; i < infix.length(); i++)
	{
		//--1--
		if ((infix[i] != '(') && (infix[i] != ')') && (infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/'))
		{
			result[result_pos] = infix[i];
			result_pos++;
			result[result_pos] = '\0';
		}
		//--2--
		if (infix[i] == '(') stack_op.Push(infix[i]);
		//--3--                                            
		if (infix[i] == ')')
		{
			while (stack_op.Top() != '(')//����
			{
				result[result_pos] = stack_op.Pop();
				result_pos++;
				result[result_pos] = '\0';
			}
			stack_op.Pop();
		}
		//-----
		if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/'))
		{
			//--a--
			if (stack_op.IsEmpty() || stack_op.Top() == '(') stack_op.Push(infix[i]);
			//--b--
			else if (Priority(infix[i]) > Priority(stack_op.Top())) stack_op.Push(infix[i]);
			//--c--
			else
			{
				while (!stack_op.IsEmpty() && Priority(infix[i]) <= Priority(stack_op.Top()))
				{
					result[result_pos] = stack_op.Pop();
					result_pos++;
					result[result_pos] = '\0';
				}
				stack_op.Push(infix[i]);
				//-----
			}
		}

	}
	//--4--
	while (stack_op.IsEmpty() == 0)//����
	{
		result[result_pos] = stack_op.Pop();
		result_pos++;
		result[result_pos] = '\0';
	}
	//-----
	postfix = result;
	return postfix;
	}
	
	double Calculate()
	{
	    	char a[MaxSize];
	double b[MaxSize];
	int flag;
	double k;

	TStack<double> stack(MaxSize);
	for (unsigned int i = 0; i < postfix.length(); i++)
	{
		//--a--
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/')
		{
			flag = 0;
			a[i] = postfix[i];
			for (int j = 0; j < i; j++)
				if (postfix[i] == a[j])
				{
					flag = 1;
					stack.Push(b[j]);
					break;
				}

			if (flag == 0)
			{
				char tmp[MaxSize];
				tmp[0] = postfix[i];
				tmp[1] = '\0';
				if ( isdigit(tmp[0]) ) b[i] = atoi(tmp); // ������������� ������� � ���� int
				else
				{
				cout << postfix[i] << "=";
				cin >> k;
				b[i] = k;
				}
				stack.Push(b[i]);
			}

		}
		else
			//--b--
		{
			if (postfix[i] == '+')
			{
				double tmp1 = stack.Pop();
				double tmp11 = stack.Pop();
				stack.Push(tmp11 + tmp1);
			}
			if (postfix[i] == '-')
			{
				double tmp1 = stack.Pop();
				double tmp11 = stack.Pop();
				stack.Push(tmp11 - tmp1);
			}
			if (postfix[i] == '/')
			{
				double tmp1 = stack.Pop();
				double tmp11 = stack.Pop();
				stack.Push(tmp11 / tmp1);
			}
			if (postfix[i] == '*')
			{
				double tmp1 = stack.Pop();
				double tmp11 = stack.Pop();
				stack.Push(tmp11 * tmp1);
			}
		}

	}

	return stack.Pop();;
	}
};

int main()
{
string expression;
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "������� �������������� ���������: ";
	cin >> expression;
	cout << expression << endl;
	TPostfix postfix(expression);
	cout << "�������������� ���������: " << postfix.GetInfix() << endl;
	postfix.ToPostfix();
	cout << "����������� �����: " << postfix.GetPostfix() << endl;
	res = postfix.Calculate();
	cout << res << endl;
	return 0;
}
