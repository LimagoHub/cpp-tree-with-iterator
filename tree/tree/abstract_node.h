#pragma once
#include <ostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>

class Iterator;

class abstract_node 
{
	friend class Iterator;
	
	std::string name_;
	abstract_node* parent_;
	abstract_node * next_sibling() const;

public:

	
	#include "Iterator.h" // Include as inner class
	
	virtual ~abstract_node() = default;
	

	explicit abstract_node(std::string name = "undef");
	abstract_node(const abstract_node&) = delete;
	abstract_node& operator = (const abstract_node&) = delete;
	abstract_node(const abstract_node&&) = delete;
	abstract_node& operator = (const abstract_node&&) = delete;

	const virtual std::vector<abstract_node*>& get_children();
	Iterator begin();
	Iterator end();
	virtual void print(std::ostream& os) const;

	void set_name(const std::string& name);
	void set_parent(abstract_node* const parent);
	std::string get_name() const;
	abstract_node* get_parent() const;

	
	friend std::ostream& operator<<(std::ostream& os, const abstract_node& obj);


	friend bool operator==(const abstract_node& lhs, const abstract_node& rhs);

	friend bool operator!=(const abstract_node& lhs, const abstract_node& rhs);
};

