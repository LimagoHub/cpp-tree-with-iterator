#include <algorithm>
#include <ostream>

#include "node.h"



node::node(const std::string& name)
	: abstract_node(name)
{
}

void node::print(std::ostream& os) const 
{
	os << "Node: ";
	abstract_node::print(os);
}

const std::vector<abstract_node*>& node::get_children() 
{
	return children;
}

void node::append(abstract_node* child)
{
	children.push_back(child);
	child->set_parent(this);
}

void node::remove(abstract_node* child)
{
	const auto position = std::find(children.begin(), children.end(), child);
	if (position != children.end())
		children.erase(position);
}


