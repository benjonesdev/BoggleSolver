
//if current letter is on one of the four corner
//next move can be
void onCorner()
{
    int nextMove;
    if(x == 0 && y == 0)
    {
        //next move can be
        nextMove = rand() % 3;
        switch (nextMove)
        {
            case 0:
                x += 1;
                break;
            case 1: y += 1;
                break;
            case 2:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 3 && y == 0)
    {
        nextMove = rand() % 3;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                y += 1;
            case 2:
                x -= 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 0 && y== 3)
    {
        nextMove = rand() % 3;
        switch(nextMove)
        {
            case 0:
                y -= 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                y -= 1;
                x += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 3 && y == 3)
    {
        nextMove = rand() % 3;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                y -= 1;
                break;
            case 2:
                x -= 1;
                y -= 1;
                break;
            default:
                break;
        }
    }
}


//if current letter is on edge or in the middle
//next move can be 
void EdgeMiddle()
{
    if(y == 0)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x += 1;
                break;
            case 1:
                x -= 1;
                break;
            case 2:
                y += 1;
                break;
            case 3:
                x -= 1;
                y += 1;
                break;
            case 4:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if(x == 0)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x += 1;
                break;
            case 1:
                y += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                x += 1;
                y -= 1;
                break;
            case 4:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
    }
    else if( y == 3)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                x -= 1;
                y -= 1;
                break;
            case 4:
                x += 1;
                y -= 1;
                break;
            default:
                break;
        }
    }
    else if(x == 3)
    {
        nextMove = rand() % 5;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                y -= 1;
                break;
            case 2:
                y += 1;
                break;
            case 3:
                x -= 1;
                y += 1;
                break;
            case 4:
                x -= 1;
                y -= 1;
                break;
            default:
                break;
        }
    }
    else
    {
        nextMove = rand() % 8;
        switch(nextMove)
        {
            case 0:
                x -= 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                y += 1;
                break;
            case 4:
                x -= 1;
                y -= 1;
                break;
            case 5:
                x -= 1;
                y += 1;
                break;
            case 6:
                x += 1;
                y -= 1;
                break;
            case 7:
                x += 1;
                y += 1;
                break;
            default:
                break;
        }
}

    static const char DICE[16][6] = {
    'A', 'A', 'E', 'E', 'G', 'N', 'A', 'B', 'B', 'J', 'O', 'O', 'A', 'C', 'H', 'O', 'P', 'S',
    'A', 'F', 'F', 'K', 'P', 'S', 'A', 'O', 'O', 'T', 'T', 'W', 'C', 'I', 'M', 'O', 'T', 'U', 'D',
    'E', 'I', 'L', 'R', 'X', 'D', 'E', 'L', 'R', 'V', 'Y', 'D', 'I', 'S', 'T', 'T', 'Y', 'E', 'E',
    'G', 'H', 'N', 'W', 'E', 'E', 'I', 'N', 'S', 'U', 'E', 'H', 'R', 'T', 'V', 'W', 'E', 'I', 'O', 'S', 'S', 'T', 'E', 'L', 'R', 'T', 'T', 'Y', 'H', 'I', 'M', 'N', 'Q', 'U', 'H', 'L', 'N', 'N', 'R', 'Z'};
int main() {
    // Prints out contents of all dice
    for (int i = 0; i < 16; i++) {
        for(int j = 0; j < 6; j++)
        {
            std::cout << DICE[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    //pick a letter from each dice using random function, rand() % 5 + 0;
    //print  boggle board
    srand(time(0));
    int dice = 0;
    int r;
    std::cout << "Here is the boggle board generated randomly based on the letters of each dice: \n";
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            r = rand() % 5 + 1;
            //std::cout <<"random number is " << r << std::endl;
            std::cout << DICE[dice][r] << " ";
            dice ++;
        }
        std::cout << std::endl;
    }
    
    //use to calculate points
    std::string guessWord;
    
//first you can pick up a location within the board, then you only can select the letters adjacent to the previous one
    //first select a start point
    int x;
    int y;
    x = rand() % 4;
    y = rand() % 4;
    int nextMove;
    
    
    
    
   

//then try to check if there is a valid word by compare within the word of dictionary
    std::string word; //valid word
    int points = 0;

    while(!input.eof())
    {
        input >> word;
        if(guessWord == word)
        {
            if(guessWord.length() <= 2)
            {
                points += 0;
            }
            else if(guessWord.length() <= 4)
            {
                points += 1;
            }
            else if(guessWord.length() <= 5)
            {
                points += 2;
            }
            else if(guessWord.length() <= 6)
            {
                points += 3;
            }
            else if(guessWord.length() <= 7)
            {
                points += 5;
            }
            else
            {
                points += 11;
            }
        }
    }
    
    return 0;
}


