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

void util::List::ReversoShowList()
{
	Node* cur = m_tail;
	for (size_t i = 0; i < this->m_size; i++, cur = cur->prev)
	{
		std::cout << cur->val << "\t";
	}
	std::cout << "\n";
}

size_t util::List::Size()
{
	return this->m_size;
}

void util::List::PushBack(int data)
{
	Node* newNode = new Node;
	newNode->val = data;
	
	if (m_size == 0)
	{
		m_head = m_tail = newNode;
	}
	else
	{
		m_tail->next = newNode;
		newNode->prev = m_tail;
		m_tail = newNode;
	}

	++this->m_size;
}

int util::List::PopBack()
{
	if (m_size == 0) // empty!!
	{
		std::cerr << "Unexpected operation - pop... ERROR.. list is empty!!\n";
		return -1;
	}
	
	int res = m_tail->val;

	Node* prevTail = m_tail->prev;
	if (prevTail != nullptr) // size != 1
	{
		prevTail->next = nullptr;
	}

	delete m_tail;
	m_tail = nullptr;
	m_tail = prevTail;
	--m_size;

	return res;
}

void util::List::Clear()
{
	Node* cur = m_head;
	Node* prev = nullptr;
	for (size_t i = 0; i < m_size; i++, cur = cur->next)
	{
		if (prev != nullptr)
		{
			//std::cout << prev->val << "# ";
			delete prev;
			prev = nullptr;
		}
		prev = cur;
	}
	if (prev != nullptr)
	{
		//std::cout << prev->val << "# ";
		delete prev;
		prev = nullptr;
	}
	m_size = 0;
	//std::cout << "\n";
}
