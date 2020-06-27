#include <iostream>
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

	void Print() const
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
};

int main()
{
	List<int> ls;

	ls.AddToHead(10);
	ls.AddToHead(15);
	ls.AddToHead(5);
	ls.AddToHead(20);

	ls.Print(); cout << endl;

	ls.DeleteHead();
	ls.AddToTail(777);

	ls.Print(); cout << endl;

	ls.DeleteTail();
	ls.DeleteTail();

	ls.Print(); cout << endl;

	return 0;
}