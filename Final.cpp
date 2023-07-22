#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *writer,*title,*publisher;
	float *price;
	int *stock;
public:	
	book()	{
        writer = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
	}
	void inputinfo();
	void editinfo();
	void showinfo();
	int search(char[],char[]);
	void buy();
	
};

void book::inputinfo()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";  cin.getline(writer, 20);
    cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter amount in stock: ";   cin>>*stock;   
	
}


void book::showinfo()	{
    cout << "\nWriter Name: " << writer;
    cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock amount "<<*stock;   
	
}

int book::search(char tbuy[20],char abuy[20] )	{
    if (strcmp(tbuy, title) == 0 && strcmp(abuy, writer) == 0)
        return 1;
	else return 0;
		
}

void book::buy()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Tk "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock!!";
}

int main()	{
	book *A[10];
	int i=0,j,k,num;
	char buytitle[20],buywriter[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>num;
		
		switch(num)	{
			case 1:	A[i] = new book;
				A[i]->inputinfo();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(buytitle,20);
				cout<<"Enter Author Of Book: ";  cin.getline(buywriter,20);
				for(k=0;k<i;k++)	{
					if(A[k]->search(buytitle,buywriter))	{
						A[k]->buy();
						break;
					}
				}
				if(k==1)
				cout<<"\nThis Book is Not avaiable";
				
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(buytitle,20);
				cout<<"Enter Author Of Book: ";  cin.getline(buywriter,20);
				
				for(k=0;k<i;k++)	{
					if(A[k]->search(buytitle,buywriter))	{
						cout<<"\nBook Found Successfully";
						A[k]->showinfo();
						break;
					}
				}
				if(k==i)
				cout<<"\nThis Book is Not in Stock";
				break;
			
			
			case 4: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}