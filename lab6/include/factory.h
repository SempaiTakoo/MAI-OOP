#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <set>

#include "npc.h"

std::shared_ptr<NPC> factory(const std::string &name, std::istream &is,
                             const std::string &filename);
std::shared_ptr<NPC> factory(NpcType type, const std::string &name, int x,
                             int y, const std::string &filename);

void save(const set_t &array, const std::string &filename);
set_t load(const std::string &name, const std::string &filename);
set_t fight(const set_t &array, size_t distance);

std::ostream &operator<<(std::ostream &os, const set_t &array);
