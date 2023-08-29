#pragma once

// For Double LinkedList
	// Add Node* prev
	// Add -- operators
	// and other such relevent things

class List {
protected:
	struct Node {
	public:
		Node(int data) : data{ data }, next{ nullptr }, previous{ nullptr } {}
		~Node() {
			if (next != nullptr) {
				delete next;
			}
		}
		int data;
		Node* next;
		Node* previous;

	};

	Node* head;
	Node* tail;
	int size;

public:
	struct Iterator {
	private:
		Node* value;
	public:
		Iterator(Node* value) : value{ value } {}

		Iterator& operator++() { // Prefix ++i so increases then we use
			value = value->next;
			return *this;
		}

		Iterator& operator++(int) { // Postfix i++ where we use it then it increases
			Iterator tmp = *this;
			value = value->next;
			return tmp;
		}

		Iterator& operator--() { // Prefix --i so decreases then we use
			value = value->previous;
			return *this;
		}

		Iterator& operator--(int) { // Postfix i-- where we use it then it decreases
			Iterator tmp = *this;
			value = value->previous;
			return tmp;
		} 

		bool operator!=(const Iterator& rhs) {
			return value != rhs.value;
		}
		bool operator==(const Iterator& rhs) {
			return value == rhs.value;
		}


		int operator*() {
			return value->data;
		}

		Node* operator->() {
			return value;
		}

		/*void InsertAfter(int data) {
			Node* newNode = new Node(data);
			newNode->next = value->next;
			value->next = newNode;
		}*/

		Node* GetValue() {
			return value;
		}
	};

	List() {
		head = nullptr;
		tail = nullptr;
	}

	~List() {
		if (IsEmpty()) {
			Clear();
		}
	}

	//Common Methods

	//Adding Methods

	void PushFront(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			return;
		}
		else {
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void PushBack(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			return;
		}
		else {
			tail->next = newNode;
			newNode->previous = tail;
			newNode = tail;
		}
	}

	void Insert(Iterator currentNode, int value) {
		Node* newNode = new Node(value);
		newNode->next = currentNode->;

		if (currentNode != nullptr) {
			newNode->previous = currentNode->previous;
			if (currentNode->previous != nullptr)
			{
				currentNode->previous->next = newNode;
			}
			currentNode->previous = newNode;
		}

		if (currentNode == head) {
			head = newNode;
		}

		if (tail == nullptr) {
			tail = newNode;
		}
		
		
	}

	//Remove Methods

	void PopFront() {
		if (IsEmpty()) {
			return;
		}
		if (head != nullptr) {
			Node* temp = head;

			if (head->next != nullptr) {
				head->next->previous = nullptr;
			}

			head = head->next;

			delete temp;

			size--;
		}
	}

	void PopBack() {
		if (IsEmpty()) {
			return;
		}
		if (head != nullptr) {
			Node* temp = head;

			if (head->next != nullptr) {
				head->next->previous = nullptr;
			}

			head = head->next;

			delete temp;

			size--;
		}
	}








	bool IsEmpty() {
		return head == nullptr;
	}

	//Returns head by value
	int First() {
		if (head != nullptr)
			return head->data;
	}

	//Returns tail by value
	int Last() {
		if (tail != nullptr)
			return tail->data;
	}

	void Remove(int value) {
		Iterator previous(nullptr);
		for (auto i = Begin(); i != End();) {

			if (*i == value) {
				// If we are the head
				if (i.GetValue() == head) {
					head = i->next;
					Node* temp = i.GetValue();


					++i;

					i->next = nullptr;


					delete temp;
					size--;
					continue;
				}
				else if (i.GetValue() == tail) {
					previous->next = tail->next;
					delete tail;
					tail = previous.GetValue();
					size--;
					return;
				}
				else {
					previous->next = i->next;


					Node* temp = i.GetValue();
					++i;
					temp->next = nullptr;

					delete temp;
					size--;
					continue;
				}



				// We set prev i to i->next
				//set our next to nullptr
				//delete ourself
			}

			previous = i;
			i++;

		}
	}

	Iterator Begin() {
		return Iterator(head);
	}
	Iterator End() {
		return Iterator(tail->next);
	}

	int GetSize() {
		return size;
	}

	void Clear() {
		delete head;
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
};