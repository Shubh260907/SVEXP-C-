#include<iostream>
#include<string.h>
using namespace std;
class library
{
private :
    int book_id;
    string title;
    string author;
    int num_copy;

public :
    int search(int);
    void set_data();
    void add_b();
    void issue_b();
    void return_b();
    void display_b();
};
int library::search(int bookid)
{
    if(bookid==book_id)
        return 1;
    else
        return 0;
}

void library::set_data()
{
    cout<<"enter book id :";
    cin>>book_id;
    cout<<"enter book title :";
    cin>>title;
    cout<<"enter author name :";
    cin>>author;
    cout<<"enter total number of book :";
    cin>>num_copy;

}
void library::add_b()
{
    int ncopy=0;
    cout<<"enter book number for update total count:";
    cin>>ncopy;
    num_copy=ncopy+num_copy;

}
void library::issue_b()
{
     int ncopy=0;
    cout<<"enter number of copies you want to issue";
    cin>>ncopy;
    num_copy=num_copy-ncopy;
    cout<<"book issued"<<endl;
}
void library::return_b()
{
    num_copy++;
    cout<<"book returned"<<endl;
}
void library::display_b()
{
    cout<<"updated total number of book count :"<<num_copy<<endl;
}

int main()
{
    library b[50];
    int book_id;
    int i,ch;
    int j=0;
    int flag=0;
    cout<<"NAME       : Shubham Vora\n";
    cout<<"ID         : 25CE141\n";
    cout<<"DEPARTMENT : COMPUTER ENGEENERING\n"<<endl;
option:

    cout<<"enter 1.  add new book details."<<endl;
    cout<<"enter 2.  only add book."<<endl;
    cout<<"enter 3.  issue book."<<endl;
    cout<<"enter 4.  return book."<<endl;
    cout<<"enter 5.  to show available book."<<endl;
    cout<<"enter 6.  exit."<<endl;
    cout<<"enter choice :";
    cin>>ch;
    cout<<endl;

    switch(ch)
    {
    case 1:
        b[j].set_data();
        j++;
        flag=1;
        goto option;
    case 2:
        cout<<"enter book id :";
        cin>>book_id;
        if(flag==1)
        {
            for(i=0; i<j; i++)
            {
                if(b[i].search(book_id))
                {
                    b[i].add_b();
                    break;
                }
            }
        }
        else
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
    case 3:
        cout<<"enter book id :";
        cin>>book_id;
        if(flag==1)
        {


            for(i=0; i<j; i++)
            {
                if(b[i].search(book_id))
                {
                    b[i].issue_b();
                    break;
                }
            }
        }
        else
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
    case 4:
        cout<<"enter book id :";
        cin>>book_id;
        if(flag==1)
        {
            for(i=0; i<j; i++)
            {
                if(b[i].search(book_id))
                {
                    b[i].return_b();
                    break;
                }
            }
        }
        else
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
    case 5:
        cout<<"enter book id :";
        cin>>book_id;
        if(flag==1)
        {
            for(i=0; i<j; i++)
            {
                if(b[i].search(book_id))
                    b[i].display_b();
                    break;
                {
                }
            }
        }
        else
        {
            cout<<"book not found.. \nenter choice again."<<endl;
            cout<<endl;

        }
        goto option;
    case 6:
        cout<<"thank you ... visite again.."<<endl;
        return 0;
    default:
        cout<<"invalid choice .. enter your choice again.."<<endl;
        goto option;
    }
}
