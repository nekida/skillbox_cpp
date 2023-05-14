int main ()
{
    int cutlery[2][6] = {
        {3, 3, 3, 3, 3, 4},
        {3, 3, 3, 3, 3, 4}
    };

    int dishes[2][6] = {
        {2, 2, 2, 2, 2, 3},
        {2, 2, 2, 2, 2, 3}
    };

    int chairs[2][6] = {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };

    chairs[0][4] += 1;
    cutlery[1][2] -= 1;
    cutlery[0][5] -= 1;
    cutlery[1][2] += 1;
    dishes[0][5] -= 1;

    return 0;
}
