#include <stdio.h> 

int main()
{
    char player_1_name[50];
    char player_2_name[50];
    
    int game_round = 1;
    
    int player_1_hp = 100;
    int player_2_hp = 100;

    int player_1_ep = 0;
    int player_2_ep = 0;

    int choice;
    int game_winner = 0; 
    
    printf("\n\n");

    printf("\033[1;33m<-------Welcome to Energy Duel!------->\033[0m\n");
    
    printf("\n\n");
    
    printf("Rules: \n\n");
    printf("1. This is a two player game which involves logic and battle skills.\n");
    printf("2. Both the players start at 100 hp(health points) and 0 ep (energy points).\n");
    printf("3. Player 1 starts first and chooses the attack type.\n");
    printf("4. The attack types are the following: \n");
    printf("    (a) Light attack: Costs 1 Energy. Deals 10 damage to the opponent.\n");
    printf("    (b) Heavy attack: Costs 3 Energy. Deals 35 massive damage to the opponent.\n");
    printf("    (c) Charge: Gain 2 Energy points. (Does not cost any ep)\n"); 
    printf("5. After player 1, player 2 chooses their attack type.\n");
    printf("6. The game continues until a player looses all their hp.\n");

    printf("\n\n");

    printf("Player name can not contain any spaces!\n");
    printf("Enter Player 1 name: ");
    scanf("%s", player_1_name);
    printf("Enter Player 2 name: ");
    scanf("%s", player_2_name);

    while (player_1_hp > 0 && player_2_hp > 0)
    {
        printf("\n-----------------------------------------\n");
        printf("               ROUND %d                  \n", game_round);
        printf("-----------------------------------------\n\n");
        
        if (game_round == 1)
        {
            printf("\033[1;32m%s starts first!\033[0m\n", player_1_name);
        }
        else
        {
            printf("\n\n\033[1;32mNow it is %s's turn!\033[0m\n", player_1_name);
        }
        
        printf("%s's Stats: \n", player_1_name);
        printf("---> | HP: %d | EP: %d <---\n", player_1_hp, player_1_ep);
        
        printf("Enemy's Stats: \n");
        printf("---> | HP: %d | EP: %d <---\n\n", player_2_hp, player_2_ep);
        
        printf("(1 -- Light attack) [Requires 1 ep]\n(2 -- Heavy attack) [Requires 3 ep]\n(3 -- Charge)\n");
       
        printf("Enter the number of the desired attack: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (player_1_ep >=1)
            {
                printf("%s used Light attack on %s!\n", player_1_name, player_2_name);
                printf("\033[1;31m%s's hp got decreased by 10!\033[0m\n", player_2_name);
                player_2_hp -= 10;
                player_1_ep -= 1;
            }
            else
            {
                printf("\033[1;35mNot enough energy! Turn wasted!\033[0m\n");
            }
        }
        else if (choice == 2)
        {
            if (player_1_ep >=3)
            {
                printf("%s used Heavy attack on %s!\n", player_1_name, player_2_name);
                printf("\033[1;31m%s's hp got decreased by 35!\033[0m\n", player_2_name);
                player_2_hp -= 35;
                player_1_ep -= 3;
            }
            else
            {
                printf("\033[1;35mNot enough energy! Turn wasted!\033[0m\n");
            }
        }
        else if (choice == 3)
        {
            printf("%s used Charge!\n", player_1_name);
            printf("\033[1;36mThe ep of %s got increased by 2!\033[0m\n", player_1_name);
            player_1_ep += 2;
        }
        else
        {
            printf("\033[1;35mInvalid choice! Turn wasted!\033[0m\n");
        }
        
        if (player_2_hp <= 0)
        {
            game_winner = 1;
            break;
        }

        choice = 0;

        
        printf("\n\n\033[1;36mNow it is %s's turn!\033[0m\n", player_2_name);
        
        printf("%s's Stats: \n", player_2_name);
        printf("---> | HP: %d | EP: %d <---\n\n", player_2_hp, player_2_ep);

        printf("Enemy's Stats: \n");
        printf("---> | HP: %d | EP: %d <---\n\n", player_1_hp, player_1_ep);
        
        printf("(1 -- Light attack) [Requires 1 ep]\n(2 -- Heavy attack) [Requires 3 ep]\n(3 -- Charge)\n");
       
        printf("Enter the number of the desired attack: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (player_2_ep >=1)
            {
                printf("%s used Light attack on %s!\n", player_2_name, player_1_name);
                printf("\033[1;31m%s's hp got decreased by 10!\033[0m\n", player_1_name);
                player_1_hp -= 10;
                player_2_ep -= 1;
            }
            else
            {
                printf("\033[1;35mNot enough energy! Turn wasted!\033[0m\n");
            }
        }
        else if (choice == 2)
        {
            if (player_2_ep >=3)
            {
                printf("%s used Heavy attack on %s!\n", player_2_name, player_1_name);
                printf("\033[1;31m%s's hp got decreased by 35!\033[0m\n", player_1_name);
                player_1_hp -= 35;
                player_2_ep -= 3;
            }
            else
            {
                printf("\033[1;35mNot enough energy! Turn wasted!\033[0m\n");
            }
        }
        else if (choice == 3)
        {
            printf("%s used Charge!\n", player_2_name);
            printf("\033[1;36mThe ep of %s got increased by 2!\033[0m\n", player_2_name);
            player_2_ep += 2;
        }
        else
        {
            printf("\033[1;35mInvalid choice! Turn wasted!\033[0m\n");
        }
        
        game_round++;
        printf("\n\n");
        
        if (player_1_hp <= 0)
        {
            game_winner = 2;
            break;
        }
    }

    printf("\n\n==========================================================\n");
    
    if (game_winner == 1)
    {
        printf("\033[1;32mCongratulations! %s has defeated their opponent %s!\033[0m\n", player_1_name, player_2_name);
    }
    else if (game_winner == 2)
    {
        printf("\033[1;32mCongratulations! %s has defeated their opponent %s!\033[0m\n", player_2_name, player_1_name);
    }
    printf("==========================================================\n");
    
    return 0;
}