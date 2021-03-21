//
// Created by andre on 07.05.2019.
//

//#ifndef EX4_DEBUG_H
//#define EX4_DEBUG_H

#ifdef DEBUG
#define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)
#else
#define PRINT_DEBUG(n)
#endif

//#endif //EX4_DEBUG_H
