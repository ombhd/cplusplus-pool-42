/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:25:52 by obouykou          #+#    #+#             */
/*   Updated: 2021/02/19 12:45:17 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void	sep()
{
	std::cout << std::endl;
	usleep(500000);
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* nkki = new Character("nkki");
    
    AMateria* tmp;
    AMateria* tmp2;
    tmp = src->createMateria("ice");
    nkki->equip(tmp);
    std::cout << "[+] ICE = " << tmp->getType() << std::endl;
    sep();
	
    tmp2 = src->createMateria("cure");
    nkki->equip(tmp2);
    std::cout << "[+] CURE = " << tmp2->getType() << std::endl;
    sep();
    
    ICharacter* bob = new Character("bob");
    
    nkki->use(0, *bob);
    sep();
    nkki->use(1, *bob);
    std::cout << "[+] " << tmp->getType() << " xp = " << tmp->getXP() << std::endl;
    sep();
    std::cout << "[+] " << tmp2->getType() << " xp = " << tmp2->getXP() << std::endl;
    sep();

    
    nkki->use(0, *bob);
    sep();
    std::cout << "[+] " << tmp->getType() << " xp = " << tmp->getXP() << std::endl;
    std::cout << "[+] " << tmp2->getType() << " xp = " << tmp2->getXP() << std::endl;
    sep();

    delete bob;
    delete nkki;
    delete src;
    
    return 0;
}