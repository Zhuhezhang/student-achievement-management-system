//���������࣬��һ���Ǵ��ѧ����Ϣ�ģ�ͬʱҲ��Ҫ�����ļ��ģ� 
//�ڶ�������������Ҫ�Ĳ������� 
#ifndef WORK4CLASS_H_
#define WORK4CLASS_H_
using namespace std;

//ѧ����Ϣ���
class Student{
	public:
		char student_name[20];
		char student_ID[10];
		int chinese_score;
		int math_score;
		int english_score;
		int average_score;
		Student *next;
		
		void input();
		void readfile(ifstream &in);
};

//ѧ����Ϣ�������
class Student_information
{
    public:
	    Student_information();
	    ~Student_information();
	    void show_menu();//��ʾ�˵� 
  	    void add();      //���� 
	    void del();      //ɾ�� 
	    void display();  //��ʾ 
	    void find();     //��ѯ 
	    void modify();   //�޸� 
	    void save();     //���� 
    	void copy(Student *p1,Student *p2);//�����ڵ� 
	    void sort();     //���� 
	    void count();    //ͳ��
	    void clean();    //��� 
	private: 
	//Student_information����Կ�������Student��Ϊ�������� 
	    Student *head;//����ͷ 
	    Student *end; //����β 
	    ifstream in;
		ofstream out; 
};
#endif
