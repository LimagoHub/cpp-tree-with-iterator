#pragma once
#include <algorithm>
#include <ostream>
#include <stack>
#include <string>
#include <vector>

class abstract_node 
{
	friend class Iterator;
	
	std::string name_;
	abstract_node* parent_;

	

	abstract_node * next_sibling() const;

public:

	
	#include "Iterator.h" // Include as inner class
	

	void ausgabe();
	
	
	virtual ~abstract_node() = default;

	explicit abstract_node(std::string name="undef")
		: name_(std::move(name)), parent_(nullptr)
	{
	}


	

	const virtual std::vector<abstract_node*>& get_children();
	Iterator begin();
	Iterator end();

	void set_name(const std::string& name)
	{
		name_ = name;
	}

	void set_parent(abstract_node* const parent)
	{
		parent_ = parent;
	}
	std::string get_name() const
	{
		return name_;
	}

	abstract_node* get_parent() const
	{
		return parent_;
	}

	

	
	virtual void print(std::ostream& os) const;
	
	friend std::ostream& operator<<(std::ostream& os, const abstract_node& obj)
	{
		obj.print(os);
		return os;
			
	}


	friend bool operator==(const abstract_node& lhs, const abstract_node& rhs)
	{
		return lhs.name_ == rhs.name_
			&& lhs.parent_ == rhs.parent_;
	}
	

	friend bool operator!=(const abstract_node& lhs, const abstract_node& rhs)
	{
		return !(lhs == rhs);
	}
};

