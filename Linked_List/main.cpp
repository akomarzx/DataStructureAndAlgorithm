#include<iostream>
#include<initializer_list>
#include<string>
// Class for a single linked list

template<class T>
class linked_list
{

	struct node
	{
		T* data;
		node* next_node;
		~node()
		{
			if (data != nullptr)
			{
				delete data;
			}
		}
	};

private:
	node* head_pointer;
public:

	linked_list()
		:head_pointer{ std::move(new node{nullptr,nullptr})}
	{}

	linked_list(std::initializer_list<T> list)
		:head_pointer{ std::move(new node{nullptr,nullptr})}
	{
		for (auto x : list)
		{
			this->Append(x);
		}
	}
	~linked_list()
	{
		while (head_pointer->next_node != nullptr)
		{
			node* temp = head_pointer->next_node;
			head_pointer->next_node = temp->next_node;
			delete(temp);
		}
		delete(head_pointer);
	}

	//************************************
	// Method:    Append
	// FullName:  linked_list::Append
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int element
	// Append the current list with element 
	//************************************
	void Append(T element)
	{
		if (head_pointer->next_node == nullptr)
		{
			head_pointer->next_node = std::move(new node{ new T(element),nullptr });
		
			return;
		}

		node* temp = head_pointer->next_node;

		while (temp->next_node != nullptr)
		{
			temp = temp->next_node;
		}
 
		temp->next_node = std::move(new node{ new T(element),nullptr });
	}
	void Display()const
	{
		node* temp = head_pointer->next_node;
		while (temp != nullptr)
		{
			std::cout << *(temp->data) << " ";
			temp = temp->next_node;
		}
		std::cout << '\n';
	}
	//************************************
	// Method:    Insert
	// FullName:  linked_list::Insert
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int at
	// Parameter: int element
	// 
	// Insert the element after the at element
	// use -1 to insert on the front 
	// use Append() method if you want to insert in the back
	//************************************
	void Insert(int at,T element)
	{
		node* temp = head_pointer->next_node;
		if (at == -1)
		{
			node* newNode = std::move(new node{ new T(element), temp->next_node });
			head_pointer->next_node = newNode;
			newNode->next_node = temp;
			return;
		}
		int counter = 1;
		while (temp->next_node != nullptr && counter <= at)
		{
			if (counter == at)
			{
				node* newNode = std::move(new node{ new T(element), temp->next_node});
				temp->next_node = newNode;
			}
			temp = temp->next_node;
			++counter;
		}
	}
};

class foo
{
public:
protected:
private:
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	linked_list <std::string > mylist{ "Ronald" , "Ombao"};
	mylist.Append("Rebekah");
	mylist.Insert(1, "jewel");
	mylist.Insert(-1, "Rsds");
	mylist.Append("FASDASD");
	mylist.Display();
	linked_list<foo> list;
	return 0;
	_CrtDumpMemoryLeaks();
}