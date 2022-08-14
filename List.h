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
		List();
		List(size_t size, int val);
		List(List const& list);
		void ShowList() const;
		void ReversoShowList() const;
		size_t Size() const;
		void PushBack(int data);
		int PopBack();
		void Clear();
		~List();
	};
}
