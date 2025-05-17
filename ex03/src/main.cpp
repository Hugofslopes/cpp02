/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/17 12:45:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a(0,0),b(5,0),c(2,5),point(2,2);
	std::cout << bsp(a, b, c, point) << std::endl;
	/* Point a(0,0),b(5,0),c(2,5),point(2.5,0);
	std::cout << bsp(a, b, c, point) << std::endl;
	Point a(0,0),b(5,0),c(2,5),point(2,2);
	std::cout << bsp(a, b, c, point) << std::endl; */

}
