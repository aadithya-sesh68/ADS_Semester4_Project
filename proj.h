#include <bits/stdc++.h>
using namespace std;
class Date
{
public:
    int date;
    int month;
    int year;
};
class User
{
public:
    string username;
    long long index;
    int no_of_friends;
    int no_of_posts;
    string institution, city;
    Date dob;
    User *next;
};
class SocialMedia
{
    int v, e;
    vector<User *> graph;

public:
    void userClear();
    void addUsers();
    void display();
    int insert(int src, int des);
    void maxfriends() ;
    void minfriends();
    void maxminposts();
    void birth(int mon);
    void same_institute(string insName);
    void same_city(string cname);
    void friend_groups_helper(int i, bool visited[]);
    void friend_groups();
    vector<User *> bfs(string key);
    void search();
    int minDistance(vector<int> dist, bool visited[]);
    vector<int> dijkstra(int src);
    void writeToFile(User *newUser);
    void insertUser();
};
