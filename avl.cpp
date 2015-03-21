#include "header.h"
using namespace std;
int main (void)
{
	tree avl;
	string buffer;
	int key_in;
	while (cin>>buffer)
	{
		cin>>key_in;
//		cout<<buffer<<" "<<key_in<<endl;
		if (avl.get_head()==NULL)
		{
			cout<<"head: "<<endl<<buffer<<" "<<key_in<<endl;
			avl.set_head(key_in,buffer);
//			cout<<buffer<<endl<<"depth: 0"<<endl;
		}
		else
		{
			cout<<"1-main";
			avl.insert(key_in,buffer);
		}
	}
//	cout<<"Print:"<<endl;
//	avl.print_tree(avl.get_head());
	return 0;
}