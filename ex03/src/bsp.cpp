/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:32:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/05/19 18:50:50 by hfilipe-         ###   ########.fr       */
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


// ( (bx - ax) * (py - ay) )- ((by - ay) * (px - ax)) 
/*  example:
       C (2.5)
	   .
      / \  .P (4.5 , 4.5)
  	 /   \
 	._ _ _.
A (0,0)  B (5,0)

AB = (5 , 0) – (0 , 0) =      (5 , 0)
AP = (4.5 ,  4.5) – (0, 0) = (4.5, 4.5)
Cross1 = (5 * 4.5) – (0 * 4.5) = 22.5

BC = (2.5 ,  5) – (5 , 0)  = (-2.5 , 5)
BP = (4.5 , 4.5) - (5 , 0) = (-0.5 , 4.5)
Cross2 = (-2.5 * 4.5) – (5 * (0.5)) = -8.75

CA = (0 , 0) – (2.5 , 5) = (-2.5 , -5)
CP = (4.5 , 4.5) – (2.5, 5) = (2 , -0.5)
Cross3 = (-2.5 * -0.5) - (-5 * 2) =11.25
*/