#pragma once

struct node
{
	double m_data;
	node* m_next;
	node();
	node(double data);
	node(double data, node* next);
	~node();
};