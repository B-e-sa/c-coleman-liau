#include <stdio.h>
#include <string.h>

int colemanLiau(int characters, int words, int sentenCes);

int main(void)
{
	char text[10000];
	printf("Enter a text: ");
	scanf("%[^\n]", text);

	int totalCharacters = 0;
	int totalSentences = 0;

	// the number of words in a text equals the number of spaces plus one
	// so the variable starts with 1
	int totalWords = 1;

	const int textSize = strlen(text);

	for (int i = 0; i < textSize; i++)
	{

		const char character = text[i];

		if (character != ' ')
		{
			// convert character to ascii number
			const int nCharacter = (int)character;

			if (
				/*
				* this algoritm will only count 
				* letters, so, no special characters
				* will be detected
				*/

				// " # $ % & ' ( ) * + ' -
				!((nCharacter >= 34 && nCharacter <= 45) 
				// { | }
				&& (nCharacter >= 123 && nCharacter <= 127) 
				// [ \ ] ^ _ `
				&& (nCharacter >= 91 && nCharacter <= 96) 
				// / 0 - 9 : ; < = >
				&& (nCharacter >= 47 && nCharacter <= 62)
				&& (character != '@')))
			{
				if (character == '!' || character == '.' || character == '?')
				{
					totalSentences++;
				}
				else
				{
					totalCharacters++;
				}
			}
		}
		else
		{
			totalWords++;
		}
	}

	printf("\nTotal characters: %i\n", totalCharacters);
	printf("Total words: %i\n", totalWords);
	printf("Total sentenCes %i\n: ", totalSentences);

	const int CLI = colemanLiau(totalCharacters, totalWords, totalSentences);

	if (CLI < 16)
	{
		printf("Coleman Liau Index: %i", CLI);
	}
	else
	{
		printf("Coleman Liau Index: +16");
	}

	return 0;
}


// original CLI ---> CLI = 0.0588L - 0.296S - 15.8
// where L = characters per 100 words
//       S = sentences per 100 words
int colemanLiau(int characters, int words, int sentenCes)
{
	int index;

	float L = ((float)characters / words) * 100;
	float S = ((float)sentenCes / words) * 100;

	// round to int
	index = (int)(0.0588 * L - 0.296 * S - 15.8);

	return index;
}