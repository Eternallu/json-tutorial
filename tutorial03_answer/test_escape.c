#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_char(const char* str) {
    printf("String: %s\n", str);
}

#define PRINT_CHAR(expect) \
    do {\
        printf("define String : %s\n", expect);\
    } while(0) 
#define EXPECT_EQ_STRING(expect, actual, alength) \
    do {\
        if (sizeof(expect) - 1 != alength || memcmp(expect, actual, alength) != 0) {\
            fprintf(stderr, "Expected: %s, Actual: %s\n", expect, actual);\
        }\
    } while(0)

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        if (!(equality)) {\
            fprintf(stderr, "Expected: " format ", Actual: " format "\n", expect, actual);\
        }\
    } while(0)

int main(int argc, char const *argv[])
{
    print_char("");
    EXPECT_EQ_STRING("", "\"\"", 2); /* ""传入的就是空 */
    return 0;
}
