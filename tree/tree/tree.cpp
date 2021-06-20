#include <iostream>
#include <algorithm>
#include "leaf.h"
#include "node.h"



int main()
{
	leaf leaf1_{"Hallo"};
	leaf leaf2_{ "Welt" };
	leaf leaf3_{ "Hello" };
	leaf leaf4_{ "World" };
	leaf leaf5_{ "Hi" };
	leaf leaf6_{ "Frankfurt" };
	leaf leaf7_{ "one" };
	leaf leaf8_{ "two" };
	leaf leaf9_{ "three" };
	
	node root{ "root" };

	node e1{ "e1" };
	node e1_1{ "e1_1" };
	node e2{ "e2" };

	root.append(&e1);
	root.append(&e2);

	e1.append(&e1_1);
	e1.append(&leaf1_);
	e1.append(&leaf2_);
	e1.append(&leaf5_);
	e1.append(&leaf6_);

	e2.append(&leaf3_);
	e2.append(&leaf4_);

	e1_1.append(&leaf7_);
	e1_1.append(&leaf8_);
	e1_1.append(&leaf9_);

	for(auto it = root.begin(); it != root.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << std::endl;
	
	std::for_each(root.begin(), root.end(), [](const abstract_node& node) {std::cout << node << std::endl; });

	std::cout << std::endl << std::endl;
	
	for (auto &item: root)
	{
		item.set_name("Hallo: " + item.get_name());
		std::cout << item << std::endl;
	}
	
	
	
	

	
	
}
