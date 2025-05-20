/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/20 14:38:51 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	{
		Point a(0,0), b(5,0), c(2,5), point(2,2);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(2.2f,2.1f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{ 
		Point a(0,0), b(5,0), c(2,5), point(2.5f, 1.25f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(0, 0);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(3, 0);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	} 
	{
		Point a(0,0), b(5,0), c(2,5), point(3.1f, 0.1f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(5.0f, 0.0f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(4.9f, 0.1f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(5.1f, 0.1f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(-1,-1);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(6,1);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(2,10);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
	{
		Point a(0,0), b(5,0), c(2,5), point(4.5f, 4.5f);
		std::cout << (bsp(a, b, c, point) == 1 ? "is inside" : "is out") << std::endl;
	}
}
