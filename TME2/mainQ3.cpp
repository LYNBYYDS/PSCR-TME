#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include <utility>


int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("tmp/WarAndPeace.txt");

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	vector<pair<string, size_t>> mots;
	size_t isinlist;
	size_t motsz = 0;
	size_t nombre_lu = 0;
	//prochain mot lu
	string word;

	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);

		isinlist = 0;
		for(size_t i = 0; i < mots.size(); ++i){
			if(mots.at(i).first == word){
				isinlist = 1;
				mots.at(i).second++;
				break;
			}
		}
		if(isinlist == 0){
			mots.emplace_back(word, 1);
			motsz++;
		}
	}

	size_t war_found = 0;
	size_t peace_found = 0;
	size_t toto_found = 0;

	for(size_t i = 0; i < motsz; ++i){
		if(mots.at(i).first == "war"){
			cout << "Found a total of "<< mots.at(i).second << " word <war>" << endl;
			war_found++;
		}else if(mots.at(i).first == "peace"){
			cout << "Found a total of "<< mots.at(i).second << " word <peace>" << endl;
			peace_found++;
		}else if(mots.at(i).first == "toto"){
			cout << "Found a total of "<< mots.at(i).second << "word <toto>" << endl;
			toto_found++;
		}
	}
	if(war_found == 0){
		cout << "Didnt find word war" << endl;
	}
	if(peace_found == 0){
		cout << "Didnt find word peace" << endl;
	}
	if(toto_found == 0){
		cout << "Didnt find word toto" << endl;
	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << motsz << " words." << endl;

    return 0;
}


