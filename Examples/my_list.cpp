#include "my_list.h"
#include <iostream>

my_list::my_list(node head) {
	m_head = &head;
	m_size = 1;
	node* current = &head;
	while (current->m_next != nullptr) {
		m_size += 1;
		current = current->m_next;
	}
	m_tail = current;
}

void my_list::push_back(double data) 
{
	m_tail->m_next = new node(data);
	m_tail = m_tail->m_next;
	m_size += 1;
}

void my_list::push_front(double data) 
{
	node* new_head = new node(data, m_head);
	m_head = new_head;
	m_size += 1;
}

double my_list::pop_back() 
{
	node* current = m_head;
	while (current->m_next->m_next != nullptr) {
		current = current->m_next;
	}
	double result = current->m_next->m_data;
	m_tail = current;
	current = current->m_next;
	m_tail->m_next = nullptr;
	delete current;
	m_size -= 1;
	return result;
}

double my_list::pop_front()
{
	double result = m_head->m_data;
	node* current = m_head;
	m_head = m_head->m_next;
	m_size -= 1;
	delete current;
	return result;
}

void my_list::add(size_t index, double data) {
	node* current = m_head;
	for (size_t i = 0; i < index - 1; i++) 
	{
		current = current->m_next;
	}
	node* new_node = new node(data, current->m_next);
	current->m_next = new_node;
}

double my_list::get(size_t index)
{
	node* current = m_head;
	for (size_t i = 0; i < index - 1; i++)
	{
		current = current->m_next;
	}
	node* to_delete = current->m_next;
	current->m_next = current->m_next->m_next;
	double result = to_delete->m_data;
	delete to_delete;
	return result;
}