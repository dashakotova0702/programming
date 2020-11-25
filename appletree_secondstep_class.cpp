/* Apple Tree */
#include <iostream>
#include <string>
using namespace std;

class AppleTree
{
int age;   //age of tree (year)
int branches; //number of branches (item)
double height;   //height of tree (meter)
int count_of_variety;
string* variety;   //tree variety

public:
// default constructor
AppleTree (int age = 0,
           int branches = 0,
           double height = 0.5,
           int count_of_variety = 2,
           string variety1 = "Antonovka",
           string variety2 = "Golden") :
        age(age),
        branches(branches),
        height(height),
        count_of_variety(count_of_variety)
{
        variety = new string[count_of_variety];
        switch (count_of_variety)
        {
        case 1:
        {
                variety[0] = variety1;
                break;
        }
        case 2:
        {
                variety[0] = variety1;
                variety[1] = variety2;
                break;
        }

        }
}

//copy constructor
AppleTree(const AppleTree& appletree) :
        age(appletree.age),
        branches(appletree.branches),
        height(appletree.height),
        count_of_variety(appletree.count_of_variety)
{
        variety = new string[appletree.count_of_variety];
        switch (appletree.count_of_variety)
        {
        case 1:
        {
                variety[0] = appletree.variety[0];
                break;
        }
        case 2:
        {
                variety[0] = appletree.variety[0];
                variety[1] = appletree.variety[1];
                break;
        }

        }
}

//destructor
~AppleTree()
{
        delete [] variety;
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
        switch (appletree.count_of_variety)
        {
        case 1:
        {
                stream << "The variety of the apple tree is " << appletree.variety[0] << endl;
                break;
        }
        case 2:
        {
                stream << "The variety of the apple tree is " << appletree.variety[0] << " and " << appletree.variety[1] << endl;
                break;
        }
        }
        stream << "The age of the apple tree = " << appletree.age << " (year)" << endl;
        stream << "The height of the apple tree = " << appletree.height << " (meter)" << endl;
        stream << "The number of branches of the apple tree = " << appletree.branches << " (meter)" << endl << endl;
        return stream;
}

int main ()
{
        AppleTree WinterVariety;

        cout << WinterVariety;
        WinterVariety.care(WinterVariety);
        cout << WinterVariety;

        AppleTree SummerVariety(1, 100, 5.5, 1, "Mantet");
        cout << SummerVariety;
        SummerVariety.care(SummerVariety);
        cout << SummerVariety;

        return 0;
}

/*
   The variety of the apple tree is Antonovka and Golden
   The age of the apple tree = 0 (year)
   The height of the apple tree = 0.5 (meter)
   The number of branches of the apple tree = 0 (meter)

   The variety of the apple tree is Antonovka and Golden
   The age of the apple tree = 0 (year)
   The height of the apple tree = 0.5 (meter)
   The number of branches of the apple tree = 0 (meter)

   The variety of the apple tree is Mantet
   The age of the apple tree = 1 (year)
   The height of the apple tree = 5.5 (meter)
   The number of branches of the apple tree = 100 (meter)

   The variety of the apple tree is Mantet
   The age of the apple tree = 1 (year)
   The height of the apple tree = 5.5 (meter)
   The number of branches of the apple tree = 70 (meter)


   Для продолжения нажмите любую клавишу . . .
 */
