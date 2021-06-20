#pragma once
#include <algorithm>
#include <ostream>
#include <stack>
#include <string>
#include <vector>

class abstract_node 
{
	std::string name_;
	abstract_node* parent_;

	

	abstract_node * next_sibling() const;

public:

	class Iterator : public std::iterator<
		std::input_iterator_tag,   // iterator_category
		abstract_node,                      // value_type
		abstract_node,                      // difference_type
		abstract_node*,						// pointer
		abstract_node                       // reference
	>
	{
	public:
		Iterator(abstract_node *current_node) : current_node_(current_node )
		{
			
		}

		
		abstract_node& operator*() const
		{
			return *current_node_;
		}


		

		Iterator& operator++()
		{
			
			if(try_find_most_left_child_and_move_iterator_succeeds()) return *this;

			if (try_find_next_sibling_and_move_iterator_succeeds()) return *this;
				
			while (try_find_next_sibling_of_parent_and_move_iterator_failes())
			{
				// Empty
			}
			
			return *this;
			
		}
		

	private:
		abstract_node *current_node_;
		std::stack<abstract_node *> stack_;


		

		bool try_find_most_left_child_and_move_iterator_succeeds ()
		{
			if(current_node_is_leaf()) return false;
			move_to_most_left_child();
			return true;
		}

		bool try_find_next_sibling_and_move_iterator_succeeds()
		{
			if (stack_.empty()) return false;
			return set_next_sibling_succeeds(current_node_);
		}

		

		bool try_find_next_sibling_of_parent_and_move_iterator_failes()
		{
			if (stack_.size() <= 1) return false;

			return !  set_next_sibling_succeeds(get_parent());
		}

		auto get_parent()-> abstract_node *
		{
			auto* parent = stack_.top();
			stack_.pop();
			return parent;
		}

		bool set_next_sibling_succeeds(abstract_node * node)
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
			if (lhs.current_node_ == nullptr && rhs.current_node_ == nullptr)
				return true;
				
			return lhs.current_node_ == rhs.current_node_;
				
		}

		friend bool operator!=(const Iterator& lhs, const Iterator& rhs)
		{
			return !(lhs == rhs);
		}
	};

	

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

