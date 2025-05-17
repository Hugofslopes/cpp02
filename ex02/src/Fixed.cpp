/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:39:26 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/16 12:40:27 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	this->raw = (value << Fixed::bits);
}

Fixed::Fixed(const float raw) {
	this->raw = (raw * (1 << Fixed::bits));
}

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

Fixed Fixed::operator+(const Fixed &rhs) {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(){
	int value = getRawBits();
	setRawBits(value + 1);
	return (*this);
}

Fixed& Fixed::operator--(){
	int value = getRawBits();
	setRawBits(value - 1);
	return (*this);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	return ((lhs > rhs) ? lhs : rhs);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
