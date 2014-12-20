#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include"List.cc"

//创建两个链表listFirst,listSecond
int main()
{
	List<int> listFirst;
	List<int> listSecond;
	
	//初始化链表listFirst
	listFirst.AddTail(1);
	listFirst.AddTail(6);
	listFirst.AddTail(8);
	listFirst.AddTail(9);
	listFirst.AddTail(13);
	
	cout<<"the listFirst is:\n";
	for(int i=0;i < (listFirst.GetCount());i++)
		cout<<listFirst.GetAt(i)<<endl;

	//初始化链表listSecond
	listSecond.AddTail(0);
	listSecond.AddTail(3);
	listSecond.AddTail(4);
	listSecond.AddTail(6);
	listSecond.AddTail(11);
	listSecond.AddTail(17);
	for(int i=0;i < (listSecond.GetCount());i++)
		cout<<listSecond.GetAt(i)<<endl;

	while(listSecond.GetCount()!=0)	//当listSecond非空时持续循环
	{
		int indexFirst=0;
		//每次把listSecond 中的第一个数按序插入到listFirst中
		//用while循环语句寻找插入位置


	}
	
	// system("pause");
	return 0;
}//end of main
