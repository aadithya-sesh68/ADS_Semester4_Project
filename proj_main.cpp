#include "proj.h"
#include "proj_methods.cpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e, ch, s, i, mon;
    User *graph;
    string insName, cityname;
    SocialMedia obj;
    obj.addUsers();
    do
    {
        cout << "\n\nMain Menu\n\n1.  Add User\n2.  Display\n3.  Find maximum no. of friends\n4.  Find max and min no. of no_of_posts\n5.  Friends having birthday in given month\n6.  Users from the same institution\n7.  Users from the same city\n8.  Users with minimum number of friends\n9.  Friend Groups\n10. Search for a user\n0.  Exit\n\nEnter your choice : ";
        cin >> ch;
        cout<<endl;
        switch (ch)
        {
        case 1:
            cout << "Enter user details\n";
            obj.insertUser();
            cout << "\nUser added successfully\n";
            break;

        case 2:
            obj.display();
            break;

        case 3:
            obj.maxfriends();
            break;

        case 4:
            obj.maxminposts();
            break;
        case 5:
            cout << "Enter month number : ";
            cin >> mon;
            obj.birth(mon);
            break;
        case 6:
            cout << "Enter institution name ";
            cin >> insName; //accepts only one word
            obj.same_institute(insName);
            break;
        case 7:
            cout << "Enter city : ";
            cin >> cityname;
            obj.same_city(cityname);
            break;
        case 8:
            obj.minfriends();
            break;
        case 9:
            obj.friend_groups();
            break;
        case 10:
            obj.search();
            break;
        }
    } while (ch != 0);
    return 0;
}