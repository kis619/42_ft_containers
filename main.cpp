/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:51:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/24 13:05:47 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inserting into a vector
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  std::cout << *it << std::endl;
  it = myvector.insert ( it , 200 );
  std::cout << *it << std::endl;

  myvector.insert (it,2,300);
  std::cout << *it << std::endl;

  // "it" no longer valid, get a new one:
  // it = myvector.begin();

  // std::vector<int> anothervector (2,400);
  // myvector.insert (it+2,anothervector.begin(),anothervector.end());

  // int myarray [] = { 501,502,503 };
  // myvector.insert (myvector.begin(), myarray, myarray+3);

  // std::cout << "myvector contains:";
  // for (it=myvector.begin(); it<myvector.end(); it++)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';

  return 0;
}