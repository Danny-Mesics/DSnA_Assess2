#pragma once

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
	int numberOfNodes;

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

#pragma region Adding Methods

	void PushFront(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		numberOfNodes++;
	}

	void PushBack(int data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		numberOfNodes++;
	}

	// Insert a new node after the current node
	void Insert(Iterator currentNode, int value) {
		Node* newNode = new Node(value);
		
		newNode->next = currentNode->next;
		currentNode->next = newNode;			
		newNode->previous = currentNode.GetValue();

		if (currentNode == tail) {
			tail = newNode;
		}
		numberOfNodes++;
	}
#pragma endregion

#pragma region Removal Methods

	//Remove the first element
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

			numberOfNodes--;
		}
	}

	//Remove the last element
	void PopBack() {
		if (IsEmpty()) {
			return;
		}
		if (tail != nullptr) {
			Node* temp = tail;

			if (tail->previous != nullptr) {
				tail->previous->next = nullptr;
			}

			tail = tail->previous;

			delete temp;

			numberOfNodes--;
		}
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
					numberOfNodes--;
					continue;
				}
				else if (i.GetValue() == tail) {
					previous->next = tail->next;
					delete tail;
					tail = previous.GetValue();
					numberOfNodes--;
					return;
				}
				else {
					previous->next = i->next;


					Node* temp = i.GetValue();
					++i;
					temp->next = nullptr;

					delete temp;
					numberOfNodes--;
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
#pragma endregion

#pragma region Return Values

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

	//Returns an Iterator to first position of list
	Iterator Begin() {
		return Iterator(head);
	}

	//Returns an Iterator to last position of list
	Iterator End() {
		return Iterator(tail->next);
	}

	int Count() {
		return numberOfNodes;
	}

	bool IsEmpty() {
		return head == nullptr;
	}

#pragma endregion


	void Clear() {
		delete head;
		numberOfNodes = 0;
		head = nullptr;
		tail = nullptr;
	}
};