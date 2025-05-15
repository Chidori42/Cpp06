/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:19:09 by ael-fagr          #+#    #+#             */
/*   Updated: 2025/05/15 15:00:00 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data dt;
    uintptr_t ptr;

    dt.setString("Abdellatif");
    dt.setNumber(23);
    dt.setLnum(65656566565566666);

    ptr = Serializer::serialize(&dt);
    Data *data_ptr = Serializer::deserialize(ptr);

    std::cout << dt.getString() << std::endl;
    std::cout << data_ptr->getString() << std::endl;
    
    return (0);
}