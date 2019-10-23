#include "set_linked_list.h"
	set::set (const set& q) {
		set_size = 0;
		head = nullptr;
		node *i = q.head;
		while(i != nullptr){
			insert(i->value);
			 i = i->next;
	}
}

	set::set (std::initializer_list<int> ilist){
		set_size = 0;
		head = nullptr;
		for(const auto& i : ilist){
		insert(i);
		}
	}

	set& set::operator=(const set& q){
		if (this == &q){
			return *this;
		}
		node* i = q.head;
		this->clear();
	while(i != nullptr){
		insert(i->value);
		i = i->next;
		}
		return *this;
	}

void set::insert (int val){
	
}

	set::node* set::find (int val){
		node *pointer = head;
		while(pointer != nullptr && pointer->value != val){
			pointer = pointer->next;
		}

		if(pointer != nullptr){
			return pointer;
		}
		else{
			return nullptr;
		}
	}

	void set::erase (node *it){
		node *nnode = it;

		if(set_size = 0 || nnode == nullptr  || head == nullptr){
			return;
		}

		if(nnode == head){
			head = head->next;
		}

		if(nnode->prev != nullptr){
			nnode->prev->next = nnode->next;
		}

		if(nnode->next != nullptr){
			nnode->next->prev = nnode->prev;
		}
		delete nnode;
		set_size--;
	}

	void set::clear(){
		node *pointer = head;

		while(pointer != nullptr){
			node *ptr = pointer->next;
			delete pointer;
			pointer = ptr;
		}
		set_size = 0;
		head = nullptr;
	}

	size_t set::size() const{
		return set_size;
	}

	bool set::empty() const{
		if(set_size == 0){
			return true;
		}
		else{
			return false;
		}
	}

	set::node* set::begin () const{
		return head;
	}

	set::~set(){
		while(head != nullptr){
			node* pointer = head;
			head = head->next;
			delete[] pointer;
		}
	}