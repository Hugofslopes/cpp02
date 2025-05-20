/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:39:26 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/20 19:26:39 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : fixedNb(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixedNb(value << bits) {}

Fixed::Fixed(const float value) : fixedNb(static_cast<int>(roundf(value * (1 << bits)))) {}

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

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedNb);
}

void Fixed::setRawBits(int const fixedNb) {
	this->fixedNb = fixedNb;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->fixedNb) / (1 << Fixed::bits));
}

int Fixed::toInt(void) const {
	return (this->fixedNb >> Fixed::bits);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->fixedNb > other.fixedNb);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->fixedNb < other.fixedNb);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->fixedNb >= other.fixedNb);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->fixedNb <= other.fixedNb);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->fixedNb != other.fixedNb);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->fixedNb == other.fixedNb);
}

Fixed Fixed::operator+(const Fixed &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.fixedNb == 0) {
        throw std::runtime_error("Division by zero");
    }
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++(void) {
	++fixedNb;
    return (*this);
}

Fixed& Fixed::operator--(void) {
	--fixedNb;
    return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::max(Fixed &obj, Fixed &otherO) {
    return (obj > otherO) ? obj : otherO;
}
const Fixed& Fixed::max(const Fixed &obj, const Fixed &otherO) {
    return (obj > otherO) ? obj : otherO;
}
Fixed& Fixed::min(Fixed &obj, Fixed &otherO) {
    return (obj < otherO) ? obj : otherO;
}
const Fixed& Fixed::min(const Fixed &obj, const Fixed &otherO) {
    return (obj < otherO) ? obj : otherO;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
