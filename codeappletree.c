/* AppleTree */

#include <cstdio>
#include <cstring>

struct AppleTree
{
	int age;        //age of tree (year)
  int branches;   //number pf branches (item)
	double height;  //height os tree (meter)
	char* variety;  //tree variety
	int mark; 	    //active component mark
	union
	{
		bool watering;    //the tree is watered (true)
			                //or not (false), mark = 0
		int trimbranches; //number of trim branches (item), mark = 1
		bool fertilizer;  //the tree is fertilized (true)
			                //or not (false), mark = 2
	};
};

//inizialization of the apple tree
void init (AppleTree* appletree,
	  int age = 0,
    int branches = 0,
	  double height = 0.5,
    char* variety = "",
  	int mark = 0)
{
	appletree->age = age;
  appletree->branches = branches;
	appletree->height = height;
  appletree->variety = variety;
	appletree->mark = mark;
	switch (mark)
	{
		case 0:
			appletree->watering = true;
			break;
		case 1:
			appletree->trimbranches = 0;
			break;
		case 2:
			appletree->fertilizer = true;
			break;
		default:
			appletree->mark = 0;
			appletree->watering = true;
			break;
	}
}

//visualization of the apple tree
void view (AppleTree* appletree)
{
  printf("The variety of the apple tree is ");
  for (int i = 0; i < strlen(appletree->variety); i++)
  {
    printf("%c", appletree->variety[i]);
  }
	printf("The age of the apple tree = %d (year) \n", appletree->age);
	printf("The height of the apple tree = %lf (meter) \n", appletree->height);
  printf("The number of branches of the apple tree = %d (meter) \n", appletree->branches);
	switch (appletree->mark)
	{
		case 0:
			if (appletree->watering)
				printf("The apple tree is watering \n");
			else
				printf("The apple tree is not watering \n");
			break;
		case 1:
			printf("The number of trim branches of the apple tree = %d (item) \n", appletree->trimbranches);
			break;
		case 2:
			if (appletree->fertilizer)
				printf("The apple tree is fertilizer \n");
			else
				printf("The apple tree is not fertilizer \n");
			break;
	}
}

//caring of the apple tree
void care (AppleTree* appletree)
{
  switch (appletree->mark)
  {
    case 0:
      if (!appletree->watering)
        appletree->watering = true;
      break;
    case 1:
      appletree->trimbranches = appletree->branches;
      break;
    case 2:
      if (!appletree->fertilizer)
        appletree->fertilizer = true;
      break;
  }
}

int main()
{
  AppleTree Antonovka, Granny;

  init(&Antonovka, 0, 20, 1.0, "Antonovka", 0);
  init(&Antonovka, 0, 20, 1.0, "Antonovka", 2);
  view(&Antonovka);
  care(&Antonovka);
  init(&Antonovka, 1, 100, 3.0, "Antonovka", 1);

  init(&Granny, 0, 5, 0.5, "Granny", 0);
  init(&Granny, 0, 5, 0.5, "Granny", 2);
  view(&Granny);
  care(&Granny);
  init(&Granny, 1, 50, 1.0, "Granny", 1);

  return 0;
}
