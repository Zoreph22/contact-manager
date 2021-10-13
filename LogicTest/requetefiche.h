#ifndef REQUETEFICHE_H
#define REQUETEFICHE_H

#include <list>
#include "requete.h"
#include "fichemodel.h"

using namespace std;

class RequeteFiche : public Requete<FicheModel>
{
public:
    RequeteFiche(list<FicheModel> * fiches);
};

#endif // REQUETEFICHE_H
