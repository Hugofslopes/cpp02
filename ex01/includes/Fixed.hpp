/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:39:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/19 14:25:02 by hfilipe-         ###   ########.fr       */
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
		Fixed(const float fvalue);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int 				fixedNb;
		static const int	bits = 8;
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
# endif