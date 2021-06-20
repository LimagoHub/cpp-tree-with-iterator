#include <algorithm>
#include <ostream>
#include <stack>
#include <string>
#include <vector>
#include "abstract_node.h"



	abstract_node* abstract_node::next_sibling() const
	{
		auto siblings = get_parent()->get_children();
		auto position = std::find(siblings.begin(), siblings.end(), this);
		return ++position != siblings.end() ? *position : nullptr;

	}

	const  std::vector<abstract_node*>& abstract_node::get_children()
	{
		static std::vector<abstract_node*> dummy{};
		return dummy;
	}

	abstract_node::Iterator abstract_node::begin()
	{
		return Iterator{ this };
	}

	abstract_node::Iterator abstract_node::end()
	{
		return Iterator{ nullptr };
	}


	void abstract_node::print(std::ostream& os) const
	{
		os << "name_: " << this->name_;
	}
	

