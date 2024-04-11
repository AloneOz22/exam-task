#include "my_list.h"
#include <iostream>

int main2() {
	node my_head(5.0);
	my_list list(my_head);
	list.push_back(7.3);
	list.push_back(3.2);
	list.add(1, 44.67);
	std::cout << list.get(1) << std::endl;
	node* current = list.m_head;
	std::cout << current->m_data << " ";
	size_t size = 0;
	while (current->m_next != nullptr) 
	{
		current = current->m_next;
		std::cout << current->m_data << " ";
		size++;
	}
	return 0;
}
