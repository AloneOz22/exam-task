#pragma once

#include "node.h"

struct my_list 
{
	node* m_head;
	node* m_tail;
	size_t m_size;
	my_list() = delete;
	my_list(node head);
	void add(size_t index, double data);
	void push_back(double data);
	void push_front(double data);
	double get(size_t index);
	double pop_back();
	double pop_front();
	//~my_list();
	
};