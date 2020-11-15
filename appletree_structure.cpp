/* AppleTree */

#include <cstdio>
#include <cstring>

struct AppleTree
{
        int age;  //age of tree (year)
        int branches; //number pf branches (item)
        double height; //height os tree (meter)
        char* variety; //tree variety
};

//inizialization of the apple tree
void init (AppleTree* appletree,
           int age = 0,
           int branches = 0,
           double height = 0.5,
           char* variety = "Antonovka")
{
        appletree->age = age;
        appletree->branches = branches;
        appletree->height = height;
        appletree->variety = variety;
}

//visualization of the apple tree
void view (AppleTree* appletree)
{
        printf("The variety of the apple tree is ");
        for (int i = 0; i < strlen(appletree->variety); i++)
        {
                printf("%c", appletree->variety[i]);
        }
        printf("\nThe age of the apple tree = %d (year) \n", appletree->age);
        printf("The height of the apple tree = %lf (meter) \n", appletree->height);
        printf("The number of branches of the apple tree = %d (meter) \n\n", appletree->branches);
}

//caring of the apple tree
void care (AppleTree* appletree)
{
        if (appletree->branches >= 100)
                appletree->branches = 70;
}

int main()
{
        AppleTree Antonovka, Granny;

        init(&Antonovka);
        view(&Antonovka);
        care(&Antonovka);
        view(&Antonovka);

        init(&Granny, 1, 100, 5.5, "Granny");
        view(&Granny);
        care(&Granny);
        view(&Granny);

        return 0;
}

/*
   The variety of the apple tree is Antonovka
   The age of the apple tree = 0 (year)
   The height of the apple tree = 0.500000 (meter)
   The number of branches of the apple tree = 0 (meter)

   The variety of the apple tree is Antonovka
   The age of the apple tree = 0 (year)
   The height of the apple tree = 0.500000 (meter)
   The number of branches of the apple tree = 0 (meter)

   The variety of the apple tree is Granny
   The age of the apple tree = 1 (year)
   The height of the apple tree = 5.500000 (meter)
   The number of branches of the apple tree = 100 (meter)

   The variety of the apple tree is Granny
   The age of the apple tree = 1 (year)
   The height of the apple tree = 5.500000 (meter)
   The number of branches of the apple tree = 70 (meter)


   Для продолжения нажмите любую клавишу . . .
 */
