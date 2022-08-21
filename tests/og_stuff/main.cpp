/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:42:40 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/11 12:14:12 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
T add(T a, T b)
{
	return (a + b);
}

template <typename T, typename U>
bool are_equal(T a, U b)
{
	return (a == b);
}

template <typename T, int N>
T fixed_multiply(T a)
{
	return (a * N);
}

class Whatever
{
	
	public:
		int a;
		Whatever(int);
};

Whatever::Whatever(int b)
{
	this->a = b;
}
// int main(int argc, char **argv, char **env)
// {
// 	Whatever b = 17;
// 	Whatever c(18);
// 	Whatever d{19};
// 	cout << b.a << endl;
// 	cout << c.a << endl;
// 	cout << d.a << endl;
// }

#include <iostream>
using namespace std;

class MyClass {
  public:
    int x;
    MyClass(int val) : x(val) {}
    const int& get() const 
	{
		return x;
	}
	
    int& get() 
	{
		return x;
	}
};

int main() {
  MyClass foo (10);
//   const MyClass bar (20);
  foo.get() = 15;         // ok: get() returns int&
// bar.get() = 25;        // not valid: get() returns const int&
  cout << foo.x << '\n';
  cout << foo.get() << '\n';
//   cout << bar.get() << '\n';

  return 0;
}