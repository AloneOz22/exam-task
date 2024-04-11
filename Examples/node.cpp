#include "node.h"
#include <malloc.h>

node::node()
{
	m_data = 0.0;
	m_next = nullptr;
}

node::node(double data)
{
	m_data = data;
	m_next = nullptr;
}

node::node(double data, node* next)
{
	m_data = data;
	m_next = next;
}


node::~node() 
{
	m_next = nullptr;
}

