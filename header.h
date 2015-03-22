#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#ifndef __header__
#define __header__
using namespace std;

class node
{
private:
	int key;
	int height;
	string name;
	node* left;
	node* right;
	node* parent;
public:
	node(int key, string name, node* parent);
	int get_key();
	string get_name();
	node* get_left();
	node* get_right();
	void set_left(int key, string name, node* parent);
	void set_right(int key, string name, node* parent);
	int get_height();
	void set_height(int);
	node* get_parent();
};

class tree
{
private:
	node* head;
	node* current;
public:
	tree ();
	node* get_head();
	void set_head(int key, string name);
	void insert(int key,string name);
	node* find_ins_pos(int key,node*);
	void print_tree(node*);
	bool balance(int,int);
	void rotate(node*,node*);
};
#endif