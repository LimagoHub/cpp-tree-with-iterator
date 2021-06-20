#include <algorithm>
#include <ostream>
#include <string>
#include <vector>
#include "abstract_node.h"


abstract_node::abstract_node(std::string name)
	: name_(std::move(name)), parent_(nullptr)
{
}

abstract_node* abstract_node::next_sibling() const
{
	auto siblings = get_parent()->get_children();
	auto position = std::find(siblings.begin(), siblings.end(), this);
	return ++position != siblings.end() ? *position : nullptr;

}

void abstract_node::set_name(const std::string& name)
{
	name_ = name;
}

void abstract_node::set_parent(abstract_node* const parent)
{
	parent_ = parent;
}

std::string abstract_node::get_name() const
{
	return name_;
}

abstract_node* abstract_node::get_parent() const
{
	return parent_;
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

std::ostream& operator<<(std::ostream& os, const abstract_node& obj)
{
	obj.print(os);
	return os;

}

bool operator==(const abstract_node& lhs, const abstract_node& rhs)
{
	return lhs.name_ == rhs.name_
		&& lhs.parent_ == rhs.parent_;
}

bool operator!=(const abstract_node& lhs, const abstract_node& rhs)
{
	return !(lhs == rhs);
}

