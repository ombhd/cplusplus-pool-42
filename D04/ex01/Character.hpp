/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:51:37 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/17 18:33:42 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#define MAX_AP 40

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
    private:
        std::string _name;
        int _actionPoints;
        AWeapon *_weapon;
        
    public:
        Character();
        Character(std::string const & name);
        Character(const Character &src);
        virtual ~Character();
        Character &operator=(const Character &src);
        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string getName() const;
        int         getAP() const;
        AWeapon		*getWP() const;
};

std::ostream &operator<<(std::ostream &out, const Character &charac);

#endif // !CHARACTER_H