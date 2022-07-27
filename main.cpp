#include <iostream>
#include "List.h"

int main()
{
	const int szList = 5;
	util::List list;
	for (size_t i = 0; i < szList; i++)
	{
		list.PushBack(i);
	}

	list.ShowList();
	std::cout << "\nlist_sise = " << list.Size() << "\n\n";

	while (true) // it's a demonstration of PopBack's work
	{
		if (list.Size() == 0) // till list isn't empty
		{
			break;
		}
		std::cout << list.PopBack() << "\n";
	}

	std::cout << "\nlist_sise = " << list.Size() << "\n\n";

	list.ShowList();
	list.Clear();
	return 0;
}