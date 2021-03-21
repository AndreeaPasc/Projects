//
// Created by andre on 15.05.2019.
//

#ifndef PARTS_DATABASE__DYNAMIC__READ_LINE_H
#define PARTS_DATABASE__DYNAMIC__READ_LINE_H


/**********************************************************
 * read_line: Skips leading white-space characters, then  *
 *            reads the remainder of the input line and   *
 *            stores it in str. Truncates the line if its *
 *            length exceeds n. Returns the number of     *
 *            characters stored.                          *
 *********************************************************/
int read_line(char str[], int n);

#endif //PARTS_DATABASE__DYNAMIC__READ_LINE_H
