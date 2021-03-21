/// original

int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
    {
        if(i<n)
            str[i++] = ch;
        str[i] = '\0';
        return i;
    }
}

/// a)

int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
    {
        if(i == 0 && isspace(ch))
            ; /// ignore
        if(i<n)
            str[i++] = ch;
        str[i] = '\0';
        return i;
    }
}

/// b)

int read_line(char str[], int n)
{
    int ch, i = 0;

    while(!isspace(ch = getchar()))
    {
        if(i<n)
            str[i++] = ch;
    }
        str[i] = '\0';
        return i;
}

/// c)

int read_line(char str[], int n)
{
    int ch, i = 0;

    do
    {
        ch = getchar();
        if (i < n)
            str[i++] = ch;
    } while (ch != '\n');
    str[i] = '\0';
    return i;
}

/// d)

int read_line(char str[], int n)
{
    int ch, i = 0;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch == '\n')
            break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;
}