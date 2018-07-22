//
// Created by hugo on 22/07/18.
//

#ifndef INVADER_IENTITY_HPP
#define INVADER_IENTITY_HPP

#include <map>
#include "Atribute.hh"

class IEntity
{
public:
    virtual std::map<std::string, Atribute> getAtributes();
    virtual bool setAtribute(std::string, Atribute);

};

#endif //INVADER_IENTITY_HPP
