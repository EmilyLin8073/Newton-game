/* ------------------------------------------------------------------------------------------
 wlin48Prog3.cpp

 Program #3: Newton game to get 5 in a row.
             Players alternate placing a piece or
             rotating a column.
 Class: CS 141
 Author: Emily, Lin
 Lab: Tues 1pm
 System: C++ Mac Xcode
 ------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cctype>
using namespace std;

const int boardSize = 41;


void displayHeader();
char assignBoardWithOriginalElement(char board[]);
void displayBoard();
char assignBoardForX(char userInput1, char board[]);
char assignBoardForO(char userInput1, char board[]);
void rotateTheBoard(char userInput2, char board[]);
bool checkVerticalWin(char board[]);
bool checkHorizontalWin(char board[]);
bool checkDiagonalWin(char board[]);
bool columnIsFull(char userInput1, char board[]);


//In ths function, we are going to print out the header and the game rule
void displayHeader()
{
   cout << "Author : Emily Lin \n"
        << "Class : CS 141, Spring 2018 \n"
        << "Lab: Tues 1pm               \n"
        << "Program: #3, Newton Game    \n"
        << "Xcode on a Mac              \n"
        << endl;

   cout << "Welcome to the game of Newton, where you try to be the first       \n"
        << "to get 5 in a row either vertically, horizontally or diagonally.  \n"
        << "Two players alternate making moves.  On each turn you may enter   \n"
        << "the column number where your piece will be placed, where that     \n"
        << "piece is inserted from the top and slides down as far as it can   \n"
        << "go in that column.  You may also enter 'r' to rotate a piece out  \n"
        << "of the bottom of a column to be dropped back in at the top of     \n"
        << "that column.  Enter 'x' to exit.                                  \n"
        << endl << endl << endl;
}


//In this function, we are going to print out the board
//change into loop
void displayBoard(char board[])
{
   cout << endl;
   cout << " 1   2   3   4   5   \n"
   << "--- --- --- --- --- \n"
   << " " << board[1] << "   " << board[2] << "   " << board[3] << "   " << board[4] << "   " << board[5] << endl
   << " " << board[6] << "   " << board[7] << "   " << board[8] << "   " << board[9] << "   " << board[10] << endl
   << " " << board[11] << "   " << board[12] << "   " << board[13] << "   " << board[14] << "   " << board[15] << endl
   << " " << board[16] << "   " << board[17] << "   " << board[18] << "   " << board[19] << "   " << board[20] << endl
   << " " << board[21] << "   " << board[22] << "   " << board[23] << "   " << board[24] << "   " << board[25] << endl
   << " " << board[26] << "   " << board[27] << "   " << board[28] << "   " << board[29] << "   " << board[30] << endl
   << " " << board[31] << "   " << board[32] << "   " << board[33] << "   " << board[34] << "   " << board[35] << endl
   << " " << board[36] << "   " << board[37] << "   " << board[38] << "   " << board[39] << "   " << board[40] << endl
   << "--- --- --- --- --- \n"
   << " 1   2   3   4   5  \n"
   << endl;
}


//In this function, we are going to assign each board slot to '.'
char assignBoardWithOriginalElement(char board[boardSize])
{
   //The for loop will continue until all the board slot are '.'
   for(int i = 1; i < boardSize; i++)
      board[i] = '.';
   
   return 0;
}


//In this function, we are going to assign the board slot into 'X' based on the user input
char assignBoardForX(char userInput1, char board[])
{
   //For each column, if user input are number 1 through 5, then we assign 'X' to the location
   switch(userInput1)
   {
      case '1':
         for(int i = 36; i >= 1; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'X';
               break;
            }
         }
         break;

      case '2':
         for(int i = 37; i >= 2; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'X';
               break;
            }
         }
         break;

      case '3':
         for(int i = 38; i >= 3; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'X';
               break;
            }
         }
         break;

      case '4':
         for(int i = 39; i >= 4; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'X';
               break;
            }
         }
         break;

      case '5':
         for(int i = 40; i >= 5; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'X';
               break;
            }
         }
         break;
   }
   return *board;
}


//In this function, we are going to assign the board slot into 'X' based on the user input
char assignBoardForO(char userInput1, char board[])
{
   //For each column, if user input are number 1 through 5, then we assign 'X' to the location
   switch(userInput1)
   {
      case '1':
         for(int i = 36; i >= 1; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'O';
               break;
            }
         }
         break;

      case '2':
         for(int i = 37; i >= 2; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'O';
               break;
            }
         }
         break;

      case '3':
         for(int i = 38; i >= 3; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'O';
               break;
            }
         }
         break;

      case '4':
         for(int i = 39; i >= 4; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'O';
               break;
            }
         }
         break;

      case '5':
         for(int i = 40; i >= 5; i = i - 5)
         {
            if(board[i] == '.')
            {
               board[i] = 'O';
               break;
            }
         }
         break;
   }
   return 0;
}


//In this function, if user enter r, we are going to swap the column
void rotateTheBoard(char userInput2, char board[])
{
   int column1DotCount = 0;

   //If user want to swap column 1, the following code will be executed
   switch(userInput2)
   {
      case '1':
         //Run through column and count how many element are there whcih are not '.'
         for(int i = 1; i < 37; i = i + 5)
         {
            //If the element of the board is not '.', we add up column1DotCount
            if(board[i] != '.')
            {
               column1DotCount++;

               //For the column1DotCount we have, we divided into half
               for(int j = 0; j < column1DotCount - 1; j++)
               {
                  char temp = board[i];
                  //cout << temp << endl;
                  board[i] = board[i-5];
                  board[i-5] = temp;
               }
            }
         }
         break;

      case '2':
         //Run through column and count how many element are there whcih are not '.'
         for(int i = 37; i > 3; i = i - 5)
         {
            //If the element of the board is not '.', we add up column1DotCount
            if(board[i] != '.')
            {
               column1DotCount++;
               //For the column1DotCount we have, we divided into half
               for(int j = 0; j < column1DotCount - 1; j++)
               {
                  char temp = board[i];
                  board[i] = board[i+5];
                  board[i+5] = temp;
               }
            }
         }
         break;

      case '3':
         //Run through column and count how many element are there whcih are not '.'
         for(int i = 38; i > 4; i = i - 5)
         {
            //If the element of the board is not '.', we add up column1DotCount
            if(board[i] != '.')
            {
               column1DotCount++;
               //For the column1DotCount we have, we divided into half
               for(int j = 0; j < column1DotCount - 1; j++)
               {
                  char temp = board[i];
                  board[i] = board[i+5];
                  board[i+5] = temp;
               }
            }
         }
         break;

      case '4':
         //Run through column and count how many element are there whcih are not '.'
         for(int i = 39; i > 5; i = i - 5)
         {
            //If the element of the board is not '.', we add up column1DotCount
            if(board[i] != '.')
            {
               column1DotCount++;
               //For the column1DotCount we have, we divided into half
               for(int j = 0; j < column1DotCount - 1; j++)
               {
                  char temp = board[i];
                  board[i] = board[i+5];
                  board[i+5] = temp;
               }
            }
         }
         break;

      case '5':
         //Run through column and count how many element are there whcih are not '.'
         for(int i = 40; i > 6; i = i - 5)
         {
            //If the element of the board is not '.', we add up column1DotCount
            if(board[i] != '.')
            {
               column1DotCount++;
               //For the column1DotCount we have, we divided into half
               for(int j = 0; j < column1DotCount - 1; j++)
               {
                  char temp = board[i];
                  board[i] = board[i+5];
                  board[i+5] = temp;
               }
            }
         }
         break;
   }
}


//In this function, we are going to check vertical win
bool checkVerticalWin(char board[])
{
   for(int i = 36; i >= 2; i = i - 5)
   {
      if(board[i] == board[i-5] && board[i-5] == board[i-10] && board[i-10] == board[i-15] && board[i-15] == board[i-20] && board[i] != '.')
         return true;
   }

   for(int i = 37; i >= 3; i = i - 5)
   {
      if(board[i] == board[i-5] && board[i-5] == board[i-10] && board[i-10] == board[i-15] && board[i-15] == board[i-20] && board[i] != '.')
         return true;
   }

   for(int i = 38; i >= 4; i = i - 5)
   {
      if(board[i] == board[i-5] && board[i-5] == board[i-10] && board[i-10] == board[i-15] && board[i-15] == board[i-20] && board[i] != '.')
         return true;
   }

   for(int i = 39; i >= 5; i = i - 5)
   {
      if(board[i] == board[i-5] && board[i-5] == board[i-10] && board[i-10] == board[i-15] && board[i-15] == board[i-20] && board[i] != '.')
         return true;
   }

   for(int i = 40; i >= 6; i = i - 5)
   {
      if(board[i] == board[i-5] && board[i-5] == board[i-10] && board[i-10] == board[i-15] && board[i-15] == board[i-20] && board[i] != '.')
         return true;
   }

   return false;
}


//In this function, we are going to check the horizontal win
bool checkHorizontalWin(char board[])
{
    for(int i = 1; i < 6; i++)
    {
       if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
       {
          return true;
       }
       for(int i = 6; i < 11; i++)
       {
          if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
          {
             return true;
          }
          for(int i = 11; i < 16; i++)
          {
             if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
             {
                return true;
             }
             for(int i = 16; i < 21; i++)
             {
                if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
                {
                   return true;
                }
                for(int i = 21; i < 26; i++)
                {
                   if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
                   {
                      return true;
                   }
                   for(int i = 26; i < 31; i++)
                   {
                      if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
                      {
                         return true;
                      }
                      for(int i = 31; i < 36; i++)
                      {
                         if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
                         {
                            return true;
                         }
                         for(int i = 36; i < 41; i++)
                         {
                            if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] == board[i+3] && board[i+3] == board[i+4] && board[i] != '.')
                            {
                               return true;
                            }
                         }
                      }
                   }
                }
             }
          }
       }
    }
   return false;

}


//In this function, we are going to check the diagonal win
bool checkDiagonalWin(char board[])
{
   int diagonal1 = board[21] + board[17] + board[13] + board[9] + board[5];
   int diagonal2 = board[26] + board[22] + board[18] + board[14] + board[10];
   int diagonal3 = board[31] + board[27] + board[23] + board[19] + board[15];
   int diagonal4 = board[36] + board[32] + board[28] + board[24] + board[20];

   int diagonal5 = board[1] + board[7] + board[13] + board[19] + board[25];
   int diagonal6 = board[6] + board[12] + board[18] + board[24] + board[30];
   int diagonal7 = board[11] + board[17] + board[23] + board[29] + board[35];
   int diagonal8 = board[16] + board[22] + board[28] + board[34] + board[40];



   //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
   if(diagonal4 != 230)
   {
      if(board[36] == board[32] && board[32] == board[28] && board[28] == board[24] && board[24] == board[20])
      {
         return true;
      }
      //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
      else if(diagonal3 != 230)
      {
         if(board[31] == board[27] && board[27] == board[23] && board[23] == board[19] && board[19] == board[15])
         {
            return true;
         }
         //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
         else if(diagonal2 != 230)
         {
            if(board[26] == board[22] && board[22] == board[18] && board[18] == board[14] && board[14] == board[10])
            {
               return true;
            }
            //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
            else if(diagonal1 != 230)
            {
               if(board[21] == board[17] && board[17] == board[13] && board[13] == board[9] && board[9] == board[5])
               {
                  return true;
               }
               //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
               else if(diagonal8 != 230)
               {
                  if(board[16] == board[22] && board[22] == board[28] && board[28] == board[34] && board[34] == board[40])
                  {
                     return true;
                  }
                  //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
                  else if(diagonal7 != 230)
                  {
                     if(board[11] == board[17] && board[17] == board[23] && board[23] == board[29] && board[29] == board[35])
                     {
                        return true;
                     }
                     //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
                     else if(diagonal6 != 230)
                     {
                        if(board[6] == board[12] && board[12] == board[18] && board[18] == board[24] && board[24] == board[30])
                        {
                           return true;
                        }
                        //If the diagonal is not equal to 230, we check if there are 5 X or 5 O
                        else if(diagonal5 != 230)
                        {
                           if(board[1] == board[7] && board[7] == board[13] && board[13] == board[19] && board[19] == board[25])
                           {
                              return true;
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }
    return false;
}


bool columnIsFull(char userInput1, char board[])
{
   switch(userInput1)
   {
      case '1':
         if(board[1] != '.') return true;
         break;

      case '2':
         if(board[2] != '.') return true;
         break;

      case '3':
         if(board[3] != '.') return true;
         break;

      case '4':
         if(board[4] != '.') return true;
         break;

      case '5':
         if(board[5] != '.') return true;
         break;
   }
   
   return false;
}


int main()
{
   char userInput1;
   char userInput2;
   char board[boardSize];

   displayHeader();
   assignBoardWithOriginalElement(board);
   displayBoard(board);

   //Count how many time does the game have been played and it start with 1
   int playCount = 1;

   //Loop that will read in user input and do the corresponding action
   do
   {
      //If the playCount is odd, it means it's X turn. If the playCount is even, it means it's O turn
      if(playCount % 2 == 1)
         cout << playCount << ". Enter column number to place X or 'r' to rotate: ";
      else
         cout << playCount << ". Enter column number to place O or 'r' to rotate: ";


      //Read in first char for the user Input and transfer into upper char
      cin >> userInput1;
      userInput1 = toupper(userInput1);

      //If the first char of userInput is 'X', we quit the game
      if(userInput1 == 'X')
      {
         break;
      }
      else if(userInput1 == 'R') // If the first char of userInput is 'R', we read in the second char
      {
         cin >> userInput2;

         rotateTheBoard(userInput2, board);

         displayBoard(board);
         playCount ++;
         continue;
      }
      else if(userInput1 > '5' /*inputNotValid need fix*/) //If the first userInput is out of range of the board, we print out statement and continue the game
      {
         cout << endl << "*** Invalid input.  Please retry..." << endl;
         continue;
      }
      else if(columnIsFull(userInput1, board)) //Check the cloumn is full or not
      {
         cout << endl << "*** Sorry, that column is already full.  Please choose another." << endl;
         continue;
      }
      else //Assign X or O to the correspond position
      {
         if(playCount % 2 == 1)
            assignBoardForX(userInput1, board);
         else
            assignBoardForO(userInput1, board);

         displayBoard(board);
         playCount ++;
      }

      //Check the win condition, if the condition meet, print the statement
      if(checkVerticalWin(board) || checkHorizontalWin(board) || checkDiagonalWin(board))
      {
         if(playCount % 2 == 0)
            cout << "\n*** Congratulations X, you win! ***" << endl;
         else
            cout << "\n*** Congratulations O, you win! ***" << endl;
         break;
      }
   }while(true);

   cout << endl << "Thank you for playing.  Exiting... " << endl;
}


























