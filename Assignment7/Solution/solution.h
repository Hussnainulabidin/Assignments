/*
Name    : Hussnain Ul Abidin
Section : K
Roll No : 22i-1102
*/
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node* next;
	Node(T data)
	{
		this->data = data;
		next = NULL;
	}
	Node()
	{
		next = NULL;
	}
};

template <class A>
class Stack
{
public:
	Node<A>* head;
	Node<A>* end;
	Stack()
	{
		head = NULL;
		end = NULL;
	}
	void push(A item)
	{
		Node<A>* newNode = new Node<A>(item);
		newNode->data = item;
		newNode->next = NULL;
		if (head == NULL)
		{
			head = newNode;
			end = newNode;
		}
		else
		{
			end->next = newNode;
			end = end->next;
		}
	}
	A pop()
	{
		if (head == end)
		{
			Node<A>* newNode = head;
			head = NULL;
			end = NULL;
			return newNode->data;
		}
		Node<A>* newNode = head;
		while (newNode->next != end)
		{
			newNode = newNode->next;
		}
		Node<A>* temp = end;
		end = newNode;
		newNode->next = NULL;
		return temp->data;
	}
	A& peek()
	{
		return end->data;
	}
	A& front()
	{
		return head->data;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	void clear()
	{
		head = NULL;
		end = NULL;
	}
	int size()
	{
		if (head == NULL)
			return 0;
		Node<A>* newNode = head;
		int index = 0;
		do
		{
			index += 1;
			newNode = newNode->next;
		} while (newNode != NULL);
		return index;
	}
	void print()
	{
		if (head == NULL)
			return;
		Node<A>* newNode = head;
		do
		{
			cout << newNode->data << " ";
			newNode = newNode->next;
		} while (newNode != NULL);
		cout << endl;
	}
};

template <class T>
class Queue
{
public:
	Node<T>* head;
	Node<T>* end;
	Queue()
	{
		head = NULL;
		end = NULL;
	}
	void enqueue(T data)
	{
		if (head == NULL)
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;
			newNode->next = NULL;
			head = newNode;
			end = newNode;
			return;
		}
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = NULL;
		end->next = newNode;
		end = newNode;
	}
	T& dequeue()
	{

		Node<T>* temp = head;
		head = head->next;
		temp->next = NULL;
		return temp->data;
	}
	T& peek()
	{
		return head->data;
	}
	bool is_empty()
	{
		if (head == NULL)
			return true;
		return false;
	}
	int size()
	{
		Node<T>* temp = head;
		int index = 0;
		if (temp == NULL)
		{
			return 0;
		}
		else
		{
			do
			{
				index++;
				temp = temp->next;

			} while (temp != NULL);
		}
		return index;
	}
	void clear()
	{
		head = NULL;
		end = NULL;
	}
	void print()
	{
		if (head == NULL)
			return;
		Node<T>* newNode = head;
		do
		{
			cout << newNode->data << " ";
			newNode = newNode->next;
		} while (newNode != NULL);
		cout << endl;
	}
};
/*
Complexity  = O(n + k )
n is for the main Loop that Deals with Stack 
K for actually creating the string from the stack
*/
std::string largestString(std::string str, int k)
{
	Stack<char> stack;
	int indexStr = 0;
	stack.push(str[indexStr++]);
	while (str[indexStr] != '\0')
	{
		if (!stack.isEmpty() && k > 0)
		{
			char topchar = stack.peek();
			if (topchar < str[indexStr])
			{
				stack.pop();
				k -= 1;
				continue;
			}
		}
		stack.push(str[indexStr++]);
	}
	while (k > 0 && !stack.isEmpty())
	{
		stack.pop();
		k--;
	}
	std::string newstr = "";
	while (!stack.isEmpty())
	{
		newstr = stack.pop() + newstr;
	}
	return newstr;
}

/*
Complexity  = O(n + k )
n is for the main Loop that Deals with Stack
K for actually creating the string from the stack
*/
std::string solve(std::string str, int k)
{
	Stack<char> stack;
	int index = 0;
	int strLength = str.length();
	int ansSize = str.length() - k;
	char topChar;
	while (str[index] != '\0')
	{

		if (!stack.isEmpty() && k > 0)
		{
			topChar = stack.peek();
			char bottomChar = stack.front();
			int size = (strLength - index) - (k - stack.size());
			if (str[index] < bottomChar && stack.size() <= k && size >= ansSize && str[index] != '0')
			{
				k -= stack.size();
				stack.clear();
				continue;
			}
			else if (topChar > str[index])
			{

				if (str[index] == '0' && stack.size() <= 1)
				{
				}
				else
				{
					stack.pop();
					k--;
					continue;
				}
			}
		}
		if (str[index] == '0' && stack.isEmpty() && k >= 0)
		{
			index++;
			k -= 1;
		}
		else
		{
			stack.push(str[index++]);
		}
	}
	while (k > 0 && !stack.isEmpty())
	{
		stack.pop();
		k--;
	}
	std::string newstr = "";
	while (!stack.isEmpty())
	{
		newstr = stack.pop() + newstr;
	}
	return newstr;
}

/*
Complexity  = O(n + k )
n is for the main Loop that Deals with Queue for Max Subsequence
K for actually creating array from the Queue to return Answer
*/
int* maxSubsequence(int* arr, int size, int k)
{
	Queue<int> indexArrayQueue;
	int* result = new int[k];
	int maxIndex = 0;
	int finalMaxprofit = -2147483647;
	int tempProfit = 0;
	for (int i = 0; i <= size; ++i)
	{
		if (indexArrayQueue.size() == k)
		{
			if (tempProfit > finalMaxprofit)
			{
				finalMaxprofit = tempProfit;
				maxIndex = indexArrayQueue.peek();
			}
			if (arr[indexArrayQueue.peek()] < 0)
				tempProfit -= arr[indexArrayQueue.peek()];
			else
				tempProfit -= arr[indexArrayQueue.peek()];
			indexArrayQueue.dequeue();
		}
		tempProfit += arr[i];
		indexArrayQueue.enqueue(i);
	}
	int j = 0;
	for (int i = maxIndex; i < maxIndex + k; ++i)
	{
		result[j] = arr[i];
		j++;
	}
	return result;

}