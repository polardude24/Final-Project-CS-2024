#ifndef ENTITY_H
#define ENTITY_H

#include <Utility.h>


class Entity : public Utility
{
    public:
        Entity();
        virtual ~Entity();

        float getHp() { return hp; }
        void setHp(float val) { hp = val; }
        string getName() { return name; }
        void setName(string val) { name = val; }
        float getStrength() { return strength; }
        void setStrength(float val) { strength = val; }
        int getId() { return id; }
        void setId(int val) { id = val; }
        int getPosX() { return posX; }
        void setPosX(int val) { posX = val; }
        int getPosY() { return posY; }
        void setPosY(int val) { posY = val; }
        bool getIsAlive() { return isAlive; }
        void setIsAlive(bool val) { isAlive = val; }
        char getType() { return type; }
        void setType(char val) { type = val; }

        void moveEntity(char);
        void display();

    protected:
        WINDOW* curWin;
        float hp;
        string name;
        float strength;
        int id;
        int posX;
        int posY;
        bool isAlive;
        char type;

    private:
};

#endif // ENTITY_H
