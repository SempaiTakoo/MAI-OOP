#include "visitors.h"

#include "errant_knight.h"
#include "npc.h"
#include "slaver.h"
#include "squirrel.h"

NPCVisitor::NPCVisitor(std::shared_ptr<NPC> attacker) : attacker_(attacker) {}

bool NPCVisitor::visit(Slaver& slaver) {
    return attacker_->fight(std::make_shared<Slaver>(slaver));
}

bool NPCVisitor::visit(ErrantKnight& knight) {
    return attacker_->fight(std::make_shared<ErrantKnight>(knight));
}

bool NPCVisitor::visit(Squirrel& squirrel) {
    return attacker_->fight(std::make_shared<Squirrel>(squirrel));
}
