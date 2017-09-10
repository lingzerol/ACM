// 贪吃蛇.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

enum direction {up0,down0,left0,right0};

const int row = 25, column = 30;

class SnakeNode {
public:SnakeNode(direction dir, SnakeNode *head,bool &jud);//初始化数据并连接节点；
	   SnakeNode(direction dir,int r,int c);//初始化数据
	   void link_Node(SnakeNode*t);//连接节点
	   int return_r();
	   int return_c();
	   SnakeNode* change_tail();//改变队尾指针；
	   bool check(int r,int c);
private:
	int r;
	int c;
	SnakeNode* ahead;
};



class Snake {
public :
	Snake(SnakeNode*head, SnakeNode*tail);
	bool add_Node();
	void delete_Node();
	SnakeNode* return_head();
	SnakeNode* return_tail();
	void food(int& r, int &c);
	bool check(int r, int c);
private:
	static SnakeNode *head;
	static SnakeNode *tail;
};



class Instrument {
public:static void get_Instr(char t);
	   static direction return_Instr();
private:
	static direction dir;
};



class pic {
public:void display();
	   static void change_val(int r, int c,char n);
	   void init();
private:
	static char p[row][column];
};


SnakeNode::SnakeNode(direction dir, SnakeNode *head,bool &jud) {
	int r, c;
	r = head->r;
	c = head->c;
	switch (dir) {
	case up0:this->r = r - 1; this->c = c; break;
	case down0:this->r = r + 1; this->c = c; break;
	case left0:this->r = r; this->c = c - 1; break;
	case right0:this->r = r; this->c = c + 1; break;
	}
	jud = true;
	if (this->r >= row)
	{
		this->r = 0;
		jud = false;
	}
	if (this->c >= column - 1)
	{
		this->c = 0;
		jud = false;
	}
	if (this->r < 0)
	{
		this->r = row - 1;
		jud = false;
	}
	if (this->c < 0)
	{
		this->c = column - 1;
		jud = false;
	}
	pic::change_val(this->r, this->c,'*');//把对应的数组元素改成*号
	this->ahead = NULL;
}
SnakeNode::SnakeNode(direction dir, int r, int c) {
	switch (dir) {
	case up0:this->r = r - 1; this->c = c; break;
	case down0:this->r = r + 1; this->c = c; break;
	case left0:this->r = r; this->c = c - 1; break;
	case right0:this->r = r; this->c = c + 1; break;
	}
	pic::change_val(this->r, this->c,'*');//把对应的数组元素改成*号
	this->ahead = NULL;
}
void SnakeNode::link_Node(SnakeNode*t) {
	this->ahead = t;
}
int SnakeNode::return_r() {
	return this->r;
}
int SnakeNode::return_c() {
	return this->c;
}
SnakeNode* SnakeNode::change_tail(){
	SnakeNode *tail;
	tail = this->ahead;
	return tail;
}
bool SnakeNode::check(int r,int c) {
	if (this->r == r&&this->c == c)
		return true;
	else return false;
}


Snake::Snake(SnakeNode*head, SnakeNode*tail) {
	this->head = head;
	this->tail = tail;
}
bool Snake::add_Node() {
	SnakeNode* t;
	bool jud;
	direction dir = Instrument::return_Instr();//
	t = new SnakeNode(dir, head,jud);//增加节点，并确定节点方向
	head->link_Node(t);//连接节点
	head = t;
	return jud;
}
void Snake::delete_Node() {
	SnakeNode *q;
	int r, c;
	q = tail;
	tail = tail->change_tail();
	r = q->return_r();
	c = q->return_c();
    pic::change_val(r,c, ' ');//改变数组值
	delete q;
}
SnakeNode* Snake::return_head() {
	return head;
}
SnakeNode* Snake::return_tail() {
	return tail;
}
SnakeNode* Snake::head = NULL;
SnakeNode* Snake::tail = NULL;
void Snake::food(int&r, int&c) {
	srand((unsigned)time(NULL));
	r = rand() % (row-1);
	c = rand() % (column-1);
	//std::cout << r << ' ' << c;
	//system("pause");
	pic::change_val(r, c,'*');
}
bool Snake::check(int r, int c){
	bool jud;
	jud = head->check(r, c);
	return jud;
}


void Instrument::get_Instr(char t) {
	switch (t) {
	case 'w':dir = up0; break;
	case 's':dir = down0; break;
	case 'a':dir = left0; break;
	case 'd':dir = right0; break;
	}
}
direction Instrument::return_Instr() {
	return dir;
}
direction Instrument::dir = right0;
void pic::init() {
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < column - 1; j++)
			if ((j == 0) || i == 0 || i == row - 1 || j == column - 2)
				p[i][j] = '*';
			else p[i][j] = ' ';
}
void pic::change_val(int r, int c, char t) {
	p[r][c] = t;
}
void pic::display() {
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column-1; j++)
			std::cout << p[i][j];
		std::cout << std::endl;
	}
}
char pic::p[row][column] = { 0 };


int main()
{
	int r, c;
	bool jud=false,jud2=true;
    Instrument instr;
	pic pi;
	pi.init();
	SnakeNode *n = new SnakeNode(instr.return_Instr(), 2, 2);
	SnakeNode *head, *tail;
	tail = n;
	head = n;
	Snake snake(head, tail);
	snake.add_Node();
	snake.add_Node();
	/*for (int i = 0; i < 33; i++)
	{
		snake.add_Node();
		snake.delete_Node();
		pi.display();
		//if (i == 8)
		//	instr.get_Instr('s');
		Sleep(500);
		system("cls");
	}//类测试;*/
	snake.food(r,c);
	while (true) {
		char t;
		t = getch();
		jud2 = true;
		instr.get_Instr(t);
		while (!kbhit()) {
			if (!snake.add_Node())
			{
				jud2 = false;
				break;
			}
			jud = snake.check(r, c);
			if (jud)
			{
				snake.food(r, c);
				jud = false;
			}
			else snake.delete_Node();
			Sleep(200);
			system("cls");
			pi.display();
		}
		if (!jud2)
			break;
	}
	system("cls");
	std::cout << "GAME OVER!"<<std::endl;
	system("pause");
    return 0;
}

