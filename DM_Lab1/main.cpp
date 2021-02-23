#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <String>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void printMenu();


template <typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	int getSize() { return size; }
	T& operator[] (const int index);
private:

	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node <T> *head;
};
template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}
template <typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == nullptr)
		head = new Node <T>(data);
	else {
		Node <T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template <typename T>
T & List<T>::operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) 
			return current->data;
		current = current->pNext;
		counter++;
	}
}
List<string> setReading() {
	List<string> set;
	string elem = "" ;
	while (getch()!=27) {
		getline(cin, elem);
		set.push_back(elem);
	}
	printMenu();
	return set;
}
void Opt11() {
	cout << "Enter the elements separating them by 'ENTER'\n";
	cout << "If you've entered what you wanted to - press 'ESC' - it will open the menu\n";
	setReading();
}
void Opt1() {
	int option;
	cout << "To create a set - press '1'\n";
	cout << "To go back to the menu - press '2'\n";
	cin >> option;
	switch (option) {
	case 1: 
		Opt11();
		break;
	case 2:
	    printMenu();
		break;
	default: 
		return;
	}
}
void Opt2() {

}
void printMenu() {
	int option;
	cout << "             ------   \n";
	cout << "            | Menu |\n";
	cout << "             ------\n";
	cout << "To create a set - press '1' \n";
	cout << "To see what sets already exist - press '2'\n";
	cout << "To logout - press '3'\n";
	cin >> option;
	switch (option) {
	case 1:
		Opt1();
		break;
		/*case 2:
			Opt2();
			break;
		case 3:
			Opt3();
			break;
		default:
			return;
		}*/
	}
	return;
}


int main(void) {
	printMenu();
	//setReading();
	return 0;

}