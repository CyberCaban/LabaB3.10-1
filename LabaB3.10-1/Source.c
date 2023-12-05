#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char* word;
	struct Node* next;
} TNode;

void pushEnd(TNode** head, char* word) {
	TNode* tmp = (TNode*)malloc(sizeof(TNode));

	if (tmp == NULL) {
		return;
	}
	tmp->next = NULL;

	TNode* curr = (*head);
	if (curr == NULL) {
		tmp->word = word;
		(*head) = tmp;
	}
	else {
		for (; curr; curr = curr->next) {
			if (curr->next == NULL) {
				tmp->word = word;
				curr->next = tmp;
				return;
			}
		}
	}
}

int sentenceInput(TNode** sentence) {
	char* word = NULL;
	char ch, t;
	int i = 0;

	for (; (ch = getchar()) != '.' && ch != '!' && ch != '?';) {
		if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' ')) {
			printf("Non valid symbol");
			return 0;
		}
		if (ch == ' ') {
			if (word) {
				word[i] = '\0';
				pushEnd(sentence, word);
				word = NULL;
				i = 0;
			}
			continue;
		}

		word = (char*)realloc(word, i + 1);
		word[i] = ch;
		i++;

		if (i >= 20) {
			printf("You cannot input words more than 20 symbols in it");
			return 0;
		}
	}

	//if (!i) { // if entered only '.'
	//	printf("Empty sentence");
	//	return 0;
	//}
	if (word) {
		word[i] = '\0';
		pushEnd(sentence, word);
		scanf("%c", &t);
	}

	return 1;
}

int strLength(char* str) {
	int i = 0;
	for (; str[i]; i++) {
	}
	return i;
}

void sentenceOutput(TNode** sentence, int k) {
	for (TNode* curr = (*sentence); curr; curr = curr->next) {
		int strBegin = k - strLength(curr->word);
		for (int i = 0; i < k; i++) {
			if (i < strBegin) {
				printf(" ");
			}
			else {
				printf("%s", curr->word);
				break;
			}
		}
		printf("\n");
	}
}

void listFree(TNode** head) {
	if ((*head) == NULL) {
		return;
	}

	TNode* next;
	for (; (*head);) {
		next = (*head)->next;
		free((*head));
		(*head) = next;
	}
}

int main() {
	TNode* sentence = NULL;
	int k;

	printf("Enter sentence:\n");
	if (!sentenceInput(&sentence)) {
		return 1;
	}

	printf("Enter right pos:\n");
	scanf("%d", &k);
	if (k < 20 || k > 80) {
		printf("Enter valid right pos. It must be integer more than 19 and less "
			"than 81");
		return 1;
	}

	sentenceOutput(&sentence, k);
	listFree(&sentence);
}