#include <iostream>
#include <stdexcept>
#include "queue.h"

queue::queue(){
	back = front = nullptr;
	queue_size = 0;
}

queue::queue(const queue& q){
	back = front = nullptr;
	queue_size = 0;
	node* newnode = q.front;
	while(newnode != nullptr){
		push(newnode->value);
		newnode = newnode->next;
}
}

queue::queue(std::initializer_list<int> ilist){
	front = back = nullptr;
	queue_size = 0;
	for (size_t i:ilist){
		push(i);
	}
}

queue& queue::operator=(const queue& q){
	if(this != &q){
 		clear();
		for(node* newnode = q.front; newnode != nullptr; newnode = newnode->next){
			push(newnode->value);
		}
	}
	return *this;
}

void queue::push(int val){
	node* newnode = new node(val);

	if(queue_size == 0){
		front = newnode;
	}
	else{
		back->next = newnode;
	}
	back = newnode;
	++queue_size;
}

int queue::peek() const{
	if(queue_size == 0){
		throw std::invalid_argument("Queue is empty");
	}
	return front->value;
}

void queue::pop(){
	if(queue_size == 0){
		throw std::invalid_argument("Queue is empty");
	}
	else{
	node* newnode = front;
	front = front->next;
		if(front == nullptr){
			back == nullptr;
	}
	delete newnode;
	--queue_size;
	}
}

void queue::clear(){
	while (queue_size!=0){
		pop();
	}
}

size_t queue::size() const{
	return queue_size;
}

bool queue::empty() const{
	if(queue_size == 0){
		return true;
	}
	else{
		return false;
	}
}

void queue::merge (queue& x){
	if(this  != &x){
		if(queue_size == 0){
			this->front = x.front;
			this->back = x.back;
		}
		else{
			back->next = x.front;
			back = x.back;
		}
		queue_size += x.queue_size;
		x.queue_size = 0;
		x.front = x.back = nullptr;
}
}

queue::~queue(){ clear();}