#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */
#define DAY_LEN 2       /* maximum number of digits in a day */
#define TIME_LEN 6      /* length of a 24-hour time, including space */

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char time_str[DAY_LEN + TIME_LEN + 1], msg_str[MSG_LEN+1];
    int day, hr, min, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter a day, 24-hour time, and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        else if (day < 0 || day > 31)
        {
            printf("Error: Day out of range\n");
            while (getchar() != '\n'); /* clear buffer */
            continue;
        }
        scanf("%d:%d", &hr, &min);
        sprintf(time_str, "%2d %.2d:%.2d", day, hr, min);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(time_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Time  Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}