#pragma once

#include "binary_tree.hpp"

node::node() 
{
	m_data = 0;
	m_parent = nullptr;
	m_left = nullptr;
	m_right = nullptr;
}

node::node(double data) 
{
	m_data = data;
	m_parent = nullptr;
	m_left = nullptr;
	m_right = nullptr;
}

bool binary_tree::search(double data) 
{
	return true;
}