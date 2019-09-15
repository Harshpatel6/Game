#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct gear
{
    int wep, shield, body_Arm, legs_Arm, hhh_hat_hood_helm;
    int r_Hand, l_Hand, neck;
};
struct monster
{
    int level;
    int hp, armor, atk;
    double atkspeed;
    int exp;
};
struct character
{
    int race, gender, hero_class, sub_class;
    int level;
    double exp, hp, mana, atk, str, agi, intel, atkspeed, armor;
    char name[30];
    int wep, shield;
};

int main()
{
    struct character player[10];
    int index = 0;
    int selection_Menu;

    selection_Menu = menu();

    if (selection_Menu != 3)
    {
        player[0].armor = 0;
        player[0].exp = 0;
        player[0].level = 1;
        player[0].hp = 100;
        player[0].mana = 100;
        name(&player[0]);
        race(&player[0]);
        hero_Class(&player[0]);
        gender(&player[0]);
        stats(&player[0]);
        index++;
    }
}
void name(struct character* hero)
{
    char name[30];

    printf("What is your name? ");
    scanf("%s", &name);

    strcpy(hero->name, name);
}
void race(struct character* hero)
{
    int id;

    while (1 == 1)
    {
        printf("Choose one of the following (1 for Human, 2 for Elf, 3 for Dwarf: ");
        scanf("%d", &id);

        if (id == 1 || id == 2 || id == 3)
            break;

        printf("Enter a number between 1 to 3 please. \n");
    }
    hero->race = id;
}
void gender(struct character* hero)
{
    int id;

    while (1 == 1)
    {
        printf("Choose one of the following (1 for Male, 2 for Female: ");
        scanf("%d", &id);

        if (id == 1 || id == 2)
            break;

        printf("Enter a number between 1 to 2 please. \n");
    }
    hero->gender = id;
}
void hero_Class(struct character* hero)
{
    int id;

    while (1 == 1)
    {
        printf("Choose one of the following (1 for Warrior, 2 for Archer, 3 for Mage: ");
        scanf("%d", &id);

        if (id == 1 || id == 2 || id == 3)
            break;

        printf("Enter a number between 1 to 3 please. \n");
    }
    hero->hero_class = id;
}
int menu()
{
    int input;

    while (1==1)
    {
        printf("Enter one of the following options!\n");
        printf("Please write 1 for new character.\n");
        printf("Please write 2 for loading game.\n");
        printf("Please write 3 to exit the game.\n");
        printf("Select a number: ");
        scanf("%d", &input);

        if (input == 1)
        {
            return 1;
        }
        else if (input == 2)
        {
            return 2;
        }
        else if (input == 3)
        {
            return 3;
        }
        else
            printf("Please write a integer between 1-3.\n");
    }
}
void stats(struct character* hero)
{
    int i;
    double multiplier;
    double targetexp;
    int hero_Lvl;
    int counter;
    int str_const;
    int agi_const;
    int intel_const;
    double atk_speed;

    //level 1, 0 exp
    targetexp = 150;
    multiplier = 1.5;
    counter = 0;
    hero_Lvl = 1;

    for (i = 0; i < 20; i++)
    {
        if ((i + 1) % 5 == 0)
            multiplier = multiplier - 0.1;

        if (hero->exp >= targetexp)
        {
            hero_Lvl = i + 1;
            printf("%d Hero should be level\n", i);
        }
        targetexp = targetexp * multiplier;
    }
    if(hero->level != hero_Lvl)
    {
        hero->level = hero_Lvl;
        printf("Hero has leveled up\n");
    }
    //check to see if level has increased here
    switch(hero->hero_class)
    {
        case 1:
            str_const = 3;
            agi_const = 2;
            intel_const = 1;
            hero->str = 0;
            hero->agi = 0;
            hero->intel = 0;
            atk_speed = 0.5;
            for (i = 0; i < hero->level; i++)
            {
                if (counter == 5)
                {
                    counter = 0;
                    str_const++;
                    agi_const++;
                    intel_const++;
                }
                hero->str += str_const;
                hero->agi += agi_const;
                hero->intel += intel_const;
            }
            hero->atk = (hero->str * 1.5) + 10;
            hero->mana = hero->mana + (hero->intel * 30);
            hero->hp = hero->hp + (hero->str * 30);
            hero->atkspeed = atk_speed + (hero->agi * 0.05);
            break;
        case 2:
            str_const = 1;
            agi_const = 3;
            intel_const = 2;
            hero->str = 0;
            hero->agi = 0;
            hero->intel = 0;
            atk_speed = 1;
            for (i = 0; i < 20; i++)
            {
                if (counter == 5)
                {
                    counter = 0;
                    str_const++;
                    agi_const++;
                    intel_const++;
                }
                hero->str += str_const;
                hero->agi += agi_const;
                hero->intel += intel_const;
            }
            hero->atk = (hero->agi * 1.5) + 10;
            hero->hp = hero->hp + (hero->str * 30);
            hero->mana = hero->mana + (hero->intel * 30);
            hero->atkspeed = atk_speed + (hero->agi * 0.05);
            break;
        case 3:
            str_const = 1;
            agi_const = 2;
            intel_const = 3;
            hero->str = 0;
            hero->agi = 0;
            hero->intel = 0;
            atk_speed = 0.7;
            for (i = 0; i < 20; i++)
            {
                if (counter == 5)
                {
                    counter = 0;
                    str_const++;
                    agi_const++;
                    intel_const++;
                }
                hero->str += str_const;
                hero->agi += agi_const;
                hero->intel += intel_const;
            }
            hero->atk = (hero->intel * 1.5) + 10;
            hero->hp = hero->hp + (hero->str * 30);
            hero->mana = hero->mana + (hero->intel * 30);
            hero->atkspeed = atk_speed + (hero->agi * 0.05);
            break;
    }
}
