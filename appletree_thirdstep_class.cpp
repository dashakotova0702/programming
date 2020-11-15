/* Apple Tree */
#include <iostream>
#include <fstream>
using namespace std;

class AppleTree
{
int age;           //age of tree (year)
int branches;      //number pf branches (item)
double height;     //height of tree (meter)
string variety;     //tree variety
ifstream stream;   //input file stream

public:
// default constructor
AppleTree (const char* file = "Antonovka.txt")
{
        stream.open (file);
        if (stream.is_open())
        {
                //data member initialization
                stream >> age;
                stream >> branches;
                stream >> height;
                stream >> variety;
        }
        else
        {
                //data member default initialization;
                age = 0;
                branches = 0;
                height = 0.5;
                variety = "Antonovka";
        }
}

//copy constructor
AppleTree(const AppleTree& appletree) :
        age(appletree.age),
        branches(appletree.branches),
        height(appletree.height),
        variety(appletree.variety)
{
}

//destructor
~AppleTree()
{
        if (stream.is_open())
                stream.close();
}

//usefull function
void care (AppleTree& appletree);

//friend operator function
friend ostream& operator<< (ostream&, AppleTree);
};

void AppleTree::care (AppleTree& appletree)
{
        if (appletree.branches >= 100)
                appletree.branches = 70;
}

ostream& operator<< (ostream& stream, AppleTree appletree)
{
        stream << "The variety of the apple tree is " << appletree.variety << endl;
        stream << "The age of the apple tree = " << appletree.age << " (year)" << endl;
        stream << "The height of the apple tree = " << appletree.height << " (meter)" << endl;
        stream << "The number of branches of the apple tree = " << appletree.branches << " (meter)" << endl << endl;
        return stream;
}

int main ()
{
        AppleTree Antonovka;

        cout << Antonovka;
        Antonovka.care(Antonovka);
        cout << Antonovka;

        AppleTree Granny ("Granny.txt");
        cout << Granny;
        Granny.care(Granny);
        cout << Granny;

        return 0;
}

/*
        The variety of the apple tree is Antonovka
        The age of the apple tree = 0 (year)
        The height of the apple tree = 0.5 (meter)
        The number of branches of the apple tree = 0 (meter)

        The variety of the apple tree is Antonovka
        The age of the apple tree = 0 (year)
        The height of the apple tree = 0.5 (meter)
        The number of branches of the apple tree = 0 (meter)

        The variety of the apple tree is Granny
        The age of the apple tree = 1 (year)
        The height of the apple tree = 5.5 (meter)
        The number of branches of the apple tree = 100 (meter)

        The variety of the apple tree is Granny
        The age of the apple tree = 1 (year)
        The height of the apple tree = 5.5 (meter)
        The number of branches of the apple tree = 70 (meter)


        Для продолжения нажмите любую клавишу . . .
 */
