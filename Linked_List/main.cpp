#include<iostream>
#include<initializer_list>
#include<string>

//Class for creating a singly linked list
template<class T>
class linked_list
{
private:
	struct node
	{
		T* data;
		node* next;
		~node()
		{
			delete data;
		}
	};
private:
	node* head; 
	node* tail;

public:

	linked_list()
		:head{nullptr}, tail{head}{}

	linked_list(std::initializer_list<T> list)
	{
		for (auto element : list)
		{
			this->_Insert(element);
		}
	}
	~linked_list()
	{
		
		while (head != tail)
		{
			node* temp = head;
			head = temp->next;
			delete(temp);
		}
		delete head;
	}
	//************************************
	// Returns:bool
	// Insert the element after the given position.
	// Use -1 to insert on the first position O(1)
	// use -2 to insert on the last position O(1)
	// Else will insert after the at position O(n) based on 0 index
	// return true if insertion is successful
	//************************************
	bool Insert(int at, T element)
	{
		if (TheNodeIsNull(head))
		{
			return false;
		}

		if (at == -1 && !TheNodeIsNull(head))
		{
			_InsertAtFront(element);
			return true;
		}
		else if (at == -2 && !TheNodeIsNull(head))
		{
			_InsertAtBack(element);
			return true;
		}
		else
		{
			int counter = 0;
			
			node* temp = head;

			while (temp != nullptr && counter <= at)
			{
				if (counter == at)
				{
					node* newNode = std::move(new node{ new T(element) , temp->next });
					temp->next = newNode;
					return true;
				}
				temp = temp->next;
				++counter;
			}
			return false;
		}
	}
	void Display()
	{
		node* temp = head;

		while (!TheNodeIsNull(head) && temp != nullptr)
		{
			std::cout << *(temp->data) << ' ';
			temp = temp->next;
		}
		std::cout << '\n';
	}
private:
	bool TheNodeIsNull(node* _node)
	{
		if (_node == nullptr)
		{
			return true;
		}
		return false;
	}

	//************************************
	// Method:    _Insert
	// FullName:  linked_list<T>::_Insert
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: T element
	// Internal function used by the constructor with initializer list 
	// to populate the list. keeps track of the head and tail.
	//************************************
	void _Insert(T element)
	{
		if (TheNodeIsNull(head))
		{
			node* newNode = std::move(new node{new T(element), nullptr});
			head = newNode;
			tail = head;
			return;
		}

		node* newNode = std::move(new node{new T(element) , nullptr});
		tail->next = newNode;
		tail = newNode;
	}
	
	//************************************
	// Method:    _InsertAtFront
	// FullName:  linked_list<T>::_InsertAtFront
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: T element
	// Internal method only don't call when the list is empty
	//************************************
	void _InsertAtFront(T element)
	{
		node* newNode = std::move(new node{ new T(element) , nullptr });
		newNode->next = head;
		head = newNode;
	}

	//************************************
	// Method:    _InsertAtFront
	// FullName:  linked_list<T>::_InsertAtFront
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: T element
	// Internal method only don't call when the list is empty
	//************************************
	void _InsertAtBack(T element)
	{
		node* newNode = std::move(new node{ new T(element) , nullptr });
		tail->next = newNode;
		tail = newNode;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		
	linked_list<int> list{ 1,2,3,4,5 };

	list.Display();
	return 0;
	_CrtDumpMemoryLeaks();
}