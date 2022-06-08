#include <iostream>
#include <list>
#include <string>
#include "omar.h"

int main()
{
    Player player;
    Pc pc;
    int win=0;
    int the_player_choise, the_pc_choise, j = -1;
    char tamplate_1[2][20]{"-------------------", "|     |     |     |"};
    char tamplate_2[3][20]{"|  1  |  2  |  3  |", "|  4  |  5  |  6  |", "|  7  |  8  |  9  |"};

    do
    {
        std::cout << "chose X or O to play :)" << std::endl;
        std::cin >> player.symbole;
    } while (player.symbole != 'O' && player.symbole != 'o' && player.symbole != 'X' && player.symbole != 'x');
    if (std::isupper(player.symbole))
    {
        pc.symbole = (player.symbole == 'O') ? 'X' : 'O';
    }
    else
    {
        pc.symbole = (player.symbole == 'o') ? 'x' : 'o';
    }

    while (player.intervale.empty() != 1 && pc.intervale.empty() != 1&&!win)
    {
        if (player.intervale.empty() != 1)
            player.show(player.chose_place(), tamplate_2);

        pc = Pc(player.intervale, pc.symbole, pc.i_conteur, pc.choises);
        if (pc.intervale.empty() != 1)
            pc.show(pc.chose_place(), tamplate_2);

        player = Player(pc.intervale, player.symbole, player.i_conteur, player.choises);

        for (int i = 0; i < 3; i++)
        {
            std::cout << tamplate_1[0] << std::endl
                      << tamplate_1[1] << std::endl;
            std::cout << tamplate_2[i] << std::endl
                      << tamplate_1[1] << std::endl;
            if (i == 2)
                std::cout << tamplate_1[0] << std::endl;
        }
        if (player.check_winner()){
            std::cout << "player is the winner__________________________" << std::endl;
            win=1;
        }
        else if (pc.check_winner()){
            std::cout << "pc is the winner__________________________" << std::endl;
            win=1;
        }
    }
    if(!win)
        std::cout << "drow__________________________" << std::endl;

    return 0;
}