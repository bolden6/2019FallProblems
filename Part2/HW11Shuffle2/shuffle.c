#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck);
void shuffleHelper(CardDeck origDeck);
void interleaveHelper(CardDeck * deck, CardDeck leftDeck, CardDeck rightDeck, int current, int leftStart, int rightStart);
void interleave(CardDeck leftDeck, CardDeck rightDeck);

static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

void shuffle(CardDeck origDeck, int round)
{

  //CardDeck * nextDeck = malloc((origdeck.size - 1) * sizeof(CardDeck));
  if (round-- > 0)
  {
    shuffleHelper(origDeck);
  }
}

void shuffleHelper(CardDeck origDeck)
{

    int numD = origDeck.size - 1;

    CardDeck * leftDeck = malloc(numD* sizeof(CardDeck));
    CardDeck * rightDeck = malloc(numD * sizeof(CardDeck));
    divide(origDeck, leftDeck, rightDeck);

    while (numD --)
      {
        interleave(leftDeck[numD], rightDeck[numD]);
      }

    free(leftDeck);
    free(rightDeck);


}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{

  for (int i = 0; i < origDeck.size - 1; i++)
    {
      leftDeck[i].size = i + 1;
      rightDeck[i].size = origDeck.size - i - 1;

      // fill the decks
      for (int c = 0; c < origDeck.size; c++)
      {
        if (c < i + 1)
        {
          leftDeck[i].cards[c] = origDeck.cards[c];
        }
        else
        {
          rightDeck[i].cards[c - i - 1] = origDeck.cards[c];
        }
      }
    }
}

void interleaveHelper(CardDeck * deck, CardDeck leftDeck, CardDeck rightDeck, int current, int leftStart, int rightStart)
{
  if (leftStart == leftDeck.size && rightStart == rightDeck.size)
    printDeck(*deck);

  if (rightStart < rightDeck.size)
    {
      deck->cards[current] = rightDeck.cards[rightStart];
      interleaveHelper(deck, leftDeck, rightDeck, current + 1, leftStart, rightStart + 1);
    }

  if (leftStart < leftDeck.size)
    {
      deck->cards[current] = leftDeck.cards[leftStart];
      interleaveHelper(deck, leftDeck, rightDeck, current + 1, leftStart + 1, rightStart);
    }
}

void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
  CardDeck deck =
    {
      .size = leftDeck.size + rightDeck.size,
      .cards = {0}
    };
  interleaveHelper(&deck, leftDeck, rightDeck, 0, 0, 0);
}
