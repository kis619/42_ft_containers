#include <vector>
#include "ft_vector.hpp"
#include <map>
#include "ft_map.hpp"
#include <assert.h>
#define _ratio 1000


std::vector<int> copy_constructor_test(std::map<int, int> mp)
{

	std::vector<int> v;
	for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
		mp.insert(std::make_pair(i, j));
	}
	std::map<int, int> mp2(mp.begin(), mp.end());
	std::map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 30 * _ratio; ++i, it++) {
		// v.push_back(it->first);
		v.push_back(it->second);
	}
	return v;
}


std::vector<int> copy_constructor_test_mine(ft::map<int, int> mp)
{
	std::vector<int> v;

	for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
		mp.insert(ft::make_pair(i, j));
	}
	ft::map<int, int> mp2(mp.begin(), mp.end());
	ft::map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 30 * _ratio; ++i, it++) {
		// v.push_back(it->first);
		v.push_back(it->second);
	}
	return v;
}

int main()
{
	std::map<int, int> mappy;
	ft::map<int, int> mapty;
	std::vector<int> v = copy_constructor_test(mappy);
	std::vector<int> v1 = copy_constructor_test_mine(mapty);
	// for (int i = 0; i < v.size(); i++)
	// {
	// 	std::cout << v.at(i) << " ";
	// }
	// std::cout << "\n";
	// for (int i = 0; i < v1.size(); i++)
	// {
	// 	std::cout << v1.at(i) << " ";
	// }
	assert(v == v1);
	// copy_constructor_test();
}
