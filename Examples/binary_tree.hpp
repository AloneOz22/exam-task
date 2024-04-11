#pragma once

#include <vector>

struct node 
{
	double m_data;
	node* m_left;
	node* m_right;
	node* m_parent;
	node();
	node(double data);
	node(node* parent, double data);
};

//  a == b
//	double eps = 1e-6;
//	fabs(a - b) < eps

struct binary_tree 
{
	node* m_root;
	binary_tree() = delete;
	binary_tree(node* root);
	void add(double data);
	bool search(double data);

	std::vector<double> to_vector();
};