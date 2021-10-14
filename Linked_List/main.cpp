#include<iostream>

template<class T>
class list
{
	template<class T>
	struct node
	{
		T data;
		node* next_node;
	};
private:
	node<T> Head;
	node<T>* Tail;
	int count;
public:
	list<T>()
	{
		count = 0;
		Head = { 0 , nullptr };
	}
	void Add(T Element)
	{
		node<T>* new_node = new node<T>{ Element , nullptr };// Contruct the node
		if (count == 0)
		{
			Head.next_node = new_node;
		}
		if (count > 0)
		{
			Tail->next_node = new_node;
		}
		++count;
		Tail = new_node;
	}
	void Display()
	{
		int x = count;
		node<T> temp = Head;
		while (x != 0)
		{
			std::cout << temp.next_node->data << '\n';
			temp = *(temp.next_node);
			--x;
		}
	}
};


int main()
{
	list<int> mylist;
	mylist.Add(20);
	mylist.Add(30);
	


	mylist.Display();
	return 0;
}