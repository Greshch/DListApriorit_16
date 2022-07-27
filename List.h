#pragma once

namespace util
{
	struct Node
	{
		int val = 0;
		Node* prev = nullptr;
		Node* next = nullptr;
	};

	class List
	{
	private:
		Node* m_head = nullptr;
		Node* m_tail = nullptr;
		size_t m_size = 0;

	public:
		void ShowList();
		size_t Size();
		void PushBack(int data);
	};
}
