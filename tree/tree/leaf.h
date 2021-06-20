#pragma once
#include "abstract_node.h"


class leaf :
    public abstract_node
{
public:
	leaf(const std::string& name);

	void print(std::ostream& os) const override;
};

