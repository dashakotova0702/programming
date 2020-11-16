/* Apple Tree */
#include <iostream>
using namespace std;

class AppleTree
{
int* age;   //age of tree (year)
int* branches; //number of branches (item)
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
        this->age = new int(age);
        this->branches = new int(branches);
}

//copy constructor
AppleTree(const AppleTree& appletree) :
        height(appletree.height),
        variety(appletree.variety)
{
        age = new int(*(appletree.age));
        branches = new int(*(appletree.branches));
}

//destructor
~AppleTree()
{
        delete age;
        delete branches;
}

//usefull function
void care (AppleTree& appletree);

//friend operator function
friend ostream& operator<< (ostream&, AppleTree);
};

void AppleTree::care (AppleTree& appletree)
{
        if (*(appletree.branches) >= 100)
                *(appletree.branches) = 70;
}

ostream& operator<< (ostream& stream, AppleTree appletree)
{
        stream << "The variety of the apple tree is " << appletree.variety << endl;
        stream << "The age of the apple tree = " << *(appletree.age) << " (year)" << endl;
        stream << "The height of the apple tree = " << appletree.height << " (meter)" << endl;
        stream << "The number of branches of the apple tree = " << *(appletree.branches) << " (meter)" << endl << endl;
        return stream;
}

int main ()
{
        AppleTree Antonovka;

        cout << Antonovka;
        Antonovka.care(Antonovka);
        cout << Antonovka;

        AppleTree Granny(1, 100, 5.5, "Granny");
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
