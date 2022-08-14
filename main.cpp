#include <iostream>
#include "List.h"

int main()
{
	const int len = 5;
	util::List list_1;
	for (size_t i = 0; i < len; i++)
	{
		list_1.PushBack(i + 1);
	}
	list_1.ShowList();
	util::List list_2(list_1);
	list_2.ShowList();
	return 0;
}