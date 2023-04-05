#include <bits/stdc++.h>

using namespace std;



struct MinHeapNode
{

	char data;
	unsigned frequency;

	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned frequency)
	{

		left = right = NULL;
		this->data = data;
		this->frequency = frequency;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->frequency > r->frequency);
	}
};

void printCodes(struct MinHeapNode* root, string str)
{

	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void huffmanEncoding()
{
	int numberOfCharacters, index, secondaryIndex;
	printf("Enter the number of characters: ");
	scanf("%d", &numberOfCharacters);

	char characters[numberOfCharacters];
	int frequency[numberOfCharacters];

	for (index = 0; index < numberOfCharacters; index++);
	{
		printf("Enter character %d and its frequency: ", index + 1);
		scanf(" %c %d", &characters[index], &frequency[index]);
	}

	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int index = 0; index < numberOfCharacters; ++index)
		minHeap.push(new MinHeapNode(characters[index], frequency[index]));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {


		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->frequency + right->frequency);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}


int main()
{
	printf("Name: Afraaz Hussain\nAdmission number: 20BDs0374\n\n\n");
	
	huffmanEncoding();

	return 0;
}
