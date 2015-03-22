#include "header.h"
using namespace std;
int main (void)
{
	tree avl;
	string buffer;
	int key_in;
	/* input names/keys */
	while (cin>>buffer)
	{
		cin>>key_in;
//testing		cout<<buffer<<" "<<key_in<<endl;
		/* set head */
		if (avl.get_head()==NULL)
		{
			cout<<"head: "<<endl<<buffer<<" "<<key_in<<endl;
			avl.set_head(key_in,buffer);
//testing			cout<<buffer<<endl<<"depth: 0"<<endl;
		}
		/* set not head */
		else
		{
//testing			cout<<"1-main";
			avl.insert(key_in,buffer);
		}
	}
	cout<<"Print:"<<endl;
	avl.print_tree(avl.get_head());
	return 0;
}