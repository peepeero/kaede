#include <iostream>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>
#include <limits>

void makeTheSign(int (&b)[4])
{
     b[0] = rand() % 8;
    b[1] = rand() % 8;
    b[2] = rand() % 8;
}

int calculateAnswer(int (&a)[5], int (&b)[4])
{
   int answer = a[0];
   for (int i = 0; i < 4; ++i)
   {
       answer = b[i] > 3 ? answer + a[i+1] : answer - a[i+1];
   }
   return answer;
}


int main(int argc, char *argv[])
{
    int a[5];
    int b[4];
    srand(std::time(nullptr));
    a[0] = argc < 2 ? rand() % 10 : rand() % 50 + 30;
    a[4] = argc < 2 ? rand() % 10 : rand() % 50  + 30;
    a[1] = rand() % 10;
    a[2] = rand() % 10;
    a[3] = rand() % 10;
    int answer;

    while (true)
    {
        makeTheSign(b);
        answer = calculateAnswer(a, b);
        if (answer > 0)
        {
            break;
        }
    }
    std::system("clear");
    std::cout << a[0] << std::endl;
    sleep(2);
    for (int i = 0; i < 4; ++i)
    {
        std::system("clear");
        if (b[i] > 3)
        {
            std::cout << "+"  << a[i+1] << std::endl;
        }
        else
        {
            std::cout << "-" << a[i+1] << std::endl;
        }
        sleep(2);
    }

    int guess;
    std::cout << "Enter your guess" << std::endl;
    while (true)
    {
        std::cin >> guess;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "only input numners" << std::endl;
        }
        else
        {
            break;
        }

    }
    if(guess == answer)
    {
        std::cout << "Congratulations you passed" << std::endl;
    }
    else
    {
        std::cout << "Wrong, the correct answer is " << answer << std::endl; 
    }
}