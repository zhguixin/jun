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
	head=tail=new ListNode<T>;	//������ͷ��㣬����ʼ��head��tail
	tail->SetLink(NULL);	//��ͷ����д洢��ָ����NULL
}

template<class T>
bool List<T>::AddTail(T value)
{
	ListNode<T>* add=new ListNode<T>(value);	//���β�м����½��
	tail->SetLink(add);
	tail=tail->GetLink();
	tail->SetLink(NULL);
	if(tail!=NULL)
		return true;
	else
		return false;
}

template<class T>
bool List<T>::RemoveTail()	//ɾ����β���
{
	return RemoveAt(this->GetCount()-1);
}

template<class T>
bool List<T>::InsertAt(int index,T value)	//������ֵָ��Ľ��ǰ����һ���½��
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		return false;
	}
	ListNode<T>* current=head;	//��ͷ��ʼѰ�ҳ���ص�
	while(index)
	{
		current=current->GetLink();	//���û�ҵ�����˳���ƶ�cur
		--index;
	}
	ListNode<T>* add=new ListNode<T>(value);
	add->SetLink(current->GetLink());	//���½��Ľ����������
	current->SetLink(add);
	if(current->GetLink()!=NULL)
		return false;
	else
		return true;
}

template<class T>
bool List<T>::RemoveAt(int index)	//��������ֵɾ�����
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		return false;
	}
	//���������ָ��Э�����ɾ�������У�curָ��Ҫɾ����ǰһ�����
	//curPreָ��Ҫɾ���Ľ��
	ListNode<T> *cur,*curPre;
	cur=head;	//������ͷ��ʼѰ��indexָ��Ľ��
	curPre=cur->GetLink();	//��curPre��cur��

	while(index!=0)
	{
		cur=cur->GetLink();	//���û�ҵ�����cur��curPre��������
		curPre=curPre->GetLink();
		--index;
	}
	
	//���Ҫɾ���Ľ��λ������β�����cur��Ϊ�µı�β
	if(tail==curPre)
		tail=cur;

	cur->SetLink(curPre->GetLink());	//����ɾ������������ժ��
	if(curPre!=NULL)
		return true;
	else 
		return false;
}

template<class T>
bool List<T>::IsEmpty()	//�жϿպ���
{
	return head->GetLink()==NULL;
}

template<class T>
T& List<T>::GetAt(int index)	//��������ֵ����value
{
	if(index>this->GetCount()-1 || index<0)	
	{
		std::cout<<"A wrong position!\n";
		// return static_cast<int &>(false);
		//return false;
		// return 0;	//"0"��ʾ������Ϣ
	}

	ListNode<T>* cur=head->GetLink();
	//cur=head->Getlink();
	while(index)
	{
		cur=cur->GetLink();	//���û�ҵ�����cur��������
		--index;
	}

	return cur->GetData();	//���ؽ���е�value
}

template<class T>
int List<T>::GetCount()	//���������н��ĸ�������ͷ�����⣩
{
	int count=0;	//��count��¼������
	ListNode<T>* cur=head->GetLink();	//��ʼ��ָ��ָ���һ����㣨���Ǳ�ͷ��㣩
	while(cur!=NULL)
	{
		++count;
		cur=cur->GetLink();	//˳���ƶ�cur
	}
	return count;
}

template<class T>
void List<T>::RemoveAll()
{
	ListNode<T>* cur;
	//����ͷ�������������ʱ��ɾ����Щ���
	while(head->GetLink()!=NULL)
	{
		cur=head->GetLink();
		head->SetLink(cur->GetLink());
		delete cur;
	}
	tail=head;	//�ñ�βΪ��ͷ��
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
void List<T>::SetTail(ListNode<T>* newtail)	//�ı�βָ��ָ��
{
	tail=newtail;
}

template<class T>
ListNode<T>* List<T>::GetNodeAt(int index)	//����ָ������ֵΪindex�Ľ���ָ��
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