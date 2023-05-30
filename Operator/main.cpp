import std;

struct T
{
	template <class...Args>
	auto operator [] (Args...args)
	{
		((std::cout << args << " "), ...);
		std::cout << "\n";
	}

	auto operator [] (size_t size)
	{
		std::cout << size << "\n";
	}

	template <class T>
	auto operator [] (std::initializer_list<T> init_list)
	{
		for (const auto& e : init_list)
		{
			std::cout << e << " ";
		}
		std::cout << "\n";
	}
};

int main()
{
	T t;
	t[1];
	t[{1, 2, 3, 4, 5}];
	t[{"*", "**", "***"}];
}