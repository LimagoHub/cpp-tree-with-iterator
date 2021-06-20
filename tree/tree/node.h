#pragma once

#include "abstract_node.h"

class node :
    public abstract_node
{
	std::vector<abstract_node*> children;

public:

	node(const std::string& name);
	void print(std::ostream& os) const override;

	const std::vector<abstract_node*>& get_children() override;

	void append(abstract_node* child);

	void remove(abstract_node* child);

};

