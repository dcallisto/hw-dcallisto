#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here
string* readNames(istream& instream, int&numNames)
{
  

  instream>>numNames;
  
  string *names = new string[numNames];
  

  for (int i = 0; i<numNames; i++)
  {
    instream>>names[i];
    
  }

  return names;
  
}

bool distributeTeams(string* names, int numNames, string* team1in, string* team2in, int teamSize, int teamCount, int oneCount, int twoCount)
{
    
 if (teamCount < numNames)
    {
        //cout<<"teamcount: "<<teamCount<<endl;
    string cname = names[teamCount];
    if (oneCount < teamSize)
    {
      team1in[oneCount] = cname; 
       // cout<<"team1: "<<team1in[0]<<", "<<team1in[1]<<endl;
      distributeTeams(names, numNames, team1in, team2in, teamSize, teamCount+1, oneCount+1, twoCount);


    }
    if (twoCount < teamSize)
    {

      team2in[twoCount] = cname; 
      //cout<<"team2: "<<team2in[0]<<", "<<team2in[1]<<endl;

      distributeTeams(names, numNames,team1in, team2in, teamSize, teamCount+1, oneCount, twoCount+1);

      
    }
  }
  else
  {
    printSolution(team1in, team2in, teamSize);
  }


     
    

 

  return true;
    
}



int main(int argc, char* argv[])
{

  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }
  ifstream ifile(argv[1]);
  if(ifile.fail()){
    cerr << "Unable to open input file" << endl;
    return 1;
  }
  // Complete the rest of main
  int numNames=0;
  string* myNames;
  myNames = readNames(ifile,numNames);
  
  
  int myTeamSize = numNames/2;
  int myCount = 0;

  string* myTeam1 = new string[myTeamSize];
  string* myTeam2 = new string[myTeamSize];
  int mync = 0;
  int t1c = 0;
  int t2c = 0;
  distributeTeams(myNames, numNames, myTeam1, myTeam2, myTeamSize, mync, t1c, t2c);



  delete [] myNames;

  delete [] myTeam1;
  delete [] myTeam2;

  return 0;
}
