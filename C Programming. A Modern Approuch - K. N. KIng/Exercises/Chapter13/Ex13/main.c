#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 50

char http_www[] = "http://www.";
char index_html[] = "/index.html";

void build_index_url(const char *domain, char *index_url);

int main() {
    char domain[STR_LEN], index_url[STR_LEN];
    printf("Enter a domain: ");
    gets(domain);

    build_index_url(domain, index_url);

    printf("The URL is: %s", index_url);
    return 0;
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, http_www);
    strcat(index_url, domain);
    strcat(index_url, index_html);
}