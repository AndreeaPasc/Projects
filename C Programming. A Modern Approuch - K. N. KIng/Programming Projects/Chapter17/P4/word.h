//
// Created by andre on 18.05.2019.
//

#ifndef P4_WORD_H
#define P4_WORD_H

/***********************************************************
 * read_word: Reads the next word from the input and       *
 *            stores it in word. Makes word empty if no    *
 *            word could be read because of end-of-file.   *
 *            Truncates the word if its length exceeds     *
 *            len.                                         *
 **********************************************************/
void read_word(char *word, int len);

#endif //P4_WORD_H
