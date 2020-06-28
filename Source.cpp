#include <iostream>
#include"Stack.h"
using namespace std;

template<class T_type>
class List
{
private:
	struct Node
	{
		T_type value;
		Node* next;
	};

	Node* head;
public:
	List() : head(nullptr) { }
	~List()
	{
		while (!IsEmpty())
		{
			DeleteHead();
		}
	}

	//c-py constructor
	List(const List& other):head(nullptr)
	{
		for (Node* el = other.head; el != nullptr; el = el->next)
		{
			this->AddToTail(el->value);
		}
	}
	//operator = for list
	List& operator = (const List& other)
	{
		if (head != nullptr)
		{
			Node* prev = nullptr;
			while (head != nullptr)
			{
				prev = head;
				head = head->next;
				delete prev;
			}
		}
		Node* temp = other.head, * newer = new Node;
		head = newer;
		while (temp != nullptr)
		{
			newer->value = temp->value;
				temp = temp->next;
			if (temp != nullptr)
			{
				newer->next = new Node;
				newer = newer->next;
			}
			else
				newer->next = nullptr;
		}
		return *this;
		
	}

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	// додати елемент до голови
	void AddToHead(T_type value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		head = newElem;
	}

	// додати елемент до хвоста
	void AddToTail(T_type value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;

		if (head == nullptr)
		{
			head = newElem;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				// move to next
				current = current->next;
			}

			current->next = newElem;
		}
	}

	// видалити елемент з голови
	void DeleteHead()
	{
		if (head == nullptr) return;

		Node* temp = head->next;
		delete head;

		if (temp == nullptr)
			head = nullptr;
		else
			head = temp;
	}

	// видалити елемент з хвоста
	void DeleteTail()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				// move to next
				current = current->next;
			}

			// видаляємо останній елемент
			delete current->next;
			current->next = nullptr;
		}
	}

	void Show() const
	{
		Node* current = head;
		while (current != nullptr)
		{
			// print current value
			cout << current->value << ", ";

			// move to next
			current = current->next;
		}
	}
	//delete element by possition
	void DelByPoss(int pos)
	{
		Node* current = new Node;
		Node* previous = new Node;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}

	//adding element at partucular possition
	void InsertToPoss(int pos, T_type value)
	{
		Node* pre = new Node;
		Node* cur = new Node;
		Node* temp = new Node;
		cur = head;
		for (int i = 1; i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->value = value;
		pre->next = temp;
		temp->next = cur;
	}
	//method delete all 
	void DeleteAll() {
		Node* temp = head, * next;
		while (temp != NULL) {
			next = temp->next;
			delete temp;
			temp = next;
		}
		delete head;
		head = NULL;
	}
	//method find
	bool Find(T_type val)
	{
		Node* current = head; 
		while (current != NULL)
		{
			if (current->value == val)
				return true;
			current = current->next;
		}
		return false;
	}

	
};



int main()
{
	List<int> ls;

	ls.AddToHead(10);
	ls.AddToHead(15);
	ls.AddToHead(5);
	ls.AddToHead(20);

	ls.Show(); cout << endl;
	ls.Find(2);
	/*ls.DeleteHead();
	ls.AddToTail(777);

	ls.Show(); cout << endl;

	ls.DeleteTail();
	ls.DeleteTail();*/

	ls.Show(); cout << endl;

	return 0;
}