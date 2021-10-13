#include "date.h"
#include "fichemodel.h"
#include "requete.h"
#include "requetefiche.h"

#include <iostream>

using namespace std;

int main()
{
    std::list<FicheModel> * l = new list<FicheModel>();

    RequeteFiche * r = new RequeteFiche(l);
    r->test();
    r->test();

    std::list<FicheModel> * results = r->getResults();
    cout << to_string(results->size()) << endl;

    return 0;
}
