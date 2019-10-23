#include <iostream>
#include<stdexcept>
#include "stack.h"

stack::stack(const stack& stk){
	array_capacity = stk.array_capacity;
	stack_size = stk.stack_size;
	values = new int[stk.array_capacity];

	for(size_t i = 0; i < stk.stack_size; i++){
		values[i] = stk.values[i];
	}
}

stack::stack(std::initializer_list<int> ilist){
	int j = 0;
	stack_size = ilist.size();
	array_capacity = (2*stack_size);
	values = new int[stack_size];
	for (int i:ilist){
	values[j] = i;
	j++;
	}


}

stack& stack::operator=(const stack& stk){
	array_capacity = stk.array_capacity;
	stack_size = stk.stack_size;
	values = new int[stk.stack_size];
	for (size_t i = 0; i < stk.stack_size; i++){
		values[i] = stk.values[i];
	}
	return *this;
}	

void stack::push(int val){
	int *mem = new int[array_capacity];
	if(stack_size == array_capacity){
		array_capacity = 2*array_capacity;
	}
	for(size_t i=0;i<stack_size;i++){
		mem[i]=values[i];
	}
	delete[] values;
	values = mem;
    values[stack_size] = val;
	stack_size++;
}

int stack::peek() const {
	if(stack_size==0){
		throw std::invalid_argument("Empty Stack"); 
}
	int x = values[stack_size-1];
	return x;
}

void stack::pop(){
	if(stack_size==0){
		throw std::invalid_argument("Empty Stack"); 
}
	stack_size--;
}

void stack::clear(){
	stack_size = 0;
}

size_t stack::size() const{
	return stack_size;
}

bool stack::empty() const{
	return (stack_size==0);
}

stack::~stack(){
delete[] values;
}