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
	return 0;
}