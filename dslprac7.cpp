#include<iostream>
#include<string>
using namespace std;

class ClubMember
{
public:
    string prn;
    string name;
    ClubMember*next;

    ClubMember(const string &prn,const string &name):prn(prn),name(name),next(nullptr){}
};
class ClubLinkedList
{
private:
    ClubMember*president;
    ClubMember*secretary;

public:
    ClubLinkedList():president(nullptr),secretary(nullptr){}
    void addMember(const string &prn, const string &name)
    {
        ClubMember*newMember=new ClubMember(prn,name);

        if(!president)
        {
            /*if the list is empty ,set the new member as president and secretary*/
            president=secretary=newMember;
        }
        else
        {
            /*Add the new member to the end of the list*/
            secretary->next=newMember;
            secretary=newMember;
        }
    cout<<"Member added: "<<name<<" (PRN:"<<prn<<")"<<endl;
    }
void deleteMember(const string &prn)
{
    ClubMember*current=president;
    ClubMember*prev=nullptr;

    while(current)
    {
        if(current->prn==prn)
        {
            if(current==president)
            {
                //Deleting the president,update the next president
                president=president->next;
            }
            else
            {
                //Delete the current member
                prev->next=current->next;
            }
        delete current;
        cout<<endl<<"Member with PRN:"<<prn<<" deleted."<<endl;
        return;
        }
        prev=current;
        current=current->next;
    }
    cout<<"Member with PRN"<<prn<<"not found."<<endl;
}
int getTotalMember()const
{
    int count=0;
    ClubMember*current=president;

    while(current)
    {
        count++;
        current=current->next;
    }
    return count;
}
void displayMembers()const{
    ClubMember*current=president;

    while(current)
    {
        cout<<"PRN:"<<current->prn<<",Name:"<<current->name<<endl;
        current=current->next;
    }
}
static ClubLinkedList concatenateLists(const ClubLinkedList &list1,const ClubLinkedList &list2)
{
    ClubLinkedList result=list1;

    if(result.secretary)
    {
        //If list1 is not empty,concatenate list2
        result.secretary->next=list2.president;
        result.secretary=list2.secretary;
    }
    else
    {
        //if list1 is empty,set list2 as result
        result=list2;
    }
    return result;
}
};
int main()
{
    ClubLinkedList division1,division2;

    division1.addMember("22171","RAM PAWAR");
    division1.addMember("22172","MOGLI KUMAR");

    division2.addMember("22173","YOGI PAWAR");
    division2.addMember("22174","TYAGI KUMAR");

    cout<<endl<<"Members of Division 1"<<endl;
    division1.displayMembers();

    cout<<endl<<"Members of Division 2"<<endl;
    division2.displayMembers();

    ClubLinkedList concatenatedList=ClubLinkedList::concatenateLists(division1,division2);

    cout<<endl<<"Concatenated Members:"<<endl;
    concatenatedList.displayMembers();

    division1.deleteMember("22171");

    cout<<"\nMembers of Division 1 after deletion:"<<endl;
    division1.displayMembers();
}