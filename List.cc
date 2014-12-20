#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
// #include<iostream>
//using std::noboolalpha;

template <class T>
class List
{
	ListNode<T>* head;
	ListNode<T>* tail;
public:
	List();
	~List(){};

	bool AddTail(T value);
	bool RemoveTail();
	bool InsertAt(int index,T value);
	bool RemoveAt(int index);
	bool IsEmpty();
	T& GetAt(int index);
	int GetCount();
	void RemoveAll();
	ListNode<T>* GetHead();
	ListNode<T>* GetTail();
	void SetTail(ListNode<T>* newtail);
	ListNode<T>* GetNodeAt(int index);
	ListNode<T>* GetCur();
	ListNode<T>* TowardCur();
};

template <class T>
List<T>::List()
{
	head=tail=new ListNode<T>;	//创建表头结点，并初始化head和tail
	tail->SetLink(NULL);	//表头结点中存储的指针置NULL
}

template<class T>
bool List<T>::AddTail(T value)
{
	ListNode<T>* add=new ListNode<T>(value);	//向表尾中加入新结点
	tail->SetLink(add);
	tail=tail->GetLink();
	tail->SetLink(NULL);
	if(tail!=NULL)
		return true;
	else
		return false;
}

template<class T>
bool List<T>::RemoveTail()	//删除表尾结点
{
	return RemoveAt(this->GetCount()-1);
}

template<class T>
bool List<T>::InsertAt(int index,T value)	//在索引值指向的结点前插入一个新结点
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		return false;
	}
	ListNode<T>* current=head;	//从头开始寻找出入地点
	while(index)
	{
		current=current->GetLink();	//如果没找到，则顺序移动cur
		--index;
	}
	ListNode<T>* add=new ListNode<T>(value);
	add->SetLink(current->GetLink());	//将新建的结点链入链表
	current->SetLink(add);
	if(current->GetLink()!=NULL)
		return false;
	else
		return true;
}

template<class T>
bool List<T>::RemoveAt(int index)	//按照索引值删除结点
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		return false;
	}
	//用两个结点指针协作完成删除。其中，cur指向要删除的前一个结点
	//curPre指向要删除的结点
	ListNode<T> *cur,*curPre;
	cur=head;	//从链表头开始寻找index指向的结点
	curPre=cur->GetLink();	//置curPre到cur后

	while(index!=0)
	{
		cur=cur->GetLink();	//如果没找到，则cur与curPre继续后移
		curPre=curPre->GetLink();
		--index;
	}
	
	//如果要删除的结点位于链表尾，则把cur置为新的表尾
	if(tail==curPre)
		tail=cur;

	cur->SetLink(curPre->GetLink());	//将被删除结点从链表中摘下
	if(curPre!=NULL)
		return true;
	else 
		return false;
}

template<class T>
bool List<T>::IsEmpty()	//判断空函数
{
	return head->GetLink()==NULL;
}

template<class T>
T& List<T>::GetAt(int index)	//返回索引值结点的value
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		// return static_cast<int &>(false);
		//return false;
		// return 0;	//"0"表示错误信息
	}

	ListNode<T>* cur=head->GetLink();
	//cur=head->Getlink();
	while(index)
	{
		cur=cur->GetLink();	//如果没找到，则cur继续后移
		--index;
	}

	return cur->GetData();	//返回结点中的value
}

template<class T>
int List<T>::GetCount()	//返回链表中结点的个数（表头结点除外）
{
	int count=0;	//用count记录结点个数
	ListNode<T>* cur=head->GetLink();	//初始化指针指向第一个结点（不是表头结点）
	while(cur!=NULL)
	{
		++count;
		cur=cur->GetLink();	//顺序移动cur
	}
	return count;
}

template<class T>
void List<T>::RemoveAll()
{
	ListNode<T>* cur;
	//当表头结点后还有其他结点时，删除这些结点
	while(head->GetLink()!=NULL)
	{
		cur=head->GetLink();
		head->SetLink(cur->GetLink());
		delete cur;
	}
	tail=head;	//置表尾为表头处
}

template<class T>
ListNode<T>* List<T>::GetHead()
{
	return head;
}

template<class T>
ListNode<T>* List<T>::GetTail()
{
	return tail;
}

template<class T>
void List<T>::SetTail(ListNode<T>* newtail)	//改变尾指针指向
{
	tail=newtail;
}

template<class T>
ListNode<T>* List<T>::GetNodeAt(int index)	//返回指向索引值为index的结点的指针
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		return false;
	}
}

template<class T>
ListNode<T>* List<T>::GetCur()
{
	// return cur;
}

template<class T>
ListNode<T>* List<T>::TowardCur()
{
	// cur=cur->Getlink();
	// return cur;
}

#endif