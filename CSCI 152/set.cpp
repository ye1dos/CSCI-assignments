#include "set.h"

// Case insensitive string equality
bool equal(const std::string& s1, const std::string& s2){
	if(s1.length() == s2.length()){
		size_t i = 0;
		while(i<s1.length()){
			if (tolower(s1[i]) != tolower(s2[i])){
				return false;
			}
			i++;
		}
		return true;
	}
	return false;
}

size_t hash(const std::string& s){

	size_t nn = 0;
	char ch;
	for(int j = 0; s[j] != '\0'; j++){
		ch = tolower(s[j]);
		nn = 60*nn + ch;
		}
	return nn;
	}

set::set(const set& s){
	bucket_array = new std::list<std::string>[s.bucket_array_size];
	bucket_array_size = s.bucket_array_size;
	set_size = s.set_size;
	int i = 0;
	while(i < bucket_array_size){
		bucket_array[i] = s.bucket_array[i];
		i++;
		}
	}

	// Initializer list constructor
set::set(std::initializer_list<std::string> ilist):
	bucket_array(new std::list<std::string>[4]),
		bucket_array_size(4),
		set_size(0)
{
	for (auto val: ilist) insert(val);
}
	// Copy assignment
set& set::operator=(const set& s){
	if(this != &s) {
		clear();
		delete[] bucket_array;
		bucket_array_size = s.bucket_array_size; 
		set_size = s.set_size; 
		bucket_array = new std::list<std::string>[bucket_array_size];
		int i = 0;
		while(i < bucket_array_size){
			bucket_array[i] = s.bucket_array[i];
			i++;	
	}
}
	return *this;
}

bool set::insert(std::string val){
	if(contains(val)) 
		return false;
	else{
		size_t qq = hash(val)%bucket_array_size;
		bucket_array[qq].push_back(val);
	if (max_load_factor<loadfactor()){
		std::list <std::string>* ext = new std::list<std::string>[2*bucket_array_size];
		for(size_t i =0; i < bucket_array_size; i++){
			for (auto j:bucket_array[i]) {
				ext[hash(j)%(2*bucket_array_size)].push_back(j);
			}
		}
		size_t nn = set_size;
		clear();
		delete[] bucket_array;
		bucket_array = ext;
		set_size = nn;
		bucket_array_size = 2*bucket_array_size;
	}
	set_size++;
	return true;
	}
}

bool set::contains(std::string val) const{
	for(auto qq = bucket_array[hash(val)%bucket_array_size].begin();
	 qq != bucket_array[hash(val)%bucket_array_size].end(); qq++){
	if(equal (val, *qq)){
			return true;
		}
	}
	return false;
}

bool set::remove(std::string val){
	for(auto qq = bucket_array[hash(val)%bucket_array_size].begin();
		qq != bucket_array[hash(val)%bucket_array_size].end(); qq++){
		if(equal (val, *qq)){
			bucket_array[hash(val)%bucket_array_size].erase(qq);
			set_size--;
			return true;
		}
	}
	return false;
}

void set::clear(){
	for(size_t i = 0; i < bucket_array_size; i++){
		bucket_array[i].clear();
	}
		set_size = 0;
}

size_t set::size() const{
	return set_size;
}

bool set::empty() const{
	return set_size == 0;
	}
set::~set(){
    clear();
    delete [] bucket_array;
}