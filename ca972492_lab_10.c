#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie {
	int flag;
	struct Trie* children[26];
} Trie;

void insert(struct Trie **ppTrie, char *word)
{
	if (*ppTrie == NULL)
		return;
	
	int length = strlen(word);
	Trie *temp = *ppTrie;
	
	for (int i = 0; i < length; ++i)
	{
		int index = word[i] - 'a';
		
		if (temp->children[index] == NULL)
			temp->children[index] = (Trie *)calloc(1, sizeof(Trie));
		
		temp = temp->children[index];
	}
	
	temp->flag++;
}

int numberOfOccurances(struct Trie *pTrie, char *word)
{
	if (pTrie == NULL)
		return 0;
	
	int length = strlen(word);
	Trie *temp = pTrie;
	
	for (int i = 0; i < length; ++i)
	{
		int index = word[i] - 'a';
		
		temp = temp->children[index];
	}
	
	return (temp->flag);
}
	
struct Trie *deallocateTrie(struct Trie *pTrie)
{
	if (pTrie == NULL)
		return pTrie;
	
	int i;
	
	for (i=0; i<26; i++)
		if (pTrie->children[i] != NULL)
			deallocateTrie(pTrie->children[i]);
		
	free(pTrie);
}

int main(void)
{
	Trie* trie = calloc(1, sizeof(Trie));;
	
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	  
	  for (int i = 0; i < 5; ++i)
		  insert(&trie, pWords[i]);
	  
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
     }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}