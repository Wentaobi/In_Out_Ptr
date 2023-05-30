import std;

// auto{} and auto() just create a copy of value

auto copy(const auto& value)
{
	return value;
}

static void erase_first(auto& container)
{
	std::erase(container, copy(container.front()));
	//std::erase(container, auto{container.front()});
}


int main()
{
	std::vector<std::string> strs{ "test3", "test3", "hello" , "test", "test3"};
	erase_first(strs);

	for (const auto& e : strs)
	{
		std::cout << e << std::endl;
	}

	return 0;
}