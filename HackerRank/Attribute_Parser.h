
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;



struct Tag
{
    int number;
    string name;
    string value;
    Tag(int number)
        : number(number) {}
};

struct Tags
{
    vector<Tag> set;
    void addTags(Tag tag) {
        if (is_unique(set, tag)) set.push_back(tag);
    }

};


bool is_unique(vector<Tag> set, Tag tag)
{
    for (int i = 0; i != set.size(); i++) {
        if (tag.number == set[i].number)return false;
    }
    return true;
}

void get()
{
    char ch;
    cin >> ch;

    switch (ch)
    {
    case'<':

    default:
        break;
    }
}

void getTag(int n)
{
   

}

void runAttributeParser()
{
    int n, q;
    cin >> n >> q;

}


