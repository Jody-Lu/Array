#include <iostream>
#include <map>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(NULL), random(NULL){}
};


class Solution
{
public:
	RandomListNode* copyRandomList(RandomListNode *head)
	{
		if(head == NULL) return NULL;

		map<RandomListNode*, int> hash; // map the node's address to its position
		map<int, RandomListNode*> new_hash;
		RandomListNode* new_head = new RandomListNode(head -> label);
		RandomListNode* tmp_1 = head; // to fill the hash table
		RandomListNode* tmp_2 = head; // to copy the Randomlist
		int position = 0;

		// mapping each node to its position: head -> 0 | head -> next -> 1 ... and so on
		while(tmp_1 != NULL)
		{
			hash[tmp_1] = position;
			++position;
			tmp_1 = tmp_1 -> next;
		}
		hash[NULL] = get_size(head);
		//cout << hash[head -> next -> random] << endl;

		// copy the whole randomlist and the random pointers have not been copied yet
		RandomListNode* tmp = new_head;
		new_hash[0] = new_head;


		tmp_2 = tmp_2 -> next;
		while(tmp_2 != NULL)
		{
			tmp -> next = new RandomListNode(tmp_2 -> label);
			//cout << tmp_2 -> label << endl;
			tmp_2 = tmp_2 -> next;
			tmp = tmp -> next;
		}

		int new_position = 0;
		RandomListNode* idx = new_head;
		while(idx != NULL)
		{
			new_hash[new_position] = idx;
			idx = idx -> next;
			++new_position;
		}
		new_hash[get_size(head)] = NULL;
		//cout << "size: " << new_hash.size() << endl;

		// handle the random pointer

		RandomListNode* tmp_go = new_head;
		tmp = new_head;
		tmp_2 = head;
		while(tmp != NULL)
		{
			//if(hash[tmp_2 -> random] != 0)
			//cout << "index: " << hash[tmp_2 -> random] << " " << tmp_2 -> random << " " << new_hash[hash[tmp_2 -> random]] << endl;
			tmp -> random = new_hash[hash[tmp_2 -> random]];

			tmp = tmp -> next;
			tmp_2 = tmp_2 -> next;
		}
		//hash[NULL] = 10;
		//cout << "test " << hash[NULL] << endl; // NULL and head are mapping to zero
		//new_head -> random = new_hash[hash[head -> random]];

		return new_head;
	}
private:
	int get_size(RandomListNode* head)
	{
		int size = 0;
		while(head != NULL)
		{
			++size;
			head = head -> next;
		}
		return size;
	}

};

int main()
{
	Solution sol;
	RandomListNode* head = new RandomListNode(-2);
	RandomListNode* tmp = head;
	for(int i = 0; i < 2; ++i)
	{
		tmp -> next = new RandomListNode(-1);
		tmp -> next -> random = tmp -> next;
		tmp = tmp -> next;
	}



	RandomListNode* tmp_2 = head;
	while(head != NULL)
	{
		cout << "label: " << head -> label << endl;
		if(head -> random)
			cout << "random label: " << head -> random -> label << endl;
		else
			cout << "NULL" << endl;
		head = head -> next;
	}
	RandomListNode* new_head = sol.copyRandomList(tmp_2);
	cout << "--------" << endl;
	while(new_head != NULL)
	{
		cout << "label: " << new_head -> label << endl;
		if(new_head -> random)
			cout << "random label: " << new_head -> random -> label << endl;
		else
			cout << "NULL" << endl;
		new_head = new_head -> next;
	}

}

