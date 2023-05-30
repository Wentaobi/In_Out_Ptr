// in_out_ptr and out_ptr exist for compatibility
// between C++ smart pointers and C APIs
//#include <memory>
import std;

//extern "C"
//{
//	void get_data(int** ptr)
//	{
//		int* result = (int *)malloc(sizeof(int));
//		*result = 42;
//		*ptr = result;
//	}
//}

void old_c_api(int** p) {
	*p = new int{ 42 };
}


int main() {
	auto pi = std::make_shared<int>(51);

	// error C2338: static_assert failed: 'out_ptr_t with shared_ptr requires a deleter (N4892 [out.ptr.t]/3)'
	// old_c_api(std::out_ptr(pi));

	old_c_api(std::out_ptr(pi, std::default_delete<int>()));

	std::cout << *pi << '\n';
}

//int main1()
//{
//	//std::unique_ptr<int> a = std::make_unique<int>(1);
//	std::unique_ptr<int, decltype([](int* ptr) {free(ptr); })> a;
//	get_data(std::out_ptr(a));
//	std::cout << *a << std::endl;
//
//	return 0;
//}