// let non-static member function's this be explicit
// this key word can't be used in the member function
import std;
struct X_before23
{
	int f(int arg)
	{
		using T = decltype(*this); // X &
		return v + arg;
	}

	int f(int arg) const
	{
		using T = decltype(*this); // const X &
		return v + arg;
	}

	int v = 0;
};

struct X_23
{
	int f(this X_23* self, int arg)
	{
		std::cout << "copy overloading function" << std::endl;
		return self->v + arg;
	}

	//int f(this auto&& self, int arg)
	//{
	//	std::cout << "auto&& universal reference" << std::endl;
	//}

	int f(this X_23& self, int arg) 
	{
		std::cout << "reference overloading function" << std::endl;
		return self.v + arg;
	}

	int f(this const X_23& self, int arg)
	{
		std::cout << "const reference overloading function" << std::endl;
		return self.v + arg;
	}

	int v = 0;
};

int main()
{
	X_before23 x;
	x.f(1);

	const X_23 x23_const;
	x23_const.f(1);

	X_23 x23;
	x23.f(1);

	X_23* x23_ptr{nullptr};
	x23_ptr->f(1);

	return 0;
}