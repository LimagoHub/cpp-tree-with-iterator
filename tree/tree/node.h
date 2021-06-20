#pragma once
#include <algorithm>
#include "abstract_node.h"

class node :
    public abstract_node
{
	std::vector<abstract_node*> children;

public:

	node(const std::string& name)
		: abstract_node(name)
	{
	}
	void print(std::ostream& os) const override
	{
		os << "Node: ";
		abstract_node::print(os);
	}

	const std::vector<abstract_node*>& get_children() override
	{
		return children;
	}

	void append(abstract_node *child)
	{
		children.push_back(child);
		child->set_parent(this);
	}

	void remove(abstract_node* child)
	{
		const auto position = std::find(children.begin(), children.end(), child);
		if (position != children.end())
			children.erase(position);
	}


};

