using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace Creature
{
    abstract class Creature
    {
        public int damage { get; set; }
        public int strength { get; set; }
        public int hitpoints { get; set; }
        public abstract int getDamage();
        public Creature()
        {

        }
        public Creature(int newStrength, int newHit)
        {

        }
        /*int GetDamage()
        {

            int damage = 0;
            Random random = new Random();
            if ((type == 2) || type == 1)
            {
                if ((random.NextDouble() % 100) < 5)
                {
                    damage += 50;
                    return damage;

                }
            }
            if(type == 3)
            {
                if(random.NextDouble() %10 == 0)
                {
                   return damage = damage * 2;
                }
            }
            if(type == 2)
            {
               return damage = (damage +((random.Next()) % strength) + 1);
             }
            return 0;

        }*/



    }
    class Human : Creature
    {
        public Human(int strength, int hitpoints) : base(strength, hitpoints) { }
        public override int getDamage()
        {
            return damage * 2;
        }
    }
    class Balrog : Cyberdemon
    {
        public Balrog(int strength, int hitpoints) : base(strength, hitpoints) { }
        Random random = new Random();
        public override int getDamage()
        {
            return damage = (damage + ((random.Next()) % strength) + 1);
        }
    }
    class Cyberdemon : Creature
    {
        public Cyberdemon(int strength, int hitpoints) : base(strength, hitpoints) { }

        public override int getDamage()
        {
            return damage * 2;
        }
    }
    class Elf : Human
    {
        public Elf(int strength, int hitpoints) : base(strength, hitpoints) { }
        Random random = new Random();
        public override int getDamage()
        {
            if (random.NextDouble() % 10 == 0)
            {
                return damage = damage * 2;
            }
            else return 0;
        }
    }
}
