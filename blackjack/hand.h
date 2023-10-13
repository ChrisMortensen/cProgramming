
typedef struct
{
	Card *cards;
	int size;
	int sum;
} Hand;

void handSum(Hand *hand)
{
	int sum = 0;
	for (int i = 0; i < hand->size; i++)
	{
		sum += hand->cards[i].rank;
	}
	hand->sum = sum;
}

int aceCheck(Hand hand){
	for (int i = 0; i < hand.size; i++)
	{
		if (hand.cards[i].rank==ace)
		{
			return 1;
		}
	}
	return 0;
}