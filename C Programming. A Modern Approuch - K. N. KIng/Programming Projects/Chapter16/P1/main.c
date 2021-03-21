#include <stdio.h>

#define N ((int) (sizeof(country_codes) / sizeof(country_codes[0])))

struct dialing_code{
    char *country;
    int code;
};

const struct dialing_code country_codes[] = {{"Argentina",            54}, {"Bangladesh",     880},
                                             {"Brazil",               55}, {"Burma",           95},
                                             {"China",                86}, {"Colombia",        57},
                                             {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
                                             {"Ethiopia",            251}, {"France",          33},
                                             {"Germany",              49}, {"India",           91},
                                             {"Indonesia",            62}, {"Iran",            98},
                                             {"Italy",                39}, {"Japan",           81},
                                             {"Mexico",               52}, {"Nigeria",        234},
                                             {"Pakistan",             92}, {"Philippines",     63},
                                             {"Poland",               48}, {"Russia",           7},
                                             {"South Africa",         27}, {"South Korea",     82},
                                             {"Spain",                34}, {"Sudan",          249},
                                             {"Thailand",             66}, {"Turkey",          90},
                                             {"Ukraine",              380}, {"United Kingdom",  44},
                                             {"United States",         1}, {"Vietnam",         84}};

char *display_country(int dial_code);


int main() {

    int dial_code;
    char *country;
    printf("Enter a dial country code: ");
    scanf("%d", &dial_code);

    if(country = display_country(dial_code))
    {
        printf("Country: %s", country);
    }
    else
        printf("Error!");

    return 0;
}

char *display_country(int dial_code) {
    int i;
    for (i = 0; i < N; i++)
        if (dial_code == country_codes[i].code)
            return country_codes[i].country;
}