
class X_o
{
public:
    char symbole;
    int choises[5]{}, i_conteur = 0;
    std::list<int> intervale{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int win_combinitions[8][3]{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 5, 9}, {3, 5, 7}};
    void sort()
    {
        int tmp;
        for (int s = 0; s < i_conteur - 1; s++)
        {
            for (int i = s + 1; i < i_conteur; i++)
            {
                if (choises[i] < choises[s])
                {
                    tmp = choises[s];
                    choises[s] = choises[i];
                    choises[i] = tmp;
                }
            }
        }
    }
    int check_winner()
    {
        int truee[3]{0, 0, 0};
        if (i_conteur >= 3)
        {
            sort();
            for (int i = 0; i < 8; i++)
            {
                    for (int j = 0; j < 3; j++)
                    {
                        int s = 0;
                        while (s < i_conteur && win_combinitions[i][j] != choises[s])
                            s++;
                        if (win_combinitions[i][j] == choises[s])
                            truee[j] = 1;
                    }
                    if (truee[0] && truee[1] && truee[2])
                        return 1;
                    else
                    {
                        truee[0] = 0;
                        truee[1] = 0;
                        truee[2] = 0;
                    }
            }
        }
        else
            return 0;
        return 0;
    }
};

class Player : public X_o
{
public:
    Player() = default;
    Player(std::list<int> Intervale, char Symbole, int I_conteur, int Choises[5])
    {
        intervale = Intervale;
        symbole = Symbole;
        i_conteur = I_conteur;
        for (int i = 0; i < i_conteur; i++)
            choises[i] = Choises[i];
    }

    void show(int the_player_choise, char tamplate_2[3][20])
    {
        int j;
        if (the_player_choise < 4)
            j = 0;
        else
            j = (the_player_choise > 3 && the_player_choise < 7) ? 1 : 2;
        for (int i = 0; i < 19; i++)
        {
            if ((tamplate_2[j][i] - '0') == the_player_choise)
            {
                tamplate_2[j][i] = symbole;
                break;
            }
        }
    }
    int chose_place()
    {
        int chosen;
        bool in = false;
        do
        {
            std::cout << "chose number betwen 1..9 :)" << std::endl;
            std::cin >> chosen;
            for (auto &s : intervale)
                if (s == chosen)
                {
                    in = true;
                    intervale.remove(s);
                    break;
                }
        } while (!in);
        choises[i_conteur] = chosen;
        i_conteur++;
        return chosen;
    }
};

class Pc : public X_o
{
public:
    Pc() = default;
    Pc(std::list<int> Intervale, char Symbole, int I_conteur, int Choises[5])
    {
        intervale = Intervale;
        symbole = Symbole;
        i_conteur = I_conteur;
        for (int i = 0; i < i_conteur; i++)
            choises[i] = Choises[i];
    }
    void show(int the_pc_choise, char tamplate_2[3][20])
    {
        int j;
        if (the_pc_choise < 4)
            j = 0;
        else
            j = (the_pc_choise > 3 && the_pc_choise < 7) ? 1 : 2;
        for (int i = 0; i < 19; i++)
        {
            if ((tamplate_2[j][i] - '0') == the_pc_choise)
            {
                tamplate_2[j][i] = symbole;
                break;
            }
        }
    }
    int chose_place()
    {
        srand(time(NULL));
        int choise;
        bool in = false;
        do
        {
            choise = rand() % 9 + 1;
            for (auto &s : intervale)
                if (s == choise)
                {
                    in = true;
                    intervale.remove(s);
                    break;
                }
        } while (!in);
        choises[i_conteur] = choise;
        i_conteur++;
        return choise;
    }
};