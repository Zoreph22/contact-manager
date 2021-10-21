#include "contactcollection.h"

#include <iostream>
#include <regex>

using namespace std;

int main()
{
//    ContactCollection i;

//    ContactModel m1(5);
//    m1.setNom("fabrice");
//    ContactModel m2(6);
//    ContactModel m3(1);

//    i.add(m1);
//    i.add(m2);

//    cout << "taille avant " << i.count() << endl;

//    i.remove(m3);

//    for (auto & it : i.getContacts()) {
//        cout << it.getId() << endl;
//    }

//    cout << "taille apres " << i.count() << endl;

    std::string text = "BonjouAZX les amis yeaAZX man";
    std::regex vowel_re("(AZX) ");

    // construct a string holding the results
    std::cout << '\n' << std::regex_replace(text, vowel_re, "_") << '\n';

    return 0;
}

