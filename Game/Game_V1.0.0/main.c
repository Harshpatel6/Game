#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct gear
{
    int id;
    int str, agi, armor, intel;
    int rarity;
};
struct character
{
    int level;
    int gender;                                         //1 for male, 2 for female
    int race;                                           //1 for human, 2 for elf, 3 for dwarf
    int hero_Class;                                     //1 for Warrior, 2 for archer, 3 for mage
    int hero_subClass;
    int str, intel, agi, hp, mana, stamina;
    int exp, atk, atkspeed, armor;
    int armorSlot, wepSlot;
};
struct monster
{
    int level;
    int hp, armor, atk, atkspeed;
    int exp;
};
void menu(struct character user, struct monster a, struct monster b, struct monster c, struct monster d, struct monster e)
{
    int damage;
    int input;
    while (1 == 1)
    {
        while (1 == 1)
        {
            printf("Who do you want to fight (1 for slime, 2 for goblin, 3 for hobgoblin, 4 for direwolf, 5 for ogre)? ");
            scanf("%d", &input);

            if (input > 0 && input < 6)
                break;

            printf("PLEASE FOR THE LOVE OF GOD WRITE A NUMBER BETWEEN 1 - 5");
        }

        switch(input)
        {
            case 1:
                printf("A wild slime appears.\n\n");
                fight(user, a);
                break;
            case 2:
                printf("A wild goblin appears.\n\n");
                fight(user, b);
                break;
            case 3:
                printf("A wild hobgoblin appears.\n\n");
                fight(user, c);
                break;
            case 4:
                printf("A wild direwolf appears.\n\n");
                fight(user, d);
                break;
            case 5:
                printf("A wild ogre appears.\n\n");
                fight(user, e);
                break;
        }
    }
}
void fight(struct character user, struct monster mon)
{
    int winner;
    int curMonHP = mon.hp;
    int curUserHP = user.hp;
    int i;
    int userAttackCounter, monAttackCounter;

    winner = 0;
    userAttackCounter = user.atkspeed;
    monAttackCounter = mon.atkspeed;

    while (1 == 1)
    {
        printf("Enemy has %d HP.\n", curMonHP);
        printf("You have %d HP.\n", curUserHP);

        for (i = 0; i < 10; i++)
        {
            userAttackCounter--;
            monAttackCounter--;

            if (userAttackCounter == 0)
            {
                //User attacks
                curMonHP = curMonHP - user.atk - mon.armor;
                userAttackCounter = user.atkspeed;
                printf("User attacked Monster for %d HP at %d seconds.\n", user.atk - mon.armor, i + 1);
            }

            if (monAttackCounter == 0)
            {
                //Monster attacks
                curUserHP = curUserHP - mon.atk - user.armor;
                monAttackCounter = mon.atkspeed;
                printf("Monster attacked user for %d HP at %d seconds.\n", mon.atk - user.armor, i + 1);
            }
            printf("Enemy has %d HP.\n", curMonHP);
            printf("You have %d HP.\n", curUserHP);
            //system("pause");
            if (curMonHP <= 0 && curUserHP <= 0)        // Ties
            {
                winner = 3;
                printf("It is a tie!\n");
                break;
            }
            if (curMonHP <= 0 && curUserHP > 0)        // User wins
            {
                winner = 2;
                printf("User wins!\n");
                break;
            }
            if (curMonHP > 0 && curUserHP <= 0)        // Monster wins
            {
                winner = 1;
                printf("Monster wins!\n");
                break;
            }
        }
        if (winner != 0)
            break;
    }
    if (winner == 2)
    {
        user.exp += mon.exp;
        printf("User has gained %d exp, User is now at %d exp\n", mon.exp, user.exp);
        if (levelUp(user.exp, user.level) != 0)
        {
            printf("USER LEVELED UP\n");
        }
    }
}

int main()
{
    createWorld();
}
void createWorld()
{
    struct character grim;
    struct monster slime;
    struct monster goblin;
    struct monster hobgoblin;
    struct monster direwolf;
    struct monster ogre;

    grim.level = 1;
    grim.race = race();
    grim.gender = gender();
    grim.hero_Class = hero_Class();
    grim.str = str(grim);
    grim.agi = agi(grim);
    grim.intel = intel(grim);
    grim.hp = 100 + grim.str * 10;
    grim.mana = 100 + grim.intel * 10;
    grim.stamina = 100 + grim.agi * 10;
    grim.exp = 0;
    grim.atk = atk(grim);
    grim.atkspeed = atkspeed(grim.hero_Class) - grim.agi / 20;
    grim.armor = armor(grim.hero_Class);
    showStats(grim);

    slime.level = 1;
    slime.hp = 100;
    slime.armor = 0;
    slime.atk = 5;
    slime.atkspeed = 2;
    slime.exp = 10;

    goblin.level = 2;
    goblin.hp = 150;
    goblin.armor = 3;
    goblin.atk = 10;
    goblin.atkspeed = 3;
    goblin.exp = 25;

    hobgoblin.level = 3;
    hobgoblin.hp = 250;
    hobgoblin.armor = 10;
    hobgoblin.atk = 15;
    hobgoblin.atkspeed = 4;
    hobgoblin.exp = 45;

    direwolf.level = 4;
    direwolf.hp = 400;
    direwolf.armor = 0;
    direwolf.atk = 20;
    direwolf.atkspeed = 3;
    direwolf.exp = 80;

    ogre.level = 5;
    ogre.hp = 550;
    ogre.armor = 20;
    ogre.atk = 50;
    ogre.atkspeed = 5;
    ogre.exp = 100;

    menu(grim, slime, goblin, hobgoblin, direwolf, ogre);
}
void showStats(struct character user)
{
    switch(user.gender)
    {
        case 1:
            printf("The gender is: Male\n");
            break;
        case 2:
            printf("The gender is: Female\n");
            break;
        default:
            printf("Something is wrong.\n");
            break;
    }
    switch(user.race)
    {
        case 1:
            printf("The race is: Human\n");
            break;
        case 2:
            printf("The race is: Elf\n");
            break;
        case 3:
            printf("The race is: Dwarf\n");
            break;
        default:
            printf("Something is wrong.\n");
            break;
    }
    switch(user.hero_Class)
    {
        case 1:
            printf("The class is: Warrior\n");
            break;
        case 2:
            printf("The class is: Archer\n");
            break;
        case 3:
            printf("The class is: Mage\n");
            break;
        default:
            printf("Something is wrong.");
            break;
    }
    printf("The HP is: %d\nThe MANA is: %d\nThe STAMINA is: %d\nThe STR is: %d\nThe AGI is: %d\nThe INT is: %d\n", user.hp, user.mana, user.stamina, user.str, user.agi, user.intel);
    printf("The ATTACK is: %d\nThe ATTACK SPEED is: %d\nThe ARMOR is: %d\n", user.atk, user.atkspeed, user.armor);
}
int gender()
{
    int input_Gender;

    while(1 == 1)
    {
        printf("Enter your gender(1 for Male, 2 for Female): ");
        scanf("%d", &input_Gender);

        if (input_Gender == 1)
            break;

        if(input_Gender == 2)
            break;

        printf("Please for the sake of god, enter 1 or 2\n");
    }

    return input_Gender;
}
int race()
{
    int input_Race;

    while(1 == 1)
    {
        printf("Enter your race(1 for Human, 2 for Elf, 3 for Dwarf): ");
        scanf("%d", &input_Race);

        if (input_Race == 1)
            break;

        if(input_Race == 2)
            break;

        if(input_Race == 3)
            break;

        printf("Please for the sake of god, enter 1,2 or 3\n");
    }

    return input_Race;
}
int hero_Class()
{
    int input_Class;

    while(1 == 1)
    {
        printf("Enter your race(1 for Warrior, 2 for Archer, 3 for Mage): ");
        scanf("%d", &input_Class);

        if (input_Class == 1)
            break;

        if(input_Class == 2)
            break;

        if(input_Class == 3)
            break;

        printf("Please for the sake of god, enter 1,2 or 3\n");
    }

    return input_Class;
}
int str(struct character c)
{
    switch(c.hero_Class)
    {
        case 1:
            return 6 + c.level * 3;
            break;
        case 2:
            return 3 + c.level * 1;
            break;
        case 3:
            return 3 + c.level * 1;
            break;
        default:
            printf("Something is wrong");
            break;
    }
}
int intel(struct character c)
{
    switch(c.hero_Class)
    {
        case 1:
            return 3 + c.level * 1;
            break;
        case 2:
            return 4 + c.level * 3;
            break;
        case 3:
            return 6 + c.level * 2;
            break;
        default:
            printf("Something is wrong");
            break;
    }
}
int agi(struct character c)
{
    switch(c.hero_Class)
    {
        case 1:
            return 4 + c.level * 1;
            break;
        case 2:
            return 6 + c.level * 2;
            break;
        case 3:
            return 4 + c.level * 3;
            break;
        default:
            printf("Something is wrong");
            break;
    }
}
int atk(struct character c)
{
    switch(c.hero_Class)
    {
        case 1:
            return 15 + (c.str/2);
            break;
        case 2:
            return 10 + (c.agi/2);
            break;
        case 3:
            return 10 + (c.intel/2);
            break;
        default:
            printf("Something is wrong");
            break;
    }
}
int atkspeed(int c)
{
    switch(c)
    {
        case 1:
            return 3;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            printf("Something is wrong");
            break;
    }
}
int armor(int c)
{
    switch(c)
    {
        case 1:
            return 0;
            break;
        case 2:
            return 0;
            break;
        case 3:
            return 0;
            break;
        default:
            printf("Something is wrong");
            break;
    }
}
int levelUp(int exp, int currentLevel)
{
    int levelUp;
    if (exp >= (100 * pow(1.5, currentLevel)))
    {
        return 1;
    }
    else
        return 0;
}
