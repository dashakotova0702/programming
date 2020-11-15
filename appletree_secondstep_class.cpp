/* Apple Tree */
#include <iostream>
using namespace std;

class AppleTree
{
int* pointer;   //pointer on the first array element
//pointer[0] - age of tree (year)
//pointer[1] - number pf branches (item)
double height;   //height of tree (meter)
string variety;   //tree variety

public:
// default constructor
AppleTree (int age = 0,
           int branches = 0,
           double height = 0.5,
           string variety = "Antonovka") :
        height(height),
        variety(variety)
{
        pointer = new int[2];
        pointer[0] = age;
        pointer[1] = branches;
}

//copy constructor
AppleTree(const AppleTree& appletree) :
        height(appletree.height),
        variety(appletree.variety)
{
        pointer = new int[2];
        pointer[0] = appletree.pointer[0];
        pointer[1] = appletree.pointer[1];
}

//destructor
~AppleTree()
{
        delete[] pointer;
}

//usefull function
void care (AppleTree& appletree);

//friend operator function
friend ostream& operator<< (ostream&, AppleTree);
};

void AppleTree::care (AppleTree& appletree)
{
        if (appletree.pointer[1] >= 100)
                appletree.pointer[1] = 70;
}

ostream& operator<< (ostream& stream, AppleTree appletree)
{
        stream << "The variety of the apple tree is " << appletree.variety << endl;
        stream << "The age of the apple tree = " << appletree.pointer[0] << " (year)" << endl;
        stream << "The height of the apple tree = " << appletree.height << " (meter)" << endl;
        stream << "The number of branches of the apple tree = " << appletree.pointer[1] << " (meter)" << endl << endl;
        return stream;
}

int main ()
{
        AppleTree Antonovka;

        cout << Antonovka;
        Antonovka.care(Antonovka);
        cout << Antonovka;

        AppleTree Granny (1, 100, 5.5, "Granny");
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
