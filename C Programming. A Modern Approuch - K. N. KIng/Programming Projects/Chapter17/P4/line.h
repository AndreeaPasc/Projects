//
// Created by andre on 18.05.2019.
//

#ifndef P4_LINE_H
#define P4_LINE_H


/***********************************************************
 * clear_line: Clears the current line.                    *
 **********************************************************/
void clear_line(void);

/***********************************************************
 * add_word: Adds a word to the end of the current line.   *
 *           If this is not the first word on the line.    *
 *           puts one space before word.                   *
 **********************************************************/
void add_word(const char *word);

/***********************************************************
 * space_remaining: Returns the number of characters left  *
 *                  in the current line.                   *
 **********************************************************/
int space_remaining(void);

/***********************************************************
 * write_line: Writes the current line with                *
 *             justification.                              *
 **********************************************************/
void write_line(void);

/***********************************************************
 * flush_line: Writes the current line without             *
 *             justification. If the line is empty, does   *
 *             nothing.                                    *
 **********************************************************/
void flush_line(void);

#endif //P4_LINE_H
