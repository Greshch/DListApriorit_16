#include "List.h"
#include <iostream>

util::List::List()
{
}

util::List::List(size_t size, int val)
{
	for (size_t i = 0; i < size; i++)
	{
		PushBack(val);
	}
}

util::List::List(List const& list)
{
	Node* cur = list.m_head;
	for (size_t i = 0; i < list.m_size; i++, cur = cur->next)
	{
		int val = cur->val;
		PushBack(val);
	}
}

void util::List::ShowList() const
{
	Node* cur = m_head;
	for (size_t i = 0; i < m_size; i++, cur = cur->next)
	{
		std::cout << cur->val << "\t";
	}
	std::cout << "\n";
}

void util::List::ReversoShowList() const
{
	Node* cur = m_tail;
	for (size_t i = 0; i < m_size; i++, cur = cur->prev)
	{
		std::cout << cur->val << "\t";
	}
	std::cout << "\n";
}

size_t util::List::Size() const
{
	return m_size;
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

	++m_size;
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

util::List::~List()
{
	Clear();
}
