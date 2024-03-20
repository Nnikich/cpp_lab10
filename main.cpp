#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
	T data;
	Node<T>* prev, * next;
	Node(T data) {
		this->data = data;
		this->prev = this->next = NULL;
	}
};

template <typename T>
class List
{
public:
	Node<T>* head, * tail;
	int Size;
	List();
	~List();
	Node<T>* push_front(T data);
	Node<T>* push_back(T data);
	void pop_front();
	void pop_back();
	int GetSize(){ 
		return Size; 
	}
};

template <typename T>
List<T>::List(){
	head = tail = NULL;
}

template <typename T>
List<T>::~List(){
	while (head != NULL)
		pop_front();
}

template <typename T>
Node<T>* List<T>::push_front(T data){
	Node<T>* ptr = new Node<T>(data);
	ptr->next = head;
	if (head != NULL)
		head->prev = ptr;
	if (tail == NULL)
		tail = ptr;
	head = ptr;
	Size++;
	return ptr;
}

template <typename T>
Node<T>* List<T>::push_back(T data){
	Node<T>* ptr = new Node<T>(data);
	ptr->prev = tail;
	if (tail != NULL)
		tail->next = ptr;
	if (head == NULL)
		head = ptr;
	tail = ptr;
	Size++;
	return ptr;
}

template <typename T>
void List<T>::pop_front(){
	if (head == NULL) return;
	Node<T>* ptr = head->next;
	if (ptr != NULL)
		ptr->prev = NULL;
	else
		tail = NULL;
	Size--;
	delete head;
	head = ptr;
}

template <typename T>
void List<T>::pop_back(){
	if (tail == NULL) return;
	Node<T>* ptr = tail->prev;
	if (ptr != NULL)
		ptr->next = NULL;
	else
		head = NULL;
	Size--;
	delete tail;
	tail = ptr;
}

int main(){
	List<double> ListOne;
	ListOne.push_back(1.0);
	ListOne.push_front(2.0);
	ListOne.push_back(3.0);
	ListOne.push_front(4.0);
	ListOne.push_back(5.0);
	ListOne.push_front(6.0);
	ListOne.push_back(7.0);
	ListOne.push_front(8.0);
	for (Node<double>* ptr = ListOne.head; ptr != NULL; ptr = ptr->next)
		cout << ptr->data << ' ';
	cout << endl;
	cout << ListOne.GetSize() << endl;
	ListOne.pop_back();
	ListOne.pop_front();
	for (Node<double>* ptr = ListOne.head; ptr != NULL; ptr = ptr->next)
		cout << ptr->data << ' ';
	cout << endl;
	cout << ListOne.GetSize() << endl;

	List<string> ListTwo;
	ListTwo.push_back("a");
	ListTwo.push_front("a");
	ListTwo.push_back("b");
	ListTwo.push_front("b");
	ListTwo.push_back("c");
	ListTwo.push_front("c");
	ListTwo.push_back("d");
	ListTwo.push_front("d");
	for (Node<string>* ptr = ListTwo.head; ptr != NULL; ptr = ptr->next)
		cout << ptr->data << ' ';
	cout << endl;
	cout << ListTwo.GetSize() << endl;
	ListTwo.pop_back();
	ListTwo.pop_front();
	for (Node<string>* ptr = ListTwo.head; ptr != NULL; ptr = ptr->next)
		cout << ptr->data << ' ';
	cout << endl;
	cout << ListTwo.GetSize() << endl;
}
