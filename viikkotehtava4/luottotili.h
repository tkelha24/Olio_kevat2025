#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "Pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(string omistaja, double luottoRaja);

    bool deposit(double summa) override;
    bool withdraw(double summa) override;

    double getLuottoRaja();
};

#endif // LUOTTOTILI_H
