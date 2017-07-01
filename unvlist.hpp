#ifndef UNV_LIST
#define UNV_LIST
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class NodeBase {
public:
	NodeBase *left, *right;
	int data_type;
	void set_type(unsigned int value);
	void set_type(int value);
	void set_type(unsigned short value);
	void set_type(short value);
	void set_type(unsigned long value);
	void set_type(long value);
	void set_type(unsigned char value);
	void set_type(char value);
	void set_type(unsigned long long value);
	void set_type(long long value);
	void set_type(double value);
	void set_type(float value);
	void set_type(long double value);
	void set_type(string value);
	void set_type(bool value);
};

template <class T>
class Node : public NodeBase {
public:
	T key_value;
};

class unvlist {
private:
	NodeBase *front, *back;
	int length;

public:
	unvlist();
	template <class T>
	unvlist(const T* arr, int len);
	~unvlist();
	template <class T>
	void set(int n, const T& value);
	template <class T>
	T get(int n);
	template <class T>
	T insert(int n, const T& value);
	template <class T>
	T erase(int n);
	int size();
	void pop_back();
	void pop_front();
	template <class T>
	void push_back(const T& value);
	template <class T>
	void push_front(const T& value);
	unvlist operator+(unvlist& b);
	bool operator==(unvlist& b);
};

void NodeBase::set_type(unsigned int value) {
	data_type=1;
}
void NodeBase::set_type(int value) {
	data_type=2;
}
void NodeBase::set_type(unsigned short value) {
	data_type=3;
}
void NodeBase::set_type(short value) {
	data_type=4;
}
void NodeBase::set_type(unsigned long value) {
	data_type=5;
}
void NodeBase::set_type(long value) {
	data_type=6;
}
void NodeBase::set_type(unsigned char value) {
	data_type=7;
}
void NodeBase::set_type(char value) {
	data_type=8;
}
void NodeBase::set_type(unsigned long long value) {
	data_type=9;
}
void NodeBase::set_type(long long value) {
	data_type=10;
}
void NodeBase::set_type(double value) {
	data_type=11;
}
void NodeBase::set_type(float value) {
	data_type=12;
}
void NodeBase::set_type(long double value) {
	data_type=13;
}
void NodeBase::set_type(string value) {
	data_type=14;
}
void NodeBase::set_type(bool value) {
	data_type=15;
}

unvlist::unvlist() {
	front=NULL;
	back=NULL;
	length=0;
};

template <class T>
unvlist::unvlist(const T* arr, int len) {
	front=NULL;
	back=NULL;
	length=0;
	for(int i=0;i<len;i++) {
		this->push_back(arr[i]);
	}
};

unvlist::~unvlist() {
	while(length) {
		pop_back();
	}
};

template <class T>
void unvlist::set(int n, const T& value) {
	NodeBase *tmp=front;
	for(int i=0;i<n;i++) {
		tmp=tmp->right;
	}
	((Node<T>*)tmp)->key_value=value;
	tmp->set_type(value);
}

template <class T>
T unvlist::get(int n) {
	NodeBase *tmp=front;
	for(int i=0;i<n;i++) {
		tmp=tmp->right;
	}
	return ((Node<T>*)tmp)->key_value;
}

template <class T>
T unvlist::insert(int n, const T& value) {
	NodeBase *after, *tmp=front, *insert_node;
	if(n==0) {
		this->push_front(value);
		return value;
	}
	if(n==length) {
		this->push_back(value);
		return value;
	}
	for(int i=0;i<n-1;i++) {
		tmp=tmp->right;
	}
	insert_node=new Node<T>;
	after=tmp->right;
	((Node<T>*)insert_node)->key_value=value;
	insert_node->set_type(value);
	tmp->right=insert_node;
	insert_node->left=tmp;
	insert_node->right=after;
	after->left=insert_node;
	length++;
	return value;
}

template <class T>
T unvlist::erase(int n) {
	NodeBase *before, *tmp=front;
	T value;
	if(n==0) {
		value=((Node<T>*)front)->key_value;
		this->pop_front();
		return value;
	}
	if(n==(length-1)) {
		value=((Node<T>*)back)->key_value;
		this->pop_back();
		return value;
	}
	for(int i=0;i<n;i++) {
		tmp=tmp->right;
	}
	
	value=((Node<T>*)tmp)->key_value;	
	before=tmp->left;
	tmp=tmp->right;
	delete (tmp->left);
	before->right=tmp;
	tmp->left=before;
	length--;
	return value;
}

int unvlist::size() {
	return length;
}

void unvlist::pop_back() {
	length--;
	if(front==back) {
		delete front;
		front=NULL;
		back=NULL;
	}
	else {
		back=back->left;
		delete (back->right);
		back->right=NULL;
	}
}

void unvlist::pop_front() {
	length--;
	if(front==back) {
		delete back;
		front=NULL;
		back=NULL;
	}
	else {
		front=front->right;
		delete (front->left);
		front->left=NULL;
	}
}

template <class T>
void unvlist::push_back(const T& value) {
	length++;
	if(back==NULL) {
		back=new Node<T>;
		((Node<T>*)back)->key_value=value;
		back->set_type(value);
		back->left=NULL;
		back->right=NULL;
		front=back;
	}
	else {
		back->right=new Node<T>;
		((Node<T>*)back->right)->key_value=value;
		back->right->set_type(value);
		back->right->right=NULL;
		back->right->left=back;
		back=back->right;
	}
}

template <class T>
void unvlist::push_front(const T& value) {
	length++;
	if(front==NULL) {
		front=new Node<T>;
		((Node<T>*)front)->key_value=value;
		front->set_type(value);
		front->left=NULL;
		front->right=NULL;
		back=front;
	}
	else {
		front->left=new Node<T>;
		((Node<T>*)front->left)->key_value=value;
		front->left->set_type(value);
		front->left->left=NULL;
		front->left->right=front;
		front=front->left;
	}
}

unvlist unvlist::operator+(unvlist& b) {
	unvlist list;
	list.front=NULL;
	list.back=NULL;
	list.length=0;
	NodeBase *tmp;
	int length=this->size();
	if(length!=0) tmp=this->front;
	else tmp=b.front;
	length+=b.size();
	for(int i=0;i<length;i++) {
		switch(tmp->data_type) {
			case 1:
				list.push_back<unsigned int>(((Node<unsigned int>*)tmp)->key_value);
				break;
			case 2:
				list.push_back<int>(((Node<int>*)tmp)->key_value);
				break;
			case 3:
				list.push_back<unsigned short>(((Node<unsigned short>*)tmp)->key_value);
				break;
			case 4:
				list.push_back<short>(((Node<short>*)tmp)->key_value);
				break;
			case 5:
				list.push_back<unsigned long>(((Node<unsigned long>*)tmp)->key_value);
				break;
			case 6:
				list.push_back<long>(((Node<long>*)tmp)->key_value);
				break;
			case 7:
				list.push_back<unsigned char>(((Node<unsigned char>*)tmp)->key_value);
				break;
			case 8:
				list.push_back<char>(((Node<char>*)tmp)->key_value);
				break;
			case 9:
				list.push_back<unsigned long long>(((Node<unsigned long long>*)tmp)->key_value);
				break;
			case 10:
				list.push_back<long long>(((Node<long long>*)tmp)->key_value);
				break;
			case 11:
				list.push_back<double>(((Node<double>*)tmp)->key_value);
				break;
			case 12:
				list.push_back<float>(((Node<float>*)tmp)->key_value);
				break;
			case 13:
				list.push_back<long double>(((Node<long double>*)tmp)->key_value);
				break;
			case 14:
				list.push_back<string>(((Node<string>*)tmp)->key_value);
				break;
			case 15:
				list.push_back<bool>(((Node<bool>*)tmp)->key_value);
				break;
		}
		if(b.size()==0 && tmp==this->back) continue;
		else if(this->size()!=0 && tmp==this->back) tmp=b.front;
		else if(tmp==b.back) continue;
		else tmp=tmp->right;
	}
	return list;
}

bool unvlist::operator==(unvlist& b) {
	if(this->size()!=b.size()) return false;
	NodeBase *tmp_a=this->front, *tmp_b=b.front;
	for(int i=0;i<this->size();i++) {
		if(tmp_a->data_type!=tmp_b->data_type) return false;
		switch(tmp_a->data_type) {
			case 1:
				if(((Node<unsigned int>*)tmp_a)->key_value!=((Node<unsigned int>*)tmp_b)->key_value) return false;
				break;
			case 2:
				if(((Node<int>*)tmp_a)->key_value!=((Node<int>*)tmp_b)->key_value) return false;
				break;
			case 3:
				if(((Node<unsigned short>*)tmp_a)->key_value!=((Node<unsigned short>*)tmp_b)->key_value) return false;
				break;
			case 4:
				if(((Node<short>*)tmp_a)->key_value!=((Node<short>*)tmp_b)->key_value) return false;
				break;
			case 5:
				if(((Node<unsigned long>*)tmp_a)->key_value!=((Node<unsigned long>*)tmp_b)->key_value) return false;
				break;
			case 6:
				if(((Node<long>*)tmp_a)->key_value!=((Node<long>*)tmp_b)->key_value) return false;
				break;
			case 7:
				if(((Node<unsigned char>*)tmp_a)->key_value!=((Node<unsigned char>*)tmp_b)->key_value) return false;
				break;
			case 8:
				if(((Node<char>*)tmp_a)->key_value!=((Node<char>*)tmp_b)->key_value) return false;
				break;
			case 9:
				if(((Node<unsigned long long>*)tmp_a)->key_value!=((Node<unsigned long long>*)tmp_b)->key_value) return false;
				break;
			case 10:
				if(((Node<long long>*)tmp_a)->key_value!=((Node<long long>*)tmp_b)->key_value) return false;
				break;
			case 11:
				if(((Node<double>*)tmp_a)->key_value!=((Node<double>*)tmp_b)->key_value) return false;
				break;
			case 12:
				if(((Node<float>*)tmp_a)->key_value!=((Node<float>*)tmp_b)->key_value) return false;
				break;
			case 13:
				if(((Node<long double>*)tmp_a)->key_value!=((Node<long double>*)tmp_b)->key_value) return false;
				break;
			case 14:
				if(((Node<string>*)tmp_a)->key_value!=((Node<string>*)tmp_b)->key_value) return false;
				break;
			case 15:
				if(((Node<bool>*)tmp_a)->key_value!=((Node<bool>*)tmp_b)->key_value) return false;
				break;
		}
		if(tmp_a->right!=NULL) {
			tmp_a=tmp_a->right;
			tmp_b=tmp_b->right;
		}
	}
	return true;
}
#endif
