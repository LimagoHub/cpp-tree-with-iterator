#include "leaf.h"

leaf::leaf(const std::string& name)
	: abstract_node(name)
{
}

void leaf::print(std::ostream& os) const 
{
	os << "Leaf: ";
	abstract_node::print(os);
}