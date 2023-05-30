import std;

int main()
{
	auto factorial = [](this auto&& self, int n)
		{
			if (n <= 1) return 1;
			return n * self(n - 1);
		};
	std::cout << std::format("{}", factorial(5)) << std::endl;
	return 0;
}