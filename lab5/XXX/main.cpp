//
// Created by Student on 30.03.2017.
//

#include "XXX.h"

int main() {
    XXX old;
    XXX new_xxx{old};
    //teraz zarówno old jak i new_xxx pokazują na ten sam fragment pamięci
    //... niedobrze bo zaraz zostanie uruchominy destruktor pierwsego i drugiego obiektu
    //i drugi destruktor będzie chciał zwolnić drugi raz ten sam fragment pamięci...
}

