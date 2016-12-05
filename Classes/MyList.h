#ifndef _MYLIST_H_
#define _MYLIST_H_

template<class T>
class MyList {
public:
	MyList(){
		first = last = current = new Node();
	}
	~MyList(){}

public:
	class Node {
	public:
		T value;
		Node* next;
		Node* previous;
	public:
		Node(T value = T(), Node* previous = nullptr, Node* next = nullptr) {
			this->value = value;
			this->previous = previous;
			this->next = next;
		}
	};

public:
	void addItem(T value);
	T deleteItem();
	T restoreItem();

private:
	Node* first;	/* first node, do not restore data */
	Node* last;		/* restore last node  */
	Node* current;
};


template<class T>
void MyList<T>::addItem(T value) {
	if (last == first) {
		current = last = new Node(value, first);
		first->next = current;
	}else {
		while (current != last) {
			auto temp = last->previous;
			delete(last);
			last = temp;
			last->next = nullptr;
		}
		last = new Node(value, current);
		current->next = last;
		current = last;
	}
}

template<class T>
T MyList<T>::deleteItem() {
	if (current == first) {
		return T();
	}else {
		current = current->previous;
		return current->next->value;
	}
}

template<class T>
T MyList<T>::restoreItem() {
	if (current == last) {
		return T();
	}else {
		current = current->next;
		return current->value;
	}
}

#endif // MYLIST
