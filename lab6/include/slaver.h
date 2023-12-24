#pragma once

#include "npc.h"
#include "visitors.h"

class Slaver : public NPC {
   public:
    Slaver(const std::string &name, int x, int y);
    Slaver(const std::string &name, std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_slaver() const;

    std::string getType() const override;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<ErrantKnight> other) override;
    bool fight(std::shared_ptr<Slaver> other) override;

    bool accept(Visitor &visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Slaver &slaver);
};
