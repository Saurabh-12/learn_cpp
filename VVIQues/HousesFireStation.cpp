# include <iostream>


using namespace std;




int main () {

    int house[] = {6, 4, 2, 1,5,3};

    int fire[] = {2} ;

    int fireStation[] = {1, 3, 5};


    // fire station have only one value 
      int fires = fire[0];
      // find the minimum range of fire station to serve all the houses
      int min = 0;
      int housesSize = sizeof(house)/sizeof(house[0])-1;

      for (int i = 0; i <= housesSize; i++)
      {
         int temp = abs(house[i] - fires);
         if (min <temp)
             min = temp;
      }
      cout << "Minimum range is " << min << endl;

      // find the minimum range of fire station to serve all the houses, 
      //if fire station have more than one value

      int max = 1;
      int fireSize = sizeof(fireStation)/sizeof(fireStation[0])-1;

      for (int i = 0; i <=housesSize; i++) {

        for (int j = 0; j <= fireSize; j++) {

            //int temp = abs(house[i] - fireStation[j]);
            fireStation[j] = house[i]+ j;
            if (max < j)
                max = j;
        }
      }
      cout << "Maximum range is " << max << endl;


      cout << "abs difference of 3-5 is " << abs(3-5) << endl;
    


    return 0;
}