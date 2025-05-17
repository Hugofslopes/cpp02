/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:32:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/17 12:43:52 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

// Area = | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) | / 2


Fixed area(const Point &p1, const Point &p2, const Point &p3) {
    Fixed area =
	p1.getPoint('x') * (p2.getPoint('y') - p3.getPoint('y')) 
	+ p2.getPoint('x') * (p3.getPoint('y') - p1.getPoint('y')) 
	+ p3.getPoint('x') * (p1.getPoint('y') - p2.getPoint('y'));
	return (area.abs() / Fixed(2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
    Fixed epsilon = 0.00001f;
    return ((A1 + A2 + A3) - A < epsilon && A1 > 0 && A2 > 0 && A3 > 0);
}
