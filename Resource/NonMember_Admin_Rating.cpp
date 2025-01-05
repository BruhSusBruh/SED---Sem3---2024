#include <iostream>
using namespace std;
#include <vector>

class NonMember{
    private:
        string name;
    public:
        NonMember(string name="Annonymous"):name(name){}

    void showInfo(){
        cout << name << "\n";
    }

    friend class Admin;
};

class Admin{
    private:
        vector<User> UserList;
    public:
        Admin(vector<User> UserList={}):UserList(UserList){}

        void checkUser(){
            User.viewProfile();
        }
};

void Rating(){
    float rating;
    cout << "What do you think of the other party's performance?\n";
    cin >> rating;
};