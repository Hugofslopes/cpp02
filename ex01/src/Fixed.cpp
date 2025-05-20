/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:39:26 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/20 19:26:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : fixedNb(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedNb(other.fixedNb){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->fixedNb = other.fixedNb;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::Fixed(const int value) {
	this->fixedNb = value << bits;
}

Fixed::Fixed(const float value) : fixedNb(static_cast<int>(roundf(value * (1 << bits)))) {}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedNb);
}

void Fixed::setRawBits(int const fixedNb) {
	this->fixedNb = fixedNb << bits;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->fixedNb) / (1 << bits));
} 

int Fixed::toInt(void) const {
	return (this->fixedNb >> bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}