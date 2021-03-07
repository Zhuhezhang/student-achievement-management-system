//��������������к��� 
#include<iostream>
#include<fstream>
#include<cstring>
#include "work4class.h"
using namespace std;

//���������ѧ����Ϣ
void Student::input()
{
	cout<<"������ѧ�����֣�";
	cin>>student_name;
	cout<<"������ѧ��ѧ�ţ�";
	cin>>student_ID;
	cout<<"������ѧ�����ĳɼ���";
	cin>>chinese_score;
	cout<<"������ѧ����ѧ�ɼ���";
	cin>>math_score;
	cout<<"������ѧ��Ӣ��ɼ���";
	cin>>english_score;
	average_score=(chinese_score+math_score+english_score)/3;
}

//���ĵ��ж�ȡֵ�����
void Student::readfile(ifstream &in)
{
	in>>student_name>>student_ID>>chinese_score>>math_score>>english_score>>average_score;
}

//������캯�������ڴ򿪳���ʱ�����Զ�����ԭ�е�ѧ����Ϣ
Student_information::Student_information()
{
	//��ʼ����ͷβ��� 
	head = new Student;
	head->next = new Student;
	end = head->next; 
	ifstream in("C++work4.txt");
	/*����Ҫ�����ļ���һ�£������ж��ļ��Ƿ�Ϊ�գ���Ϊeof()���������ж�
	�ļ��Ƿ�Ϊ�գ�eof()�Ǹ����ļ���״̬��ʶ���ж��ļ��Ƿ�Ϊ�յģ�����ȡ
	�ļ�ʱ��������βʱ��ϵͳ��ı��ļ���״̬��ʶ����ʱ��Ż᷵��EOF����
	����eof()�жϡ����ȶ�һ�µĻ���in.eof()�ǲ��᷵����ֵ�ģ���ʹ�ļ�Ϊ��*/
	char ch = in.get();
	if(in.eof())
	{
		cout<<"�ļ�Ϊ�գ�"<<endl;
	}
	//���ļ��ǿ�
	while(!in.eof())
	{
		end->readfile(in);
		if(end->student_name[0]=='\0')
		break;//������һ��Ļ��������ļ��������ı��Ҳ������		
		end->next = new Student;
		end = end->next;
	} 
}

//��������
Student_information::~Student_information()
{
	save();//�������˳������ʱ�򣬱������ݵ�C++work4.txt�� 
	Student *pos = head->next;
	Student *temp;
	while(pos!=end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head,end;
}

//���ӽ��
void Student_information::add()
{
	char quit;
	while(1)
	{
		end->input();
		end->next = new Student;
		end = end->next;
		cout<<"�Ƿ����?(Y/N)"<<endl;
		cin>>quit;
		switch(quit)
		{
			case'Y':
			case'y':break;
			case'n':
			case'N':return;break;
			default:cout<<"��������,�Ƿ��������?(Y/N)";
				cin>>quit;
		}
	}
	cout<<"������Ϣ�ɹ�!"<<endl;
	system("pause");
}

//�޸Ľ��
void Student_information::modify()
{
	char name[20];
	cout<<"����������Ҫ�޸ĵ�ѧ�����֣�";
	cin>>name;
	Student *pos = head->next;
	for(pos;pos!=end;pos=pos->next)
	{
		if(strcmp(name,pos->student_name)==0)
		{
			pos->input();
			break;
		}	
	}
	cout<<"�޸ĳɹ�!"<<endl;
}

//ɾ�����
void Student_information::del()
{
	int del_flag = 0;//����Ƿ�ɾ���ɹ� 
	char name[20];
	if(head->next == end)	
	{
	    cout<<"�յ�..."<<endl;
		   return ;
	}
	cout<<"����������Ҫɾ����ѧ�����֣�";
	cin>>name;
	Student *p1 = head->next;
	Student *p2 = head;
	for(p1;p1!=end;p1->next)
	{
		if(strcmp(p1->student_name,name)==0)
		{
			del_flag = 1;
			p2->next = p1->next;
			delete p1;
			break;		
		}
		else
		{
		    p2=p2->next;
			p1=p1->next;
		}
	}	
	if(del_flag == 0)
	{
	    cout<<"δ���ҵ���ѧ��...."<<endl;
	}
	cout<<"ɾ����Ϣ�ɹ�!"<<endl;
}

//����ѧ����Ϣ
void Student_information::find()
{
	while(1)
	{
	   char name[20];
	   char ID[10];
	   cout<<"    1����ѧ�Ų�ѯ\n";
	   cout<<"    2����������ѯ\n";
	   cout<<"\n������ָ�";
	   int choice;
       cin>>choice;
 	   while(choice !=1 && choice != 2)
	   {
		   cout<<"����ָ�\n";
		   system("pause");
		   cout<<"����������ָ�";
		   cin>>choice;
           continue;//����ִ�������ж�
	    }
        system("cls");
	    Student *pos = head->next;
	    int flag(0);//�ж��Ƿ��ҵ���Ϣ 
	    if(choice==1)
     	{
		   cout<<"������Ҫ��ѯ��ѧ�ţ�";
		   cin>>ID;
	       for(pos;pos!=end;pos=pos->next)
	       {
		       if(strcmp(pos->student_ID,ID)==0)
		       {
			      flag = 1; 
			      cout<<"ѧ������:"<<pos->student_name<<endl;
			      cout<<"ѧ��ѧ��:"<<pos->student_ID<<endl;
			      cout<<"���ĳɼ�:"<<pos->chinese_score<<endl;
			      cout<<"��ѧ�ɼ�:"<<pos->math_score<<endl;
			      cout<<"Ӣ��ɼ�:"<<pos->english_score<<endl;
			      cout<<"ƽ���ɼ�:"<<pos->average_score<<endl;
		       }
	       }
        }
	    if(choice==2)
	    {
		   cout<<"������Ҫ��ѯ��������";
		   cin>>name;
	       for(pos;pos!=end;pos=pos->next)
	       {
		       if(strcmp(pos->student_name,name)==0)
		       {
			        flag = 1;
			        cout<<"ѧ������:"<<pos->student_name<<endl;
			        cout<<"ѧ��ѧ��:"<<pos->student_ID<<endl;
			        cout<<"���ĳɼ�:"<<pos->chinese_score<<endl;
			        cout<<"��ѧ�ɼ�:"<<pos->math_score<<endl;
			        cout<<"Ӣ��ɼ�:"<<pos->english_score<<endl;
			        cout<<"ƽ���ɼ�:"<<pos->average_score<<endl;
		       }
	       }
        }
        if(!flag)
        {
    	   cout<<"δ���ҵ���ѧ����Ϣ...\n";
	    }
	    char c;
	    cout<<"\n�Ƿ������ѯ(Y/N)��";
        cin>>c;
        system("cls");
        if(c == 'N' || c == 'n')
           break;
    }
}

//����ѧ����Ϣ
void Student_information::save()
{
	out.open("C++work4.txt");
	Student *pos = head->next;
	if(head->next== end)
	{
		cout<<"�յ�..."<<endl;
	}
	else
	{
		for(pos;pos!=end;pos=pos->next)
		{
			out<<'\t'<<pos->student_name<<'\t'<<pos->student_ID<<'\t'<<pos->chinese_score<<'\t'<<pos->math_score<<'\t'<<pos->english_score<<'\t'<<pos->average_score;
			//��ʽ�������д,��Ϊһ��ʼ����ļ���һ�£����ж��ļ��Ƿ�Ϊ�գ�����ǰ������á�\t��
			//�����Ӽ����ո񣬸�����һ���ո��Բ������������ݣ�����Ͳ�Ҫ�пո�
			//��Ϊ�������C++work4.txt����Ϣʱ�����ܻ�ѿո�Ҳ����һ�����ݽ���������	
		}
	}
	out.close();
	cout<<"������Ϣ�ɹ�!"<<endl;
}

//��ʾ���
void Student_information::display()
{
	if(head->next==end)
	{
	   cout<<"�յ�..."<<endl;
	}
	Student *pos;
	pos = head->next;
	for(pos;pos!=end;pos=pos->next)
	{
		cout<<"ѧ��������"<<pos->student_name<<endl;
		cout<<"ѧ��ѧ�ţ�"<<pos->student_ID<<endl;
		cout<<"���ĳɼ���"<<pos->chinese_score<<endl;
		cout<<"��ѧ�ɼ���"<<pos->math_score<<endl;
		cout<<"Ӣ��ɼ���"<<pos->english_score<<endl;
		cout<<"ƽ���ɼ���"<<pos->average_score<<endl;
		cout<<endl;
	}
}

//ͳ�ƺ��� 
void Student_information::count()
{
	while(1)
	{
		cout<<"1���鿴ͳ�Ƶ����ķ���"<<endl;
	    cout<<"2���鿴ͳ�Ƶ���ѧ����"<<endl;
	    cout<<"3���鿴ͳ�Ƶ�Ӣ�����"<<endl;
	    cout<<"\n������ָ��(1-3)��";
	    int choice;
	    cin>>choice;
	    while(choice<1 || choice>3)
	   {
		   cout<<"����ָ�\n";
		   system("pause");
		   cout<<"��������ָ�";
		   cin>>choice;
           continue;//����ִ�������ж�
	    }
	    Student *p = head->next;
	    if(choice==1)
	   {
		  int a(0);
		  int b(0);
		  int c(0);
		  int d(0);
	      int e(0);
	      int total_student(0);
	      int total_chinese_score(0);
		  for(p;p != end;p = p->next)
          { 
             if (90 <= p->chinese_score && p->chinese_score <= 100)
             {
                a++;
             }
             else if (80 <= p->chinese_score && p->chinese_score <= 89)
             {
                b++;
             }
             else if (70 <= p->chinese_score && p->chinese_score <= 79)
             {
                c++;
             }
             else if (60 <= p->chinese_score && p->chinese_score <= 69)
             {
                d++;
             }
             else
             {
                e++;
             }
             total_student++;
	         total_chinese_score = total_chinese_score + p->chinese_score;
	       }
	       cout<<"\n����ƽ���֣�"<<total_chinese_score/total_student<<endl;;
	       cout<<"���ķ���90-100������"<<a<<endl;
	       cout<<"���ķ��� 80-89������"<<b<<endl;
	       cout<<"���ķ��� 70-79������"<<c<<endl;
	       cout<<"���ķ��� 60-69������"<<d<<endl;
	       cout<<"���ķ���  <60 ������"<<e<<endl;
        }
        if(choice==2)
	   {
		  int a(0);
		  int b(0);
		  int c(0);
		  int d(0);
	      int e(0);
	      int total_student(0);
	      int total_math_score(0);
		  for(p;p != end;p = p->next)
          { 
             if (90 <= p->math_score && p->math_score <= 100)
             {
                a++;
             }
             else if (80 <= p->math_score && p->math_score <= 89)
             {
                b++;
             }
             else if (70 <= p->math_score && p->math_score <= 79)
             {
                c++;
             }
             else if (60 <= p->math_score && p->math_score <= 69)
             {
                d++;
             }
             else
             {
                e++;
             }
             total_student++;
	         total_math_score = total_math_score + p->math_score;
	       }
	       cout<<"\n��ѧƽ���֣�"<<total_math_score/total_student<<endl;;
	       cout<<"��ѧ����90-100����Ϊ��"<<a<<endl;
	       cout<<"��ѧ���� 80-89����Ϊ��"<<b<<endl;
	       cout<<"��ѧ���� 70-79����Ϊ��"<<c<<endl;
	       cout<<"��ѧ���� 60-69����Ϊ��"<<d<<endl;
	       cout<<"��ѧ����  <60 ����Ϊ��"<<e<<endl;
       }
       if(choice==3)
	   {
		  int a(0);
		  int b(0);
		  int c(0);
		  int d(0);
	      int e(0);
	      int total_student(0);
	      int total_english_score(0);
		  for(p;p != end;p = p->next)
          { 
             if (90 <= p->english_score && p->english_score <= 100)
             {
                a++;
             }
             else if (80 <= p->english_score && p->english_score <= 89)
             {
                b++;
             }
             else if (70 <= p->english_score && p->english_score <= 79)
             {
                c++;
             }
             else if (60 <= p->english_score && p->english_score <= 69)
             {
                d++;
             }
             else
             {
                e++;
             }
             total_student++;
	         total_english_score = total_english_score + p->english_score;
	       }
	       cout<<"\nӢ��ƽ���֣�"<<total_english_score/total_student<<endl;;
	       cout<<"Ӣ�����90-100����Ϊ��"<<a<<endl;
	       cout<<"Ӣ����� 80-89����Ϊ��"<<b<<endl;
	       cout<<"Ӣ����� 70-79����Ϊ��"<<c<<endl;
	       cout<<"Ӣ����� 60-69����Ϊ��"<<d<<endl;
	       cout<<"Ӣ�����  <60 ����Ϊ��"<<e<<endl;
       }
        char c;
	    cout<<"\n�Ƿ������ѯ(Y/N)��";
        cin>>c;
        system("cls");
        if(c == 'N' || c == 'n')
        break;
	}
}

//�ѽ��p2��Ϣ������p1
void Student_information::copy(Student *p1,Student *p2)
{
	if (p2 == NULL)
    {
        cout <<"����Ŀ��Ϊ�գ�"<<endl;
    }
    else
    {
        strcpy(p1->student_name,p2->student_name);
        strcpy(p1->student_ID,p2->student_ID);
        p1->chinese_score = p2->chinese_score;
        p1->math_score = p2->math_score;
        p1->english_score = p2->english_score;
        p1->average_score = p2->average_score;
        //ֻ����Ϣ����,next���ܿ���������Ϣ��ʧ
    }
}

//�����Ƴɼ�����
void Student_information::sort()
{
	cout<<"\t\t***********************����*******************\n";
	cout<<"\t\t*                                            *\n";
    cout<<"\t\t*              1.�����ĳɼ�������            *\n";
    cout<<"\t\t*                                            *\n";
    cout<<"\t\t*              2.�����ĳɼ�������            *\n";
    cout<<"\t\t*                                            *\n";
    cout<<"\t\t*              3.����ѧ�ɼ�������            *\n";
    cout<<"\t\t*                                            *\n";
    cout<<"\t\t*              4.����ѧ�ɼ�������            *\n";
    cout<<"\t\t*                                            *\n";
    cout<<"\t\t*              5.��Ӣ��ɼ�������            *\n";
    cout<<"\t\t*                                            *\n";
    cout<<"\t\t*              6.��Ӣ��ɼ�������            *\n";
    cout<<"\t\t*                                            *\n";
    cout<<"\t\t**********************************************\n";
    cout<<"\t\t������ָ��(1-6): ";
	int choice(0);
	cin>>choice;
	while(choice < 1 || choice > 6)
    {
        printf("����ָ�\n\n");
        system("pause");//�⽫Ҫ�󡰰������....���رմ���
        continue;       //����ִ�������ж�
    }
    Student *p1,*p2;
    p1=head->next;
    if(choice==1)       //�����ĳɼ�������
    {
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			   if(p2->chinese_score > p1->chinese_score)
			   {
				   Student *ptemp = new Student;
                   copy(ptemp, p1);
                   copy(p1, p2);
                   copy(p2, ptemp);
		       }	
		    }
      	}
   }
   if(choice==2)//�����ĳɼ�������
    {
    	Student *p1,*p2,*tmp;
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			   if(p2->chinese_score < p1->chinese_score)
			   {
				   Student *ptemp = new Student;
                   copy(ptemp, p1);
                   copy(p1, p2);
                   copy(p2, ptemp);
		       }	
		    }
      	}
   }
   if(choice==3)//����ѧ�ɼ�������
    {
    	Student *p1,*p2,*tmp;
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			   if(p2->math_score > p1->math_score)
			   {
				   Student *ptemp = new Student;
                   copy(ptemp, p1);
                   copy(p1, p2);
                   copy(p2, ptemp);
		       }	
		    }
      	}
   }
   if(choice==4)//����ѧ�ɼ�������
    {
    	Student *p1,*p2,*tmp;
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			   if(p2->math_score < p1->math_score)
			   {
				   Student *ptemp = new Student;
                   copy(ptemp, p1);
                   copy(p1, p2);
                   copy(p2, ptemp);
		       }	
		    }
      	}
   }
   if(choice==5)//��Ӣ��ɼ�������
    {
    	Student *p1,*p2,*tmp;
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			   if(p2->english_score > p1->english_score)
			   {
				   Student *ptemp = new Student;
                   copy(ptemp, p1);
                   copy(p1, p2);
                   copy(p2, ptemp);
		       }
		    }
      	}
   }
   if(choice==6)//��Ӣ��ɼ�������
    {
    	Student *p1,*p2,*tmp;
	    p1=head->next;
	    for(p1;p1!=end;p1=p1->next)//ð������
	    {
		    for(p2=p1->next;p2!=end;p2=p2->next)
		    {
			   if(p2->english_score < p1->english_score)
			   {
				   Student *ptemp = new Student;
                   copy(ptemp, p1);
                   copy(p1, p2);
                   copy(p2, ptemp);
		       }
		    }
      	}
   }
    cout<<"����ɹ�!"<<endl;
}

//����ĵ�
void Student_information::clean()
{
	ofstream out("C++work4.txt",ios::trunc);
	out.close();
	exit(0);//��exitʹ�����˳������ʱ�򣬲�����Student_information�������������
			//�����ֻ���ڴ������д��C++work4.txt�ļ��� 
}

//��ʾ�˵�
void Student_information::show_menu()
{
    cout<<"\t\t************ѧ���ɼ�����ϵͳ�˵�**********\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              1.¼��ѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              2.ɾ��ѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              3.�޸�ѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              4.��ʾѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              5.��ѯѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              6.ͳ��ѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              7.����ѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              8.���ѧ���ɼ�            *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t*              0.�˳�                    *\n";
    cout<<"\t\t*                                        *\n";
    cout<<"\t\t******************************************\n";
    cout<<"\t\t������ָ��(0-8): ";
}
