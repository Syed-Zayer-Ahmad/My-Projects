#include <stdio.h> 
#include <stdlib.h>

int main()
{
    char player_1_name[50];
    char player_2_name[50];
    
    int player_1_hp = 100;
    int player_2_hp = 100;
    
    int game_round = 1;
    
    int player_1_choice;
    int player_2_choice;

    float damage_multiplier = 1.0;

    printf("$<------- WELCOME TO ELEMENT DUEL ------->$\n\n\n");

    printf("Rules: \n\n");
    printf("1. Element Duel is a two player game of reading your opponent's mind.\n");
    printf("2. Both players start with 100 HP.\n");
    printf("3. Reduce your opponent's HP to 0 or below. If both hit 0 together, it's a TIE.\n");
    printf("4. Every round, secretly input one of three elemental stances:\n");
    printf("    (1) - FIRE STANCE  : High risk, massive offensive damage.\n");
    printf("    (2) - WATER STANCE : Tactical, reactive, and healing state.\n");
    printf("    (3) - EARTH STANCE : Defensive, protective setup state.\n\n");

    printf(" MATCH ESCALATION:\n");
    printf("     Rounds 1 - 3 : Normal Mode (1.0x Baseline Damage)\n");
    printf("     Rounds 4 - 6 : INTENSITY RISING! (1.5x Damage Scaling)\n");
    printf("     Rounds 7+    : SUDDEN DEATH!!!  (2.0x Damage - Outright Lethal)\n");
    printf("   *(Note: Healing amounts remain static to ensure a swift match!)*\n\n");

    printf("6. The Battle Combinations & Damage Scaling are as follows:\n\n");
    
    printf("    (A) - FIRE STANCE MASHUP\n");
    printf("          (i)   Fire vs Fire  : Fierce clash! Both players lose health.\n");
    printf("                                [R(1-3): 15 HP | R(4-6): 22 HP | R(7+): 30 HP]\n");
    printf("          (ii)  Fire vs Water : Water vaporizes Fire! Fire player takes damage,\n");
    printf("                                Water player heals +10 HP (Max 100).\n");
    printf("                                [R(1-3): 5 DMG | R(4-6): 7 DMG  | R(7+): 10 DMG]\n");
    printf("          (iii) Fire vs Earth : Fire melts Earth entirely! Earth player takes massive damage.\n");
    printf("                                [R(1-3): 25 DMG | R(4-6): 37 DMG | R(7+): 50 DMG]\n\n");
    
    printf("    (B) - WATER STANCE MASHUP\n");
    printf("          (i)   Water vs Water: Calm seas. No damage dealt. Both heal +5 HP recovery.\n");
    printf("          (ii)  Water vs Earth: Mudslide! Earth absorbs Water. Water player takes damage.\n");
    printf("                                [R(1-3): 10 DMG | R(4-6): 15 DMG | R(7+): 20 DMG]\n\n");
    
    printf("    (C) - EARTH STANCE MASHUP\n");
    printf("          (i)   Earth vs Earth: Unbreakable Fortress! Raised shields. Both heal +10 HP.\n\n"); 
    
    printf("These combinations will be displayed at the starting of each round.\n");
   
    printf("\033[5mPress [ENTER] when you are ready to start the duel... \033[0m");
    
    // Fixed buffer flush
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    system("cls");
    
    printf("Player name can not contain any spaces!\n");
    printf("Enter Player 1 name: ");
    scanf("%s", player_1_name);
    printf("Enter Player 2 name: ");
    scanf("%s", player_2_name);

    while (player_1_hp > 0 && player_2_hp > 0)
    {
        if (game_round >= 4 && game_round <= 6) 
        {
            damage_multiplier = 1.5;
        } 
        else if (game_round >= 7) 
        {
            damage_multiplier = 2.0;
        }
        else 
        {
            damage_multiplier = 1.0; 
        }
        
        printf("\n-----------------------------------------\n");
        if (game_round >= 7)
        {
            printf("         SUDDEN DEATH - ROUND %d \n", game_round);
            printf("        (ALL DAMAGE IS DOUBLED!)\n");
        }
        else if (game_round >= 4)
        {
            printf("         INTENSITY RISING - ROUND %d \n", game_round);
            printf("      (ALL DAMAGE MULTIPLIED BY 1.5!)\n");
        }
        else
        {
            printf("               ROUND %d                  \n", game_round);
        }
        printf("-----------------------------------------\n\n");
        if (game_round == 1)
        {
            printf("%s plays first!\n", player_1_name);
        }
        else
        {
            printf("Its %s's turn!\n", player_1_name);
        }
        
        printf("The combinations are as follows: \n\n");
        printf("    (A) - Fire Stance Mashup\n");
        printf("          (i) - Fire vs Fire: Both players clash fiercely. Both players lose %d HP.\n", (int)(15 * damage_multiplier));
        printf("         (ii) - Fire vs Water: Water vaporizes Fire. The Fire player takes %d DMG, and the Water player heals +10 HP (up to a max of 100).\n", (int)(5 * damage_multiplier));
        printf("        (iii) - Fire vs Earth: Fire completely melts Earth. The Earth player takes a massive %d DMG.\n", (int)(25 * damage_multiplier));
        printf("    (B) - Water Stance Mashup\n");
        printf("          (i) - Water vs Water: Calm seas. No damage is dealt. Both players heal +5 HP as a recovery phase.\n");
        printf("         (ii) - Water vs Earth: Mudslide! Earth absorbs Water entirely. The Water player's stance is broken, and they take %d DMG.\n", (int)(10 * damage_multiplier));
        printf("    (C) - Earth Stance Mashup\n");
        printf("          (i) - Earth vs Earth: Unbreakable Fortress. Both players raise their shields. Both players heal +10 HP.\n\n");
        
        printf("%s's Stats: \n", player_1_name);
        printf("---> | HP: %d | <---\n", player_1_hp);
        
        printf("Enemy's Stats: \n");
        printf("---> | HP: %d | <---\n\n", player_2_hp);

        printf("Press: \n");
        printf("1 for FIRE\n");
        printf("2 for WATER\n");
        printf("3 for EARTH\n\n");
        
        printf("Your choice: ");
        scanf("%d", &player_1_choice);
        while (getchar() != '\n');

        while (player_1_choice < 1 || player_1_choice > 3)
        {
            printf("Invalid stance! Choose 1 (FIRE), 2 (WATER), or 3 (EARTH): ");
            scanf("%d", &player_1_choice);
            while (getchar() != '\n'); 
        }
        
        printf("\nStance locked in successfully!\n");
        printf("Press Enter to clear the screen...");
        getchar();
        
        system("cls");
        
        printf("Pass the controls to %s.\n", player_2_name);
        printf("Press Enter to clear the screen...");
        getchar();
        
        system("cls");

        printf("Its %s's turn!\n", player_2_name);

        printf("The combinations are as follows: \n\n");
        printf("    (A) - Fire Stance Mashup\n");
        printf("          (i) - Fire vs Fire: Both players clash fiercely. Both players lose %d HP.\n", (int)(15 * damage_multiplier));
        printf("         (ii) - Fire vs Water: Water vaporizes Fire. The Fire player takes %d DMG, and the Water player heals +10 HP (up to a max of 100).\n", (int)(5 * damage_multiplier));
        printf("        (iii) - Fire vs Earth: Fire completely melts Earth. The Earth player takes a massive %d DMG.\n", (int)(25 * damage_multiplier));
        printf("    (B) - Water Stance Mashup\n");
        printf("          (i) - Water vs Water: Calm seas. No damage is dealt. Both players heal +5 HP as a recovery phase.\n");
        printf("         (ii) - Water vs Earth: Mudslide! Earth absorbs Water entirely. The Water player's stance is broken, and they take %d DMG.\n", (int)(10 * damage_multiplier));
        printf("    (C) - Earth Stance Mashup\n");
        printf("          (i) - Earth vs Earth: Unbreakable Fortress. Both players raise their shields. Both players heal +10 HP.\n\n");
        
        printf("%s's Stats: \n", player_2_name);
        printf("---> | HP: %d | <---\n", player_2_hp);
        
        printf("Enemy's Stats: \n");
        printf("---> | HP: %d | <---\n\n", player_1_hp);

        printf("Press: \n");
        printf("1 for FIRE\n");
        printf("2 for WATER\n");
        printf("3 for EARTH\n\n");

        printf("Your choice: ");
        scanf("%d", &player_2_choice);
        while (getchar() != '\n');

        while (player_2_choice < 1 || player_2_choice > 3)
        {
            printf("Invalid stance! Choose 1 (FIRE), 2 (WATER), or 3 (EARTH): ");
            scanf("%d", &player_2_choice);
            while (getchar() != '\n'); 
        }
        
        printf("\nStance locked in successfully!\n");
        printf("Press Enter to clear the screen...");
        getchar();
        
        system("cls");

        printf("======= ROUND %d RESULT =======\n\n", game_round);
        
        int final_damage = 0; 
        
        if (player_1_choice == 1 && player_2_choice == 1)
        {
            printf("Both %s and %s chose FIRE!\n", player_1_name, player_2_name);
            
            final_damage = (int)(15 * damage_multiplier);
            
            player_1_hp -= final_damage;
            player_2_hp -= final_damage;

            printf("Both players lose %d HP!\n", final_damage);
        }
        else if (player_1_choice == 1 && player_2_choice == 2)
        {
            printf("%s chose FIRE and %s chose WATER!\n", player_1_name, player_2_name);
            
            final_damage = (int)(5 * damage_multiplier);
            
            player_1_hp -= final_damage;

            if (player_2_hp > 90) 
            {
                player_2_hp = 100;
            }
            else 
            {
                player_2_hp += 10;
            }

            printf("%s lost %d HP! %s gained 10 HP!\n", player_1_name, final_damage, player_2_name);
        }
        else if (player_1_choice == 1 && player_2_choice == 3)
        {
            printf("%s chose FIRE and %s chose EARTH!\n", player_1_name, player_2_name);
            
            final_damage = (int)(25 * damage_multiplier);
            
            player_2_hp -= final_damage;
            
            printf("%s lost %d HP!\n", player_2_name, final_damage);
        }
        else if (player_1_choice == 2 && player_2_choice == 1)
        {
            printf("%s chose WATER and %s chose FIRE!\n", player_1_name, player_2_name);
            
            final_damage = (int)(5 * damage_multiplier);
            
            player_2_hp -= final_damage;
            
            if (player_1_hp > 90) 
            {
                player_1_hp = 100;
            }
            else 
            {
                player_1_hp += 10;
            }

            printf("%s lost %d HP! %s gained 10 HP!\n", player_2_name, final_damage, player_1_name);
        }
        else if (player_1_choice == 2 && player_2_choice == 2)
        {
            printf("Both %s and %s chose WATER!\n", player_1_name, player_2_name);
            
            printf("Both players gain 5 HP!\n");
            
            if (player_1_hp > 95 && player_2_hp > 95)
            {
                player_1_hp = 100;
                player_2_hp = 100;
            }
            else if (player_1_hp > 95 && player_2_hp <= 95)
            {
                player_1_hp = 100;
                player_2_hp += 5;
            }
            else if (player_1_hp <= 95 && player_2_hp > 95)
            {
                player_1_hp += 5;
                player_2_hp = 100;
            }
            else 
            {
                player_1_hp += 5;
                player_2_hp += 5;
            }
        }
        else if (player_1_choice == 2 && player_2_choice == 3)
        {
            printf("%s chose WATER and %s chose EARTH!\n", player_1_name, player_2_name);
            
            final_damage = (int)(10 * damage_multiplier);
            
            player_1_hp -= final_damage;

            printf("%s lost %d HP!\n", player_1_name, final_damage);
        }
        else if (player_1_choice == 3 && player_2_choice == 1)
        {
            printf("%s chose EARTH and %s chose FIRE!\n", player_1_name, player_2_name);
            
            final_damage = (int)(25 * damage_multiplier);
            
            player_1_hp -= final_damage;
            
            printf("%s lost %d HP!\n", player_1_name, final_damage);
        }
        else if (player_1_choice == 3 && player_2_choice == 2)
        {
            printf("%s chose EARTH and %s chose WATER!\n", player_1_name, player_2_name);
            
            final_damage = (int)(10 * damage_multiplier);
            
            player_2_hp -= final_damage;
            
            printf("%s lost %d HP!\n", player_2_name, final_damage);
        }
        else if (player_1_choice == 3 && player_2_choice == 3)
        {
            printf("Both %s and %s chose EARTH\n", player_1_name, player_2_name);
            
            printf("Both players gain 10 HP!\n");
            
            if (player_1_hp > 90 && player_2_hp > 90)
            {
                player_1_hp = 100;
                player_2_hp = 100;
            }
            else if (player_1_hp > 90 && player_2_hp <= 90)
            {
                player_1_hp = 100;
                player_2_hp += 10;
            }
            else if (player_1_hp <= 90 && player_2_hp > 90)
            {
                player_1_hp += 10;
                player_2_hp = 100;
            }
            else 
            {
                player_1_hp += 10;
                player_2_hp += 10;
            }
        }
        
        game_round++;

        printf("\nPress Enter to view next round transitions...\n");
        while (getchar() != '\n');
        
        system("cls"); 
        
        printf("Pass the controls to %s.\n", player_1_name);
        printf("Press Enter when %s is ready...", player_1_name);
        getchar();
        
        system("cls");
    }
    
    if (player_1_hp > 0 && player_2_hp <= 0)
    {
        printf("Congratulations! %s has defeated their opponent %s!\n", player_1_name, player_2_name);
    }
    else if (player_1_hp <= 0 && player_2_hp > 0)
    {
        printf("Congratulations! %s has defeated their opponent %s!\n", player_2_name, player_1_name);
    }
    else 
    {
        printf("Its a TIE!\n");
    }
    
    return 0;
}