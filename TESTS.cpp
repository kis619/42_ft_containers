#include <vector>
#include "ft_vector.hpp"
#include <map>
#include "ft_map.hpp"
#include <assert.h>
#define _ratio 1000

// std::vector<int> lower_bound_test(std::map<int, int> mp) {
//     std::vector<int> v;
//     std::map<int, int, std::greater<int> > mp2;
//     mp.insert(std::make_pair(10, 10));
//     mp2.insert(std::make_pair(10, 10));
//     if (mp.lower_bound(11) == mp.end())
//         v.push_back(1);
//     if (mp2.lower_bound(1) == mp2.end())
//         v.push_back(1);
//     mp.insert(std::make_pair(20, 20));
//     mp.insert(std::make_pair(30, 30));
//     mp.insert(std::make_pair(40, 40));
//     mp.insert(std::make_pair(50, 50));
//     mp.insert(std::make_pair(60, 60));
//     mp2.insert(std::make_pair(20, 20));
//     mp2.insert(std::make_pair(30, 30));
//     mp2.insert(std::make_pair(40, 40));
//     mp2.insert(std::make_pair(50, 50));
//     mp2.insert(std::make_pair(60, 60));
//     std::map<int, int>::iterator it;
//     for (int i = 1; i < 60; i += 10) {
//         it = mp.lower_bound(i);
//         v.push_back(it->first);
//     }
//     for (int i = 11; i < 70; i += 10) {
//         it = mp2.lower_bound(i);
//         v.push_back(it->first);
//     }
//     std::map<int, int> mp3;
//     for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
//         mp3.insert(std::make_pair(i, j));
//     }
//     mp3.lower_bound(49 * _ratio);
//     return v;
// }

// std::vector<int> lower_bound_test_mine(ft::map<int, int> mp) {
//     std::vector<int> v;
//     ft::map<int, int, std::greater<int> > mp2;
//     mp.insert(ft::make_pair(10, 10));
//     mp2.insert(ft::make_pair(10, 10));
//     if (mp.lower_bound(11) == mp.end())
//         v.push_back(1);
//     if (mp2.lower_bound(1) == mp2.end())
//         v.push_back(1);
//     mp.insert(ft::make_pair(20, 20));
//     mp.insert(ft::make_pair(30, 30));
//     mp.insert(ft::make_pair(40, 40));
//     mp.insert(ft::make_pair(50, 50));
//     mp.insert(ft::make_pair(60, 60));
//     mp2.insert(ft::make_pair(20, 20));
//     mp2.insert(ft::make_pair(30, 30));
//     mp2.insert(ft::make_pair(40, 40));
//     mp2.insert(ft::make_pair(50, 50));
//     mp2.insert(ft::make_pair(60, 60));
//     ft::map<int, int>::iterator it;
//     for (int i = 1; i < 60; i += 10) {
//         it = mp.lower_bound(i);
//         v.push_back(it->first);
//     }
//     for (int i = 11; i < 70; i += 10) {
//        it = mp2.lower_bound(i);
//         v.push_back(it->first);
//     }
//     ft::map<int, int> mp3;
//     for (int i = 0, j = 0; i < 50 * _ratio; ++i, ++j) {
//         mp3.insert(ft::make_pair(i, j));
//     }
//     mp3.lower_bound(49 *_ratio);
//     return v;
// }

// int main()
// {
// 	std::map<int, int> ogft::map;
// 	std::vector<int> v1 = lower_bound_test(ogft::map);

// 	ft::map<int, int> myft::map;	
// 	std::vector<int> v2 = lower_bound_test_mine(myft::map);
// }
template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 9));
	mp.insert(std::make_pair(8, 8));
	mp.insert(std::make_pair(23, 7));
	mp.insert(std::make_pair(7, 6));
	mp.insert(std::make_pair(19, 5));
	mp.insert(std::make_pair(29, 4));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 2));
	mp.insert(std::make_pair(11, 1));
}

template <class T, class V, class C>
void fillMap2(ft::map<T, V, C> &mp) {
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

std::vector<int> comparator_test(std::map<int, int> mp) {

    std::vector<int> v;
    // fillMap(mp);
    // for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::greater<int> > mp1;
    // fillMap(mp1);
    // v.push_back(mp1.begin()->first);
    // mp1.erase(41);
    // v.push_back(mp1.begin()->first);
    // mp1.erase(29);
    // v.push_back(mp1.begin()->first);
    // std::map<int, int, std::greater<int> > mp2;
    // mp2.insert(std::make_pair(3, 3));
    // v.push_back(mp2.begin()->first);
    // mp2.erase(3);
    // if (mp2.begin() == mp2.end())
    //     v.push_back(1);
    std::map<int, int, std::plus<int> > mp3;
    mp3.insert(std::make_pair(300, 300));
    std::cout << mp3.at(300);
    fillMap(mp3);
    for (std::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) 
    {
         std::cout<< it->first << " " << it->second << "\n";
         v.push_back(it->first);
    }
  std::cout << "FIrst " << mp3.begin()->first << std::endl;
    // for (std::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::minus<int> > mp4;
    // fillMap(mp4);
    // for (std::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::greater_equal<int> > mp5;
    // fillMap(mp5);
    // for (std::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::multiplies<int> > mp6;
    // fillMap(mp6);
    // for (std::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::bit_xor<int> > mp7;
    // fillMap(mp7);
    // for (std::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::logical_and<int> > mp8;
    // fillMap(mp8);
    // for (std::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    // v.push_back(mp1.size());
    // std::cout<< mp3.at(16) <<std::endl;
    // std::cout<< mp3.at(4) <<std::endl;
    // std::cout<< mp3.at(41) <<std::endl;
    // std::cout<< mp3.at(29) <<std::endl;
    // std::cout<< mp3.at(19) <<std::endl;
    // std::cout<< mp3.at(11) <<std::endl;
    // std::cout<< mp3.at(23) <<std::endl;
    // std::cout<< mp3.at(8) <<std::endl;
    
    return v;
}

std::vector<int> comparator_test_mine(ft::map<int, int> mp) {
    std::vector<int> v;
    // fillMap2(mp);
    // int i = 0;
    // for (ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) 
    // { 
    //     std::cout << it -> first << " " << it->second << std::endl;
    //     v.push_back(it->first);
    // }
    // std::cout << "After first loop\n";
    // for (ft::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) 
    // { 
    //     std::cout << it -> first << " " << it->second << std::endl;
    //     v.push_back(it->first);
    // }
    // std::cout << "After second loop\n";
    // ft::map<int, int, std::greater<int> > mp1;
    // fillMap2(mp1);
    // v.push_back(mp1.begin()->first);
    // mp1.erase(41);
    // v.push_back(mp1.begin()->first);
    // mp1.erase(29);
    // v.push_back(mp1.begin()->first);
    // ft::map<int, int, std::greater<int> > mp2;
    // mp2.insert(ft::make_pair(3, 3));
    // v.push_back(mp2.begin()->first);
    // std::cout << mp2.begin()->first << std::endl;
    // mp2.erase(3);
    // if (mp2.begin() == mp2.end())
    //     v.push_back(1);
    ft::map<int, int, std::plus<int> > mp3;
    fillMap2(mp3);
    // std::cout << "After fill with plus\n";
    // std::cout << mp3.begin()->first;
    // std::cout << mp3.begin()->first << std::endl;
    // std::cout<< mp3.at(16) <<std::endl;
    // std::cout<< mp3.at(4) <<std::endl;
    // std::cout<< mp3.at(41) <<std::endl;
    // std::cout<< mp3.at(29) <<std::endl;
    // std::cout<< mp3.at(19) <<std::endl;
    // std::cout<< mp3.at(7) <<std::endl;
    // std::cout<< mp3.at(23) <<std::endl;
    // std::cout<< mp3.at(8) <<std::endl;
    // std::cout<< mp3.at(16) <<std::endl;
    for (ft::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++)
    { 
        std::cout <<it->first << std::endl;
        // v.push_back(it->first); 
    }
    std::cout << "After loop with plus\n";
    // for (ft::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::minus<int> > mp4;
    // fillMap2(mp4);
    // for (ft::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
    // for (ft::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::greater_equal<int> > mp5;
    // fillMap2(mp5);
    // for (ft::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
    // for (ft::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::multiplies<int> > mp6;
    // fillMap2(mp6);
    // for (ft::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
    // for (ft::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
    // ft::map<int, int, std::bit_xor<int> > mp7;
    // fillMap2(mp7);
    // for (ft::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
    // for (ft::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
    // std::map<int, int, std::logical_and<int> > mp8;
    // fillMap2(mp8);
    // for (std::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
    // for (std::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
    // v.push_back(mp1.size());

    return v;
}

int main(void)
{
    // ft::map<int, int> my_map;
    // std::map<int, int> og_map;
    // std::vector<int> v = comparator_test_mine(my_map);
    // // std::vector<int> v = comparator_test(og_map);
    // std::cout << "here\n";

    std::map<int, int>::iterator it;
}