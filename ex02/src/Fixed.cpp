/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:39:26 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/18 16:53:40 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : raw(value << Fixed::bits) {}

Fixed::Fixed(const float value) : raw(static_cast<int>(round(value * (1 << bits)))) {}

Fixed::Fixed(const Fixed &other) : raw(other.raw){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->raw = other.raw;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl; 
	return (raw);
}

void Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->raw) / (1 << Fixed::bits));
}

int Fixed::toInt(void) const {
	return (this->raw >> Fixed::bits);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->raw > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->raw < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->raw >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->raw <= other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->raw != other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->raw == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) {
	if (other.raw == 0) {
        throw std::runtime_error("Division by zero");
    }
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++(void) {
	this->raw++;
	return (*this);
}

Fixed& Fixed::operator--(void) {
	this->raw--;
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

Fixed &Fixed::max(Fixed &obj, Fixed &otherO) {
	return ((obj > otherO) ? obj : otherO);
}

const Fixed &Fixed::max(const Fixed &obj, const Fixed &otherO) {
	return ((obj > otherO) ? obj : otherO);
}

Fixed &Fixed::min(Fixed &obj, Fixed &otherO) {
	return ((obj < otherO) ? obj : otherO);
}

const Fixed &Fixed::min(const Fixed &obj, const Fixed &otherO) {
	return ((obj < otherO) ? obj : otherO);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
