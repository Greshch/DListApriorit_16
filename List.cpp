#include "List.h"
#include <iostream>

void util::List::ShowList()
{
	Node* cur = m_head;
	for (size_t i = 0; i < this->m_size; i++, cur = cur->next)
	{
		std::cout << cur->val << "\t";
	}
	std::cout << "\n";
}
