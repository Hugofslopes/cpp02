/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:31:39 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/19 14:30:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
#include "../includes/Fixed.hpp"

class Point {
	
	public:
		Point();
		Point(const Fixed x, const Fixed y );
		Point(const Point &copy);
		Point& operator=(const Point &other);
		~Point();

		Fixed	getPoint(char c) const;

	private:
		Fixed	x;
		Fixed	y;
};

#endif