#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#define WORD_LEN 20

char SentEnd[3] = { '.', '!', '?' };

typedef struct Node {
	int val;
	struct Node* next;
} TNode;

void pushEnd(TNode** head, int data) {
	TNode* tmp = (TNode*)malloc(sizeof(TNode));

	if (tmp == NULL) {
		return;
	}
	tmp->next = NULL;

	TNode* curr = (*head);
	if (curr == NULL) {
		tmp->val = data;
		(*head) = tmp;
	}
	else {
		for (; curr; curr = curr->next) {
			if (curr->next == NULL) {
				tmp->val = data;
				curr->next = tmp;
				return;
			}
		}
	}
}

int sentenceInput(char* sentence) {
	char c;
	int i = 0;
	while ((c = getchar()) != '.' && c != '!' && c != '?') {
		sentence[i] = c;
		i++;
	}
}

int main() {
	TNode* sentence = NULL;
	char word[WORD_LEN];

	sentenceInput(word);
	printf("%s", word);
	/*scanf("%s", word);
	printf("%s", word);*/
}