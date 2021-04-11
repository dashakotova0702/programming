/* Apple Tree */
#include <iostream>
#include <string>
using namespace std;

class DeciduousTree
{
protected:
bool leaves;   //presence of leaves
string month;   //month name
int mark;   //mark of month

//default constructor
DeciduousTree (string month = "april") : month(month)
{
        mark = 0;
        leaves = false;
}

//copy constructor
DeciduousTree (const DeciduousTree& deciduoustree) :
        leaves(deciduoustree.leaves),
        month(deciduoustree.month),
        mark(deciduoustree.mark)
{
}

//destructor
virtual ~DeciduousTree ()
{
}

//function of month check
void MonthCheck ();
};

void DeciduousTree::MonthCheck () {
        if (month == "january" || month == "february" || month == "march" || month == "april" || month == "october" || month == "november" || month == "december")
                mark = 0;
        if (month == "may" || month == "june" || month == "july" || month == "august" || month == "september")
                mark = 1;
        switch  (mark)
        {
        case 0:
        {
                leaves = false;
                break;
        }
        case 1:
        {
                leaves = true;
                break;
        }
        default: leaves = false;
        }
}

class AppleTree : public DeciduousTree
{
int age;              //age of tree (year)
int branches;             //number of branches (item)
double height;             //height of tree (meter)
string variety;             //tree variety

public:
// default constructor
AppleTree (int age = 0,
           int branches = 0,
           double height = 0.5,
           string variety = "Antonovka",
           string month = "april") :
        DeciduousTree(month),
        age(age),
        branches(branches),
        height(height),
        variety(variety)
{
}

//copy constructor
AppleTree(const AppleTree& appletree) :
        age(appletree.age),
        branches(appletree.branches),
        height(appletree.height),
        variety(appletree.variety)
{
        this->leaves = appletree.leaves;
        this->month = appletree.month;
        this->mark = appletree.mark;
}

//destructor
~AppleTree ()
{
}

//usefull function
void care (AppleTree& appletree);

//function of month check
void Month_check () {
        MonthCheck();
}

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
        if (appletree.leaves == false)
                stream << "The apple tree doesn't have leaves" << endl;
        else
                stream << "The apple tree has leaves" << endl;
        stream << "Current month is " << appletree.month << endl;
        stream << "The variety of the apple tree is " << appletree.variety << endl;
        stream << "The age of the apple tree = " << appletree.age << " (year)" << endl;
        stream << "The height of the apple tree = " << appletree.height << " (meter)" << endl;
        stream << "The number of branches of the apple tree = " << appletree.branches << " (meter)" << endl << endl;
        return stream;
}

int main ()
{
        AppleTree Antonovka;

        Antonovka.Month_check();
        cout << Antonovka;
        Antonovka.care(Antonovka);
        cout << Antonovka;

        AppleTree Granny (1, 100, 5.5, "Granny", "may");

        Granny.Month_check();
        cout << Granny;
        Granny.care(Granny);
        cout << Granny;

        return 0;
}

/*
        The apple tree doesn't have leaves
        Current month is april
        The variety of the apple tree is Antonovka
        The age of the apple tree = 0 (year)
        The height of the apple tree = 0.5 (meter)
        The number of branches of the apple tree = 0 (meter)

        The apple tree doesn't have leaves
        Current month is april
        The variety of the apple tree is Antonovka
        The age of the apple tree = 0 (year)
        The height of the apple tree = 0.5 (meter)
        The number of branches of the apple tree = 0 (meter)

        The apple tree has leaves
        Current month is may
        The variety of the apple tree is Granny
        The age of the apple tree = 1 (year)
        The height of the apple tree = 5.5 (meter)
        The number of branches of the apple tree = 100 (meter)

        The apple tree has leaves
        Current month is may
        The variety of the apple tree is Granny
        The age of the apple tree = 1 (year)
        The height of the apple tree = 5.5 (meter)
        The number of branches of the apple tree = 70 (meter)


        Для продолжения нажмите любую клавишу . . .
 */
