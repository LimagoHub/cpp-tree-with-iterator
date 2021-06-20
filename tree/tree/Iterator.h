#pragma once
#include <algorithm>
#include <iterator>
#include <stack>
#include "abstract_node.h"


// as inner class in abstract_node.h
class Iterator : public std::iterator<
		std::input_iterator_tag,   // iterator_category
		abstract_node,                      // value_type
		abstract_node,                      // difference_type
		abstract_node*,						// pointer
		abstract_node                       // reference
	>
{
public:
	Iterator(abstract_node* current_node) : current_node_(current_node)
	{

	}


	abstract_node& operator*() const
	{
		return *current_node_;
	}




	Iterator& operator++()
	{

		if (find_most_left_child_and_move_iterator_succeeds()) return *this;

		if (find_next_sibling_and_move_iterator_succeeds()) return *this;

		while (find_next_sibling_of_ancestor_and_move_iterator_failes())
		{
			// Empty
		}

		return *this;

	}


private:
	abstract_node* current_node_;
	std::stack<abstract_node*> stack_;




	bool find_most_left_child_and_move_iterator_succeeds()
	{
		if (current_node_is_leaf()) return false;
		move_to_most_left_child();
		return true;
	}

	bool find_next_sibling_and_move_iterator_succeeds()
	{
		if (stack_.empty()) return false;
		return set_next_sibling_succeeds(current_node_);
	}



	bool find_next_sibling_of_ancestor_and_move_iterator_failes()
	{
		if (stack_.size() <= 1) return false;

		return !set_next_sibling_succeeds(get_parent());
	}

	auto get_parent()-> abstract_node*
	{
		auto* parent = stack_.top();
		stack_.pop();
		return parent;
	}

	bool set_next_sibling_succeeds(abstract_node* node)
	{
		return current_node_ = node->next_sibling(); // Set current_node to "End" if failes (nullptr)
	}




	void move_to_most_left_child()
	{
		stack_.push(current_node_);
		current_node_ = current_node_->get_children()[0];

	}

	bool current_node_is_leaf() const
	{
		return current_node_->get_children().empty();
	}

	friend bool operator==(const Iterator& lhs, const Iterator& rhs)
	{
		return lhs.current_node_ == rhs.current_node_;

	}

	friend bool operator!=(const Iterator& lhs, const Iterator& rhs)
	{
		return !(lhs == rhs);
	}
};
