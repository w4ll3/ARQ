#ifndef LINE_H_
#define LINE_H_

extern int EXIT_SIGNAL;

typedef struct structure {
	char *data;
	struct structure *next;
} node;

typedef struct {
	node *beggin, *end;
} line;

line *initiate();

void putIn(char *data, line *li);

void showLine(line *li);

void showFirst(line li);

void showLast(line li);

int showSize(line li);

char *putOut(line *line);

void clearLine(line *line);

int isEmpty(line *li);

#endif
