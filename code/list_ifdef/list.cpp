#include "list.h"

template<typename keyType>
_list<keyType>::_list(){
#ifdef HEAD
	head = new NODE();
#else
	head = NULL;
#endif
}

template<typename keyType>
_list<keyType>::~_list(){
	if (head) {
		PNODE move = head->next;
		while (move) {
			delete head;
			head = move;
		}
		delete head;
	}
}

#ifdef HEAD
template<typename keyType>
void _list<keyType>::push(keyType k){
	PNODE add = new NODE(k);
	add->next = head->next;
	head->next = add;
}
#else
template<typename keyType>
void _list<keyType>::push(keyType k){
	if (head) {
		PNODE add = new NODE(k);
		add->next = head;
		head = add;
	}
	else	//For the empty list
		head = new NODE(k);
}
#endif

#ifdef HEAD
template<typename keyType>
void _list<keyType>::pop(){
	if (head->next) {
		keyType k = head->next->k;
		PNODE tmp = head->next->next;
		delete head->next;
		head->next = tmp;
		cout << k <<"\n";
		return;
	}
	cout << "Empty!\n";
}
#else
template<typename keyType>
void _list<keyType>::pop(){
	if (head) {
		keyType k = head->k;
		PNODE tmp = head->next;
		delete head;
		head = tmp;
		cout << k << "\n";
		return;
	}
	cout << "Empty!\n";
}
#endif

template<typename keyType>
void _list<keyType>::show(){
#ifdef HEAD
	PNODE move = head->next;
#else
	PNODE move = head;
#endif
	cout << "\tLIST: ";
	if (move) {
		while (move) {
			cout << move->k << " ";
			move = move->next;
		}
		cout << endl;
		return;
	}
	cout << "Empty!\n";
	return;
}