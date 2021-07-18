#include <bits/stdc++.h>
using namespace std;

void SocialMedia::userClear()
{
    for (int i = 0; i < v; ++i)
    {
        delete graph[i];
    }
    graph.clear();
}

void SocialMedia::addUsers()
{
    long long int i;
    int j, src, des;

    string line;
    int numlines = 0;
    ifstream reader("users.txt");
    if (!reader)
    {
        cout << "There was an error opening file" << endl;
        exit(0);
    }
    while (!reader.eof())
    {
        getline(reader, line);
        numlines++;
    }
    reader.close();
    v = numlines;

    User *start;
    int re;
    ifstream fin("users.txt");
    for (i = 0; i < v; i++)
    {
        start = new User;
        fin >> start->username;
        fin >> start->no_of_posts;
        fin >> start->dob.date >> start->dob.month >> start->dob.year;
        fin >> start->institution;
        fin >> start->city;
        start->index = i;
        graph.push_back(start);
        start->next = NULL;
    }
    fin.close();

    numlines = 0;
    ifstream reader2("connections.txt");
    if (!reader2)
    {
        cout << "There was an error opening file" << endl;
        exit(0);
    }
    while (!reader2.eof())
    {
        getline(reader2, line);
        numlines++;
    }
    reader2.close();
    e = numlines;

    src = 1;
    fin.open("connections.txt");
    while (src <= e)
    {
        fin >> des;
        if (des == -1)
        {
            src++;
            continue;
        }
        re = insert(src - 1, des - 1);
        re = insert(des - 1, src - 1);
    }
    fin.close();
}

void SocialMedia::display()
{
    User *p;
    int i, j, flag;
    cout << "USERS   \tNo of posts   \tFriends   \tDate of birth";
    for (i = 0; i < v; i++)
    {
        p = graph[i]->next;
        cout << "\n"
             << graph[i]->username;
        flag = 0;
        for (; p != NULL; p = p->next)
        {
            flag++;
        }
        cout << "\t\t" << graph[i]->no_of_posts << "\t\t" << flag << "\t\t" << graph[i]->dob.date << "/" << graph[i]->dob.month << "/" << graph[i]->dob.year;
    }
}

int SocialMedia::insert(int src, int des)
{
    User *start, *p;
    int i, flag = 0;
    start = new User;

    start->username = graph[des]->username;
    start->dob = graph[des]->dob;
    start->no_of_posts = graph[des]->no_of_posts;
    start->institution = graph[des]->institution;
    start->city = graph[des]->city;
    start->index = graph[des]->index;
    start->next = NULL;
    if (graph[src]->next == NULL)
    {
        graph[src]->next = start;
    }
    else
    {
        p = graph[src]->next;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = start;
    }
    return 0;
}

//function for maximum number of friends
void SocialMedia::maxfriends() //change to display ALL users with max friends, now displays only one
{
    int max = -1, flag, i;
    string k;
    User *p;
    for (i = 0; i < v; i++)
    {
        p = graph[i]->next;
        flag = 0;
        for (; p != NULL; p = p->next)
            flag = flag + 1;

        if (max < flag)
        {
            max = flag;
            k = graph[i]->username;
        }
    }

    int temp = 0;
    cout << "The following users have maximum friends = " << max << " " << endl;
    for (i = 0; i < v; i++)
    {
        p = graph[i]->next;
        temp = 0;
        for (; p != NULL; p = p->next)
            temp = temp + 1;

        if (max == temp)
        {
            cout << graph[i]->username << endl;
        }
    }
}

void SocialMedia::minfriends()
{
    int min = INT_MAX, flag, i;
    string k;
    User *p;
    for (i = 0; i < v; i++)
    {
        p = graph[i]->next;
        flag = 0;
        for (; p != NULL; p = p->next)
            flag = flag + 1;

        if (min > flag)
        {
            min = flag;
            k = graph[i]->username;
        }
    }

    int temp = 0;
    cout << "The following users have minimum friends = " << min << " " << endl;
    for (i = 0; i < v; i++)
    {
        p = graph[i]->next;
        temp = 0;
        for (; p != NULL; p = p->next)
            temp = temp + 1;

        if (min == temp)
        {
            cout << graph[i]->username << endl;
        }
    }
}

void SocialMedia::maxminposts()
{
    int i, max, min;
    string m, n;
    max = graph[0]->no_of_posts;
    m = graph[0]->username;
    min = graph[0]->no_of_posts;
    n = graph[0]->username;
    for (i = 0; i < v; i++)
    {
        if (max < graph[i]->no_of_posts)
        {
            max = graph[i]->no_of_posts;
            m = graph[i]->username;
        }

        if (min > graph[i]->no_of_posts)
        {
            min = graph[i]->no_of_posts;
            n = graph[i]->username;
        }
    }

    //max posts
    cout << "The following users have maximum number of posts = " << max << " " << endl;
    for (int i = 0; i < v; i++)
    {
        if (graph[i]->no_of_posts == max)
        {
            cout << graph[i]->username << endl;
        }
    }
    cout << endl;
    //min posts
    cout << "The following users have minimum number of posts = " << min << " " << endl;
    for (int i = 0; i < v; i++)
    {
        if (graph[i]->no_of_posts == min)
        {
            cout << graph[i]->username << endl;
        }
    }
}

void SocialMedia::birth(int mon)
{
    int i, flag = 0;

    for (i = 0; i < v; i++)
    {
        if (mon == graph[i]->dob.month)
        {
            cout << "User " << graph[i]->username << " having birthday on date:" << graph[i]->dob.date << endl;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\nNone of friends having birthday on " << mon << " month" << endl;
}

//function for finding users from same institution
void SocialMedia::same_institute(string insName)
{
    int i, flag = 0;
    for (int i = 0; i < v; i++)
    {
        if (insName.compare(graph[i]->institution) == 0)
        { //if institution names are equal
            cout << "User " << graph[i]->username << " also belongs to institution " << graph[i]->institution << endl;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "\n Nobody else belongs to this institution" << endl;
    }
}

//function for finding users from same city
void SocialMedia::same_city(string cname)
{
    int flag = 0;
    for (int i = 0; i < v; i++)
    {
        if (cname.compare(graph[i]->city) == 0)
        {
            cout << "User " << graph[i]->username << " also belongs to city " << graph[i]->city << endl;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "\n Nobody else belongs to this city" << endl;
    }
}

//helper function for friend groups
void SocialMedia::friend_groups_helper(int i, bool visited[])
{
    visited[i] = true;
    cout << graph[i]->username << "  ";

    User *p = graph[i]->next;
    while (p)
    {
        if (!visited[p->index])
        {
            friend_groups_helper(p->index, visited);
        }
        p = p->next;
    }
}
//function to find the total number of friend groups
void SocialMedia::friend_groups()
{
    bool *visited = new bool[v];
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == 0)
        {
            cout<<"Group "<<count+1<<": ";
            friend_groups_helper(i, visited);
            count += 1;
            cout << endl;
        }
    }
    delete[] visited;
}

vector<User *> SocialMedia::bfs(string key)
{
    queue<User *> q;
    vector<bool> visited(v, false);
    int nextIndex = 0;
    vector<User *> result;

    while (nextIndex != -1)
    {
        q.push(graph[nextIndex]);
        visited[nextIndex] = true;
        while (!q.empty())
        {
            User *record = q.front();
            q.pop();
            if (record->username.find(key) != string::npos || record->institution.find(key) != string::npos)
                result.push_back(record);
            User *p = record->next;
            while (p)
            {
                if (!visited[p->index])
                {
                    visited[p->index] = true;
                    q.push(p);
                }
                p = p->next;
            }
        }
        nextIndex = -1;
        for (int i = 0; i < v; ++i)
        {
            if (!visited[i])
            {
                nextIndex = i;
                break;
            }
        }
    }
    return result;
}
void SocialMedia::search()
{
    long long id;
    string key;

    cout << "Active user ID: ";
    cin >> id;

    cout << "Search Term: ";
    cin >> key;

    vector<User *> result = bfs(key);
    vector<int> level = dijkstra(id - 1);

    cout << "\nResults\n";
    for (auto it : result)
    {
        cout << it->username << "\t" << it->institution << "\t";
        if (level[it->index] > 0 && level[it->index] <= 3)
            cout << "Level " << level[it->index] << " connection";
        else if (level[it->index] > 0)
            cout << "Level 3+ connection";
        else
            cout << "Current User ";
        cout << endl;
    }
}

int SocialMedia::minDistance(vector<int> dist, bool visited[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
        if (visited[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

vector<int> SocialMedia::dijkstra(int src)
{
    vector<int> dist(v);
    bool visited[v];
    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX, visited[i] = false;
    dist[src] = 0;
    for (int count = 0; count < v - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        User *t = graph[u]->next;
        while (t)
        {
            int d = t->index;
            if (!visited[d] && dist[u] != INT_MAX && dist[u] + 1 < dist[d])
                dist[d] = dist[u] + 1;
            t = t->next;
        }
    }
    return dist;
}

void SocialMedia::writeToFile(User *newUser)
{
    ofstream fout("users.txt", ios::app);
    fout << "\n"
         << newUser->username << " " << newUser->no_of_posts << " " << newUser->dob.date << " " << newUser->dob.month << " " << newUser->dob.year << " " << newUser->institution << " " << newUser->city;
    fout.close();
    fout.open("connections.txt", ios::app);
    User *t = graph[newUser->index]->next;
    fout << "\n";
    while (t)
    {
        fout << t->index + 1 << " ";
        t = t->next;
    }
    fout << "-1 ";
    fout.close();
}

void SocialMedia::insertUser()
{
    User *start = new User;
    cout << "\nEnter Username : ";
    cin >> start->username;
    cout << "No of number of posts for user " << start->username << " : ";
    cin >> start->no_of_posts;
    cout << "Enter date of birth : ";
    cin >> start->dob.date >> start->dob.month >> start->dob.year;
    cout << "Enter the institution name : ";
    cin >> start->institution;
    cout << "Enter city name : ";
    cin >> start->city;
    start->index = v;
    v++;
    graph.push_back(start);

    int n, id;
    vector<int> friends;
    cout << "Enter number of friends for user " << start->username << " : ";
    cin >> n;
    cout << "Enter IDs of friends of user " << start->username << ": ";
    for (int i = 0; i < n; ++i)
    {
        cin >> id;
        friends.push_back(id - 1);
        insert(v - 1, id - 1);
        insert(id - 1, v - 1);
    }
    writeToFile(start);
}
