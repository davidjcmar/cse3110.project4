#include "header.h"
using namespace std;
int depth=0;
int height=0;
/* node methods */
node::node (int key_in, string name_in)
{
	key=key_in;
	name=name_in;
	left=NULL;
	right=NULL;
	height=0;
}
int node::get_key()
{
	return key;
}
string node::get_name()
{
	return name;
}
node* node::get_left()
{
	return left;
}
node* node::get_right()
{
	return right;
}
void node::set_left(int key_in, string name_in)
{
	left=new node(key_in,name_in);
}
void node::set_right(int key_in, string name_in)
{
	right=new node(key_in,name_in);
}
int node::get_height()
{
	return height;
}
void node::set_height(int level)
{
	height=level;
}


/* tree methods */
tree::tree()
{
	head=NULL;
}
node* tree::get_head()
{
	return head;
}
void tree::set_head(int key_in, string name_in)
{
	head=new node(key_in,name_in);
}
void tree::insert(int key_in, string name_in)
{
//cout<<"chocolate ";
	cout<</*endl*/"2-insert";
	node* parent=find_ins_pos(key_in,head);
	if (key_in<parent->get_key())
	{	
		cout<<"parent->left: "<<parent->get_name()<<endl;
		parent->set_left(key_in,name_in);
	}
	else
	{
		cout<<"parent->right: "<<parent->get_name()<<endl;
		parent->set_right(key_in,name_in);
	}
	cout<<name_in<<" "<<key_in<<endl;
	cout<<"depth: "<<depth<<endl;
	depth=0;
}
node* tree::find_ins_pos(int key_in,node* node_in)
{
	cout<<"3-find";
	depth++;
	height=depth;
//cout<<"hobnobs"<<endl;
	node* current=node_in;
	node* insert_pt=current;
	if (key_in<current->get_key())
	{
//		cout<<"left";
		if (current->get_left()==NULL)
		{
			if (current->get_height()==0)
				current->set_height(1);
/* testing */
			string buffer;
			buffer=current->get_name();
			cout<<"set height: "<<buffer<<endl;
/* ******* */
			return insert_pt;
		}
		else
			insert_pt=find_ins_pos(key_in,current->get_left());
	}
	else
	{
//		cout<<"right";
		if (current->get_right()==NULL)
		{
			if (current->get_height()==0)
				current->set_height(1);
/* testing */
			string buffer;
			buffer=current->get_name();
			cout<<"set height: "<<buffer<<endl;
/* ******* */
			return insert_pt;
		}
		else
			insert_pt=find_ins_pos(key_in,current->get_right());
	}
	--height;
	string buffer;
	buffer=current->get_name();
	cout<<buffer<<": ";
	if ((depth-height)>current->get_height())
	{
		cout<<"YO ";
		current->set_height(depth-height);
	}
	int new_hi=current->get_height();
	cout<<new_hi<<endl;
	return insert_pt;
/*	while (1)
	{
		if ((key_in<current->get_key())&&(current->get_left()!=NULL))
		{
			current=current->get_left();
		}
		else if ((key_in>current->get_key())&&(current->get_right()!=NULL))
		{
			current=current->get_right();
		}
		else
		{
			return current;
		}
	}*/
}
void tree::print_tree(node* pre)
{
	node* current=pre;
	/* testing */
	int key_out=current->get_key();
	string buffer=current->get_name();
	cout<<buffer<<" "<<key_out<<endl;
	/* ****** */
	if (current->get_left()!=NULL)
	{
		cout<<"left:"<<endl;
		print_tree(current->get_left());
	}
	if (current->get_right()!=NULL)
	{
		cout<<"right:"<<endl;
		print_tree(current->get_right());
	}
}
bool tree::balance(int left, int right)
{
	return true;
}
void tree::rotate(node* parent, node* child)
{

}