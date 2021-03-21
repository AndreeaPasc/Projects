int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int *p, sum = 0;

    for(p = &a[0][0]; p< &a[0][0] + n; p++)
    {
        sum += *p;
    }

    return sum;
}
