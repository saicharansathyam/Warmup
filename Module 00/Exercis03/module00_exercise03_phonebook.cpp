
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string nickname;
};

bool isUnique(const vector<Contact>& phonebook,const string& phone){
    for(const auto& c:phonebook) if(c.phone==phone) return false;
    return true;
}

void addContact(vector<Contact>& phonebook){
    Contact c;
    cout<<"Enter name: ";
    getline(cin,c.name);
    if(c.name.empty()){ cout<<"Name cannot be empty!\n"; return;}
    cout<<"Enter phone: ";
    getline(cin,c.phone);
    if(c.phone.empty()){ cout<<"Phone cannot be empty!\n"; return;}
    if(!isUnique(phonebook,c.phone)){ cout<<"Phone already exists!\n"; return;}
    cout<<"Enter nickname: ";
    getline(cin,c.nickname);
    if(c.nickname.empty()){ cout<<"Nickname cannot be empty!\n"; return;}
    phonebook.push_back(c);
    cout<<"Contact added!\n";
}

void showContacts(const vector<Contact>& phonebook){
    if(phonebook.empty()){ cout<<"No contacts available.\n"; return;}
    for(size_t i=0;i<phonebook.size();++i){
        cout<<"\nContact "<<i<<":\n";
        cout<<"Name: "<<phonebook[i].name<<"\n";
        cout<<"Phone: "<<phonebook[i].phone<<"\n";
        cout<<"Nickname: "<<phonebook[i].nickname<<"\n";
    }
}

void removeContact(vector<Contact>& phonebook,int& bookmark){
    if(phonebook.empty()){ cout<<"No contacts to remove.\n"; return;}
    showContacts(phonebook);
    cout<<"Enter contact index or phone number to remove: ";
    string input; getline(cin,input);
    if(input.empty()){ cout<<"Input empty!\n"; return;}
    bool num=all_of(input.begin(),input.end(),::isdigit);
    auto eraseAt=[&](size_t idx){
        cout<<"Removing: "<<phonebook[idx].name<<"\n";
        phonebook.erase(phonebook.begin()+idx);
        if(bookmark==static_cast<int>(idx)) bookmark=-1;
        else if(idx<static_cast<size_t>(bookmark)) --bookmark;
    };
    if(num){
        try{
            size_t idx=stoul(input);
            if(idx<phonebook.size()){ eraseAt(idx); return;}
        }catch(...){}
    }
    for(size_t i=0;i<phonebook.size();++i){
        if(phonebook[i].phone==input){ eraseAt(i); return;}
    }
    cout<<"No contact found.\n";
}

void bookmarkContact(const vector<Contact>& phonebook,int& bookmark){
    if(phonebook.empty()){ cout<<"No contacts to bookmark.\n"; return;}
    cout<<"Enter contact index or phone number to bookmark: ";
    string input; getline(cin,input);
    if(input.empty()){ cout<<"Input empty!\n"; return;}
    bool num=all_of(input.begin(),input.end(),::isdigit);
    if(num){
        try{
            size_t idx=stoul(input);
            if(idx<phonebook.size()){ bookmark=static_cast<int>(idx); cout<<"Bookmarked "<<phonebook[idx].name<<"\n"; return;}
        }catch(...){}
    }
    for(size_t i=0;i<phonebook.size();++i){
        if(phonebook[i].phone==input){ bookmark=i; cout<<"Bookmarked "<<phonebook[i].name<<"\n"; return;}
    }
    cout<<"No contact found.\n";
}

void showBookmark(const vector<Contact>& phonebook,int bookmark){
    if(bookmark==-1){ cout<<"No contact bookmarked.\n"; return;}
    if(bookmark>=static_cast<int>(phonebook.size())){ cout<<"Bookmark invalid.\n"; return;}
    const auto& c=phonebook[bookmark];
    cout<<"\nBookmarked Contact:\nName: "<<c.name<<"\nPhone: "<<c.phone<<"\nNickname: "<<c.nickname<<"\n";
}

int main(){
    vector<Contact> phonebook;
    int bookmark=-1;
    string cmd;
    cout<<"Welcome to Phonebook!\n";
    while(true){
        cout<<"\nCommands: ADD, SHOW, REMOVE, BOOKMARK, SHOWBOOKMARK, EXIT\nEnter command: ";
        if(!getline(cin,cmd)){ cout<<"End of input. Exiting.\n"; break; }
        if(cmd.empty()) continue; // ignore blank lines
        for(char& ch:cmd) ch=toupper(ch);
        if(cmd=="ADD") addContact(phonebook);
        else if(cmd=="SHOW") showContacts(phonebook);
        else if(cmd=="REMOVE") removeContact(phonebook,bookmark);
        else if(cmd=="BOOKMARK") bookmarkContact(phonebook,bookmark);
        else if(cmd=="SHOWBOOKMARK") showBookmark(phonebook,bookmark);
        else if(cmd=="EXIT"){ cout<<"Goodbye!\n"; break;}
        else cout<<"Unknown command. Try again.\n";
    }
    return 0;
}
