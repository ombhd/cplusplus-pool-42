/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:40:42 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/08 18:42:26 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
#define NINJATRAP_H

class NinjaTrap : 
{
public:
	NinjaTrap() = default;
	NinjaTrap(NinjaTrap &&) = default;
	NinjaTrap(const NinjaTrap &) = default;
	NinjaTrap &operator=(NinjaTrap &&) = default;
	NinjaTrap &operator=(const NinjaTrap &) = default;
	~NinjaTrap() = default;

private:
	
};

#endif // !NINJATRAP_H