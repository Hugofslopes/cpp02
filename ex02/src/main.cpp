/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/19 14:28:20 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void ) {
	{
		Fixed  a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	} 
	{
		Fixed a(5), b(10);
		Fixed &result1 = Fixed::max(a, b);
		Fixed &result2 = Fixed::min(a, b);
		std::cout << std::endl << "a- " << a << std::endl;
		std::cout << "b- "<< b << std::endl;
		std::cout << "result1 (max)- " << result1 << std::endl;
		std::cout <<  "result2 (min)- " << result2 << std::endl;

		result1.setRawBits(15);
		std::cout << std::endl << "After modifying result1:" << std::endl;
		std::cout << "a- " << a << std::endl;
		std::cout << "b- " << b << std::endl;
		std::cout << "result1 (max)- " << result1 << std::endl;

		Fixed result3 = Fixed::max(a, b);
		const Fixed &result4 = Fixed::min(a, b);
		
		std::cout << std::endl << "Const max and min:" << std::endl;
		std::cout << "result3 (max)- " << result3 << std::endl;
		std::cout << "result4 (min)- " << result4 << std::endl;
	
		result1.setRawBits(2);
		std::cout << std::endl << "After modifying result1 again:" << std::endl;
		std::cout << "result3 (max)- " << result3 << std::endl;
		std::cout << "result1 (max)- " << result1 << std::endl;
		std::cout << "a- " << a << std::endl;
		std::cout << "b- " << b << std::endl;
	}
}
