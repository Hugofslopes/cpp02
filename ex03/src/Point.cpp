/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:31:57 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/19 14:32:50 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : x(0), y(0){
	std::cout << "Default constructor called" << std::endl; 
}

Point::Point(const Fixed x, const Fixed y ) : x(x), y(y){
	std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point &copy) : x(copy.x),  y(copy.y){
	std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &other){
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Point::~Point(){}

Fixed Point::getPoint(char c) const {
	return ((c == 'x') ? this->x : this->y);
}