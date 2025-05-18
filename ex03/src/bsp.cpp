/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:32:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/18 17:05:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    Fixed cross1 = (b.getPoint('x') - a.getPoint('x')) * (p.getPoint('y') - a.getPoint('y')) -
	(b.getPoint('y') - a.getPoint('y')) * (p.getPoint('x') - a.getPoint('x'));

	Fixed cross2 = (c.getPoint('x') - b.getPoint('x')) * (p.getPoint('y') - b.getPoint('y')) -
	(c.getPoint('y') - b.getPoint('y')) * (p.getPoint('x') - b.getPoint('x'));

	Fixed cross3 = (a.getPoint('x') - c.getPoint('x')) * (p.getPoint('y') - c.getPoint('y')) -
	(a.getPoint('y') - c.getPoint('y')) * (p.getPoint('x') - c.getPoint('x'));
    
	return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
}