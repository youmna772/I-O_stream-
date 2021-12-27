#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>

using namespace std ; 

int main()
{
ifstream in_file ; 
in_file.open("exam_answers.txt") ;
if (!in_file) {
    
 cerr<<"Problem opening file" << endl ;
// return 1 ;
    }
 int count=2 ;    
string line ; 
vector <string> names  ;  
vector<int> correctasnswers ; 
int correct_answer ;
string right_answer = "ABCDE"  ;
float total = 0 ;    
while (getline(in_file,line))  {
    if (count %2 == 0 ) {names.push_back(line) ;
         correct_answer=0 ;
        }

    else { for (int i=0 ; i<5 ; i++ )
    { if (line [i] ==right_answer [i])
        correct_answer ++ ;
        
    }
    total += correct_answer ;
    correctasnswers.push_back(correct_answer) ;
            }
        count ++ ;
    }
 cerr << setw(10) ; 
cerr << "student" ;
 cerr << setw(10) ; 
cerr << "score" << endl ;
cerr << "--------------------------" << endl ;

for (size_t i=0 ; i<names.size() ; i++ )
{     cout << setw(10) ;
    cout<<names[i] ;
     cout << setw(10) ;
    cout << correctasnswers [i] << endl ;
    
    }
  in_file.close() ;  
cerr << "--------------------------" << endl ;
cerr << "Averge score";
cerr << setw(10) ; 
float averge = (total)/names.size() ;
cerr << averge << endl ;
    return 0 ;
}
