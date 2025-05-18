/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:39:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/18 10:47:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:
		Fixed();
		Fixed(const Fixed &copy); 
		Fixed& operator=(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& max(Fixed &obj, Fixed &otherO);
		static const Fixed& min(const Fixed &obj, const Fixed &otherO);
		static const Fixed& max(const Fixed &obj, const Fixed &otherO);
		static Fixed& min(Fixed &obj, Fixed &otherO);

		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed operator-() const;
		Fixed abs() const;

	private:
		int raw;
		static const int bits = 8;
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
# endif