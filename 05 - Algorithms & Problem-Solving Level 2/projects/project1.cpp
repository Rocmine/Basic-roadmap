#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

enum enGameChoices
{
    Stone = 1,
    Paper,
    Scissor
};

// system("color 4F");
/*
 0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White
*/

enum EnGameBackColor
{
    Won = 2,
    Draw = 6,
    Lose = 4,
    Res = 0
};
enum enIsWinner
{
    Loser,
    Winner,
    drawer
};
enum enWhoIsWinner
{
    User,
    Computer,
    draw
};
struct stPlayers
{
    enGameChoices Choice;
    short NumberWon;
    enIsWinner Status;
};

struct stGameOverInfo

{
    short GameRounds;
    short Player1WonTimes;
    short ComputerWonTimes;
    short DrawTimes;
    enWhoIsWinner FinalWinner;

    void setGameOverValues(short Rounds, short Player1Won, short ComputerWon)
    {

        this->GameRounds = Rounds;
        this->Player1WonTimes = Player1Won;
        this->ComputerWonTimes = ComputerWon;
        this->FinalWinner = Player1Won > ComputerWon ? enWhoIsWinner::User : (Player1Won < ComputerWon ? enWhoIsWinner::Computer : enWhoIsWinner::draw);
    }
};

unsigned ReadPositiveNumber(string UserText)
{
    unsigned num = 0;

    do
    {
        cout << UserText;
        cin >> num;
    } while (num <= 0);
    return num;
}
int ReadNumberInRange(string UserText, const int Max, const int Min)
{
    int num = 0;
    do
    {
        cout << UserText;
        cin >> num; cin.ignore(); if (cin.fail()) throw runtime_error("Invalid  Value  you should enter A digit : ");

    } while (Max > num || Min < num);

    return num;
}

char ReadCharacter(string UserText)
{
    char Letter = ' ';
    cout << UserText;
    cin >> Letter;

    return Letter;
}

int GetRandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}

void ReadUserChoice(stPlayers &User)
{
    short UserChoice = 0;
    do
    {
        cout << "Your Choice : [1]:Stone ,[2]:paper ,[3]:Scissors ? ";
        cin >> UserChoice;cin.ignore();if (cin.fail())  throw runtime_error("You should enter a Digit  ");

    } while (UserChoice < enGameChoices::Stone || UserChoice > enGameChoices::Scissor);
    User.Choice = enGameChoices(UserChoice);
}

void ReadComputerChoice(stPlayers &Computer)
{
    Computer.Choice = enGameChoices(GetRandomNumber(1, 3));
}

bool WinCases(stPlayers wonPlayer, stPlayers LosePlayer)
{

    return ((wonPlayer.Choice == enGameChoices::Stone && LosePlayer.Choice == enGameChoices::Scissor) || (wonPlayer.Choice == enGameChoices::Paper && LosePlayer.Choice == enGameChoices::Stone) || (wonPlayer.Choice == enGameChoices::Scissor && LosePlayer.Choice == enGameChoices::Paper));
}

enWhoIsWinner CheckWinner(const stPlayers User, const stPlayers Computer)
{

    if (WinCases(User, Computer))
        return enWhoIsWinner::User;
    else if (WinCases(Computer, User))
        return enWhoIsWinner::Computer;
    else
        return enWhoIsWinner::draw;
}

void SetRoundResult(short &NUmberOfRound, stPlayers &User, stPlayers &Computer, enWhoIsWinner Winner, stGameOverInfo &GameInfo)
{
    NUmberOfRound--;

    if (Winner == enWhoIsWinner::User)
    {
        User.NumberWon++;

        Computer.Status = enIsWinner::Loser;
        User.Status = enIsWinner::Winner;
    }
    else if (Winner == enWhoIsWinner::Computer)
    {

        Computer.NumberWon++;
        Computer.Status = enIsWinner::Winner;
        User.Status = enIsWinner::Loser;
    }
    else
    {
        User.Status = enIsWinner::Loser;
        Computer.Status = enIsWinner::Loser;
        User.Status = Computer.Status = enIsWinner::drawer;
        GameInfo.DrawTimes++;
    }
}
void changeColor(EnGameBackColor BackColor)
{

    string backSystemInstruction = "color " + to_string(BackColor) + "F";
    system(backSystemInstruction.data());
}

void ManageRoundResult(stPlayers &User, stPlayers &Computer, short NumberOfRound, stGameOverInfo &GameInfo)
{

    enWhoIsWinner Winner = CheckWinner(User, Computer);

    SetRoundResult(NumberOfRound, User, Computer, Winner, GameInfo);
}

void PrintRoundResult(stPlayers User, stPlayers Computer, short RoundIndex)
{

    string ArrGameChoices[4] = {"", "Stone ", "Paper", "Scissor"};

    if (User.Status == enIsWinner::Winner)
        changeColor(EnGameBackColor::Won);
    else if (Computer.Status == enIsWinner::Winner)
    {
        changeColor(EnGameBackColor::Lose);
    }

    else
        changeColor(EnGameBackColor::Draw);
    cout << "\n\n____________Round[" << RoundIndex << "]"
         << "____________\n";
    cout << "Player 1 Choice : " << ArrGameChoices[User.Choice] << "\n";
    cout << "Computer Choice : " << ArrGameChoices[Computer.Choice] << "\n";
    cout << "Round Winner    : " << (User.Status == enIsWinner::Winner ? "[User]" : (Computer.Status == enIsWinner::Winner ? "[Computer]" : "[No Winner]"));
    cout << "\n_______________________________\n";
}

void PrintGameOverResult(stGameOverInfo GameOver)
{

    if (GameOver.FinalWinner == enWhoIsWinner::User)
        changeColor(EnGameBackColor::Won);

    else if (GameOver.FinalWinner == enWhoIsWinner::Computer)
    {
        cout << "\a";
        changeColor(EnGameBackColor::Lose);
    }
    else
        changeColor(EnGameBackColor::Draw);

    cout << "\n\n\t\t_______________________________________________________________________________________\n\n";
    cout << "\t\t                             ++++ GAME OVER +++"
         << "\n";
    cout << "\t\t_______________________________[Game Results]__________________________________________\n\n";

    cout << "\t\tGame Rounds           : " << GameOver.GameRounds << "\n";
    cout << "\t\tPlayer1 won times     : " << GameOver.Player1WonTimes << "\n";
    cout << "\t\tComputer won times    : " << GameOver.ComputerWonTimes << "\n";
    cout << "\t\tDraw times            : " << GameOver.DrawTimes << "\n";
    cout << "\t\tFinal Winner    : " << (GameOver.FinalWinner == enWhoIsWinner::User ? "player1 " : (GameOver.FinalWinner == enWhoIsWinner::Computer ? "Computer" : "Draw")) << "\n";

    cout << "\t\t_________________________________________________________________________________________\n\n";
}

void GameSystem(short &NumberOfRound, stPlayers &User, stPlayers &Computer, stGameOverInfo &GameInfo)
{

    for (int i = 1; i <= NumberOfRound; i++)
    {
        ReadUserChoice(User);
        ReadComputerChoice(Computer);
        ManageRoundResult(User, Computer, NumberOfRound, GameInfo);
         _sleep(50); 
        PrintRoundResult(User, Computer, i);

    }
      _sleep(40); 
    GameInfo.setGameOverValues(NumberOfRound, User.NumberWon, Computer.NumberWon);
    PrintGameOverResult(GameInfo);
}

void InitializeGameObjects(stPlayers &User, stPlayers &Computer, stGameOverInfo &GameInfo)
{
    User.NumberWon = 0;
    Computer.NumberWon = 0;

    GameInfo.DrawTimes = 0;
    GameInfo.GameRounds = 0;
    GameInfo.Player1WonTimes = 0;
    GameInfo.ComputerWonTimes = 0;
}

int main()
{

    srand(time(NULL));
    stPlayers User, Computer;
    stGameOverInfo GameInfo;

    short NumberOfRound = 0;
    char WannaContinueGame = 'y';

    try
    {
        do
        {
            InitializeGameObjects(User, Computer, GameInfo);
            system("cls");
            changeColor(EnGameBackColor::Res);
            NumberOfRound = ReadNumberInRange("How many Rounds 1 to 10 ? ", 0, 10);

            GameSystem(NumberOfRound, User, Computer, GameInfo);

            WannaContinueGame = toupper(ReadCharacter("Do you Want to play the Game again? Y/N?"));

        } while (WannaContinueGame == 'Y');
    }
    catch (runtime_error e)
    {
        cin.clear();
        fflush(stdin);
        cout << "Error : " << e.what() << endl;
    }
    changeColor(EnGameBackColor::Res);

    return 0;
}
