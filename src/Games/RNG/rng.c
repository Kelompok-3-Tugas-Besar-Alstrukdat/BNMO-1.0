#include "rng.h"

int RandomNumber()
{
    srand(time(0));
    int num = rand();
    return num;
}

int main()
{

}