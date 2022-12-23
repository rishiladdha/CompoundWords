#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <fstream>


using namespace std;


int main() {

    set <string> dict;
    //initialising container 'set', with each element of the set being a string.

    vector <string> compound;
    //initialising container 'vector' to store compound words.

    ifstream dictionary ("/Users/laddharishi/CLionProjects/CSQ1_Rishi/dictionary.txt");

    /*if (dictionary.is_open()){
        string input;
        while (getline(dictionary, input)){
            //read until there is nothing left to read
            dict.insert(input);
            //insert into set
        }

    }*/

    string s;
    getline(cin, s);
    while (!s.empty()){
        dict.insert(s);
        getline(cin, s);
    }

    /*
    Testing if the .txt file has been imported into the set 'dict'.
    set<string>::iterator itr;
    for (itr = dict.begin(); itr != dict.end(); ++itr){
        cout << (*itr) <<endl;
    }
    */

    int count = 0;
    set<string> ::iterator itr;
    for(itr = dict.begin(); itr != dict.end(); itr++) { //iterator to iterate over the set
        for (int j =1 ; j<(*itr).length(); j++) { //iterator to iterate over each word
            if (dict.count((*itr).substr(j)) != 0 and dict.count((*itr).substr(0,j)) != 0){
                /* Here, each word is divided into two substrings (character by character). If both these substrings
                 * are found in the set, then that word is added to the solution vector and the loop is broken.
                 * The loop is broken to ensure that the compound word is added to the vector only once (even if it is
                 * a combination of more than one pair of substrings that exist in the set.)
                 */
                //compound.push_back((*itr));
                //cout << (*itr) <<endl;
                count++;
                break;
            }
        }
    }

    cout<<count<<endl;


    return 0;
}
