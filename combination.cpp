#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include"List.cc"

//������������listFirst,listSecond
int main()
{
	List<int> listFirst;
	List<int> listSecond;
	
	//��ʼ������listFirst
	listFirst.AddTail(1);
	listFirst.AddTail(6);
	listFirst.AddTail(8);
	listFirst.AddTail(9);
	listFirst.AddTail(13);
	
	cout<<"the listFirst is:\n";
	for(int i=0;i < (listFirst.GetCount());i++)
		cout<<listFirst.GetAt(i)<<endl;

	//��ʼ������listSecond
	listSecond.AddTail(0);
	listSecond.AddTail(3);
	listSecond.AddTail(4);
	listSecond.AddTail(6);
	listSecond.AddTail(11);
	listSecond.AddTail(17);
	for(int i=0;i < (listSecond.GetCount());i++)
		cout<<listSecond.GetAt(i)<<endl;

	while(listSecond.GetCount()!=0)	//��listSecond�ǿ�ʱ����ѭ��
	{
		int indexFirst=0;
		//ÿ�ΰ�listSecond �еĵ�һ����������뵽listFirst��
		//��whileѭ�����Ѱ�Ҳ���λ��


	}
	
	// system("pause");
	return 0;
}//end of main
