#include "contactcollection.h"

#include <assert.h>
#include <iostream>
#include <regex>

#define ASSERT_EXCEPTION(f, p, e)           \
    {                                       \
        try                                 \
        {                                   \
            f(p);                           \
            assert(!#f #p #e "not thrown"); \
        }                                   \
        catch (e & e)                       \
        {                                   \
        }                                   \
        catch (exception & e)               \
        {                                   \
            assert(!#f #p #e "not thrown"); \
        }                                   \
    }

using namespace std;

void dateUnitTests()
{
    cout << "== DEBUT - Test Classe Date ==" << endl;
    Date dNull;
    Date dCustom1(22, 7, 2000);
    Date dCustom2;
    dCustom2.fromDate(22, 7, 2000);
    Date dCopytor(dCustom2);
    Date dCopy;
    dCopy = dCustom2;
    Date dNow;
    dNow.setNow();

    struct tm tmNow;
    time_t nNow = time(0);
    tmNow = *localtime(&nNow);

    assert(dNull.isNull());
    assert(!dCustom1.isNull());

    assert(dNull.getJour() == 0 && dNull.getMois() == 0 && dNull.getAnnee() == 0);
    assert(dNow.getJour() == (unsigned int)tmNow.tm_mday && dNow.getMois() == (unsigned int)tmNow.tm_mon + 1 && dNow.getAnnee() == (unsigned int)tmNow.tm_year + 1900);

    assert(dNull.toString() == "");
    assert(dCustom1.toString() == "22/7/2000");

    assert(dCustom1 == dCustom2);
    assert(dCustom1 != dNow);
    assert(dCustom1 < dNow);
    assert(dNow > dCustom1);
    assert(dCustom1 <= dCustom2);
    assert(dCustom2 >= dCustom1);
    assert(dCustom1 <= dNow);
    assert(dNow >= dCustom1);

    assert(dCopytor == dCustom2);
    assert(dCopy == dCustom2);

    dCustom2.setDate(tmNow);
    assert(dCustom2 == dNow);

    dCustom2.setNull();
    assert(dCustom2.isNull());

    Date dCustom3;
    dCustom3.fromString("22-7-2000");
    assert(dCustom3 == dCustom1);
    dCustom3.fromString("22/07/2000");
    assert(dCustom3 == dCustom1);
    ASSERT_EXCEPTION(dCustom3.fromString, "22-07-00", invalid_argument);
    ASSERT_EXCEPTION(dCustom3.fromString, "22-07", invalid_argument);

    cout << "Date du jour : " << dNow << endl;

    Date dInvalid;
    ASSERT_EXCEPTION(dInvalid.fromString, "01/01/3001", domain_error);
    ASSERT_EXCEPTION(dInvalid.fromString, "01/01/1969", domain_error);
    ASSERT_EXCEPTION(dInvalid.fromString, "00/01/1970", domain_error);
    ASSERT_EXCEPTION(dInvalid.fromString, "32/01/1970", domain_error);
    ASSERT_EXCEPTION(dInvalid.fromString, "01/00/1970", domain_error);
    ASSERT_EXCEPTION(dInvalid.fromString, "01/13/1970", domain_error);

    cout << "== FIN - Test Classe Date ==" << endl;
}

void interactionModelUnitTests()
{
    cout << "== DEBUT - Test Classe InteractionModel ==" << endl;

    InteractionModel m("Contenu");
    ASSERT_EXCEPTION(m.setContenu, "", invalid_argument);

    cout << "== FIN - Test Classe InteractionModel ==" << endl;
}

void contactModelUnitTests()
{
    cout << "== DEBUT - Test Classe ContactModel ==" << endl;

    ContactModel m;
    ASSERT_EXCEPTION(m.setDateModification, Date(1, 1, 1970), invalid_argument); // dateModification < dateCreation
    m.setDateModification(Date(2, 1, 2500));
    ASSERT_EXCEPTION(m.setDateModification, Date(1, 1, 2500), invalid_argument); // dateModificationNew < dateModificationOld

    ASSERT_EXCEPTION(m.setEmail, ".user@example.org", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "user.@example.org", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "us..er@example.org", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "Abc.example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "A@b@c@example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "a\"b(c)d,e:f;g<h>i[j\\k]l@example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "just\\\"not\\\"right@example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "this is\\\"not\\allowed@example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "this\\ still\\\"not\\\\allowed@example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "1234567890123456789012345678901234567890123456789012345678901234+x@example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "i_like_underscore@but_its_not_allowed_in_this_part.example.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "QA[icon]CHOCOLATE[icon]@test.com", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "\\\" \\\"@example.org", invalid_argument);
    ASSERT_EXCEPTION(m.setEmail, "\\\"john..doe\\\"@example.org", invalid_argument);

    m.setEmail("simple@example.com");
    m.setEmail("very.common@example.com");
    m.setEmail("disposable.style.email.with+symbol@example.com");
    m.setEmail("other.email-with-hyphen@example.com");
    m.setEmail("fully-qualified-domain@example.com");
    m.setEmail("user.name+tag+sorting@example.com");
    m.setEmail("x@example.com");
    m.setEmail("example-indeed@strange-example.com");
    m.setEmail("test/test@test.com");
    m.setEmail("admin@mailserver1");
    m.setEmail("example@s.example");
    m.setEmail("mailhost!username@example.org");
    m.setEmail("user%example.com@example.org");

    cout << "== FIN - Test Classe ContactModel ==" << endl;
}

void todoModelUnitTests()
{
    cout << "== DEBUT - Test Classe TodoModel ==" << endl;

    TodoModel t("Resume");
    ASSERT_EXCEPTION(t.setResume, "", invalid_argument);

    cout << "== FIN - Test Classe TodoModel ==" << endl;
}

int main()
{
//    dateUnitTests();
//    interactionModelUnitTests();
//    contactModelUnitTests();
//    todoModelUnitTests();

//    string s = "Mon interaction\n\n"
//            "@todo Format date 1 @date 01/10/2021\n"
//            "@todo Format date 2 @date 1-10-2021\n"
//            "Un autre commentaire\n"
//            "Encore un autre commentaire @todo Sans date\n\n"
//            " @todo Syntaxe@date 22/07/2000Un dernier commentaire ";

//    InteractionModel inte(s);
//    inte.parseTodos();

//    for (auto & i : inte.getTodos().getTodos()) {
//        cout << i.getResume() << " " << i.getDateTodo() << endl;
//    }

    return 0;
}
