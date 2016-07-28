#ifndef LINE_H_
#define LINE_H_

typedef struct structure {
	int key;
	char *data;
	struct structure *next;
} node;

typedef struct {
	node *beggin, *end;
} line;

void initiate(line *li);

void putIn(int key, char *data, line *li);

void showLine(line li);

void showFirst(line li);

void showLast(line li);

int showSize(line li);

void putOut(line *line);

void clearLine(line *line);

#endif
